/*
 * AnalyticalMisfitInterfaceCub.h
 *
 *  Created on: 23 jan 2014
 *      Author: kopp
 */

#ifndef ANALYTICAL_MISFIT_INTERFACE_CUB_H_
#define ANALYTICAL_MISFIT_INTERFACE_CUB_H_

#include "AnalyticalMisfitInterfaceBase.h"

class AnalyticalMisfitInterfaceCub : public AnalyticalMisfitInterfaceBase
{
public:
	AnalyticalMisfitInterfaceCub(double rho, double bx, double by, double bz,
	                             double Qx, double Qy, double Qz,
	                             double phi, double nu, double d);
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

#endif /* ANALYTICAL_MISFIT_INTERFACE_CUB_H_ */
