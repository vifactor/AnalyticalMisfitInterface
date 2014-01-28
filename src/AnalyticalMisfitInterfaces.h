/*
 * AnalyticalMisfitInterfaces.h
 *
 *  Created on: 23 jan 2014
 *      Author: kopp
 */

#ifndef ANALYTICAL_MISFIT_INTERFACES_H_
#define ANALYTICAL_MISFIT_INTERFACES_H_

#include <gsl/gsl_math.h>
#include <iostream>

class AnalyticalMisfitInterfaceBase
{
public:
	AnalyticalMisfitInterfaceBase(double rho, double bx, double by, double bz, double Qx, double Qy, double Qz, double nu,
		 double d);
	virtual ~AnalyticalMisfitInterfaceBase();

	/*
	 * initialization of inner variables dependent on z
	 */
	virtual void init(double z) const;

	/*coefficients wij are dependent on the type of the interface*/
    virtual double wxx() const = 0;
    virtual double wzz() const = 0;
    virtual double wxz() const = 0;
    virtual double wxy() const = 0;
    virtual double wyy() const = 0;
    virtual double wyz() const = 0;

    /*mean squared distortions*/
    double Wxxxx_bx() const;
    double Wzzzz_bx() const;
    double Wxzxz_bx() const;
    double Wxxzz_bx() const;
    double Wzxzx_bx() const;
    double Wxzzx_bx() const;

    double Wyxyx_by() const;
    double Wyzyz_by() const;

    double Wxxxx_bz() const;
    double Wzzzz_bz() const;
    double Wxzxz_bz() const;
    double Wxxzz_bz() const;
    double Wzxzx_bz() const;
    double Wxzzx_bz() const;

    virtual double T(double x, double y, double z1, double z2) const;


    virtual void set_rho(double rho) {m_rho = rho;}
    virtual double get_rho() const {return m_rho;}
protected:
    double alpha, alpha2;
    double bx2, by2, bz2;
    double Qx2, Qz2, Qy2, QxQz, QxQy, QyQz;
    double m_d;
    double m_rho;
    mutable double xi, xi2, xi3, xi4, xi5, xi6, xi7, xi8;
    mutable double denom;
};

class AnalyticalMisfitInterfaceCub : public AnalyticalMisfitInterfaceBase
{
public:
	AnalyticalMisfitInterfaceCub(double rho, double bx, double by, double bz, double Qx, double Qy, double Qz, double phi, double nu,
		 double d);
	virtual ~AnalyticalMisfitInterfaceCub() {}

	/* coefficients wij are calculated
	 * taking into account 2 sets of dislocations on the cubic interface
	 *
	 * Dislocation sets are at the angle of 90-deg to each other
	 */
    virtual double wxx() const;
    virtual double wzz() const;
    virtual double wxz() const;
    virtual double wxy() const;
    virtual double wyy() const;
    virtual double wyz() const;

    virtual double T(double x, double y, double z1, double z2) const
    {
		return AnalyticalMisfitInterfaceBase::T(x, y, z1, z2);
	}
protected:
    /*
     * phi0 - angle between projection of Q on xy-plane and
     * a Burgers vector of a dislocation in the dislocation set
     */
    double sin_4phi0, cos_4phi0;
};

class AnalyticalMisfitInterfaceHex : public AnalyticalMisfitInterfaceBase
{
public:
	AnalyticalMisfitInterfaceHex(double rho, double bx, double by, double bz,
			double Qx, double Qy, double Qz, double nu, double d);
	virtual ~AnalyticalMisfitInterfaceHex() {}

	/* coefficients wij are calculated
	 * taking into account 3 sets of dislocations on the cubic interface
	 *
	 * Dislocation sets are at the angle of 120-deg to each other
	 */
    virtual double wxx() const;
    virtual double wzz() const;
    virtual double wxz() const;
    virtual double wxy() const;
    virtual double wyy() const;
    virtual double wyz() const;

	virtual double T(double x, double y, double z1, double z2) const
	{
		return AnalyticalMisfitInterfaceBase::T(x, y, z1, z2) / 3;
	}
protected:
};

#endif /* ANALYTICAL_MISFIT_INTERFACES_H_ */
