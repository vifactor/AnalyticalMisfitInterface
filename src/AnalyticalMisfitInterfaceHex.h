/*
 * AnalyticalMisfitInterfaceHex.h
 *
 *  Created on: 23 jan 2014
 *      Author: kopp
 */

#ifndef ANALYTICAL_MISFIT_INTERFACE_HEX_H_
#define ANALYTICAL_MISFIT_INTERFACE_HEX_H_

#include "AnalyticalMisfitInterfaceBase.h"

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

#endif /* ANALYTICAL_MISFIT_INTERFACE_HEX_H_ */
