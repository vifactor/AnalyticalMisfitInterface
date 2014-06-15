/*
 * AnalyticalMisfitInterfaces.h
 *
 *  Created on: 23 jan 2014
 *      Author: kopp
 */

#ifndef ANALYTICAL_MISFIT_INTERFACE_BASE_H_
#define ANALYTICAL_MISFIT_INTERFACE_BASE_H_

#include <gsl/gsl_math.h>

class AnalyticalMisfitInterfaceBase
{
public:
	AnalyticalMisfitInterfaceBase(double rho, double bx, double by, double bz,
	                             double Qx, double Qy, double Qz,
	                             double nu, double d);
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

    /*mean squared distortions below the interface*/
    double BelowWxxxx_bx() const;
    double BelowWzzzz_bx() const;
    double BelowWxzxz_bx() const;
    double BelowWxxzz_bx() const;
    double BelowWzxzx_bx() const;
    double BelowWxzzx_bx() const;

    double BelowWyxyx_by() const;
    double BelowWyzyz_by() const;

    double BelowWxxxx_bz() const;
    double BelowWzzzz_bz() const;
    double BelowWxzxz_bz() const;
    double BelowWxxzz_bz() const;
    double BelowWzxzx_bz() const;
    double BelowWxzzx_bz() const;

    /*mean squared distortions above the interface*/
    double AboveWxxxx_bx() const;
    double AboveWzzzz_bx() const;
    double AboveWxzxz_bx() const;
    double AboveWxxzz_bx() const;
    double AboveWzxzx_bx() const;
    double AboveWxzzx_bx() const;

    double AboveWyxyx_by() const;
    double AboveWyzyz_by() const;

    double AboveWxxxx_bz() const;
    double AboveWzzzz_bz() const;
    double AboveWxzxz_bz() const;
    double AboveWxxzz_bz() const;
    double AboveWzxzx_bz() const;
    double AboveWxzzx_bz() const;
};

#endif /* ANALYTICAL_MISFIT_INTERFACE_BASE_H_ */
