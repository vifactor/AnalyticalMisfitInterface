/*
 * AnalyticalMisfitInterfaceCub.cpp
 *
 *  Created on: 23 jan 2014
 *      Author: kopp
 */

#include "AnalyticalMisfitInterfaceCub.h"

/*----------------------Cubic interface------------------------------------------*/
AnalyticalMisfitInterfaceCub::AnalyticalMisfitInterfaceCub(double rho,
		double bx, double by, double bz, double Qx, double Qy, double Qz,
		double phi0, double nu, double d) :
		AnalyticalMisfitInterfaceBase(rho, bx, by, bz, Qx, Qy, Qz, nu, d)
{
	sin_4phi0 = sin(4 * phi0);
	cos_4phi0 = cos(4 * phi0);
}

double AnalyticalMisfitInterfaceCub::wxx() const
{
	static double result, result_bx, result_by, result_bz;

	if (bx2 != 0.0)
	{
		result_bx = 1.0 / 4
				* (3 * Qx2 * Wxxxx_bx() + Qy2 * Wxxxx_bx()
						+ 4 * Qz2 * Wzxzx_bx()
						+ (Qx2 - Qy2) * Wxxxx_bx() * cos_4phi0
						+ 2 * QxQy * Wxxxx_bx() * sin_4phi0);
	}
	else
		result_bx = 0.0;

	if (by2 != 0.0)
	{
		result_by = 1.0 / 4
				* (Qx2 + 3 * Qy2 - (Qx2 - Qy2) * cos_4phi0
						- 2 * QxQy * sin_4phi0) * Wyxyx_by();
	}
	else
		result_by = 0.0;

	if (bz2 != 0.0)
	{
		result_bz = 1.0 / 4
				* (3 * Qx2 * Wxxxx_bz() + Qy2 * Wxxxx_bz() + 4 * Qz2 * Wzxzx_bz()
						+ (Qx2 - Qy2) * Wxxxx_bz() * cos_4phi0
						+ 2 * QxQy * Wxxxx_bz() * sin_4phi0);
	}
	else
		result_bz = 0.0;

	result = result_bx + result_by + result_bz;

	return result;
}

double AnalyticalMisfitInterfaceCub::wyy() const
{
	static double result, result_bx, result_by, result_bz;

	if (bx2 != 0.0)
	{
		result_bx = 1.0 / 4
				* (Qx2 * Wxxxx_bx() + 3 * Qy2 * Wxxxx_bx()
						+ 4 * Qz2 * Wzxzx_bx()
						- (Qx2 - Qy2) * Wxxxx_bx() * cos_4phi0
						- 2 * QxQy * Wxxxx_bx() * sin_4phi0);
	}
	else
	{
		result_bx = 0.0;
	}

	if (by2 != 0.0)
	{
		result_by = 1.0 / 4
				* (3 * Qx2 + Qy2 + (Qx2 - Qy2) * cos_4phi0
						+ 2 * QxQy * sin_4phi0) * Wyxyx_by();
	}
	else
		result_by = 0.0;

	if (bz2 != 0.0)
	{
		result_bz = 1.0 / 4
				* (Qx2 * Wxxxx_bz() + 3 * Qy2 * Wxxxx_bz()
						+ 4 * Qz2 * Wzxzx_bz()
						- (Qx2 - Qy2) * Wxxxx_bz() * cos_4phi0
						- 2 * QxQy * Wxxxx_bz() * sin_4phi0);
	}
	else
		result_bz = 0.0;
	result = result_bx + result_by + result_bz;

	return result;
}

double AnalyticalMisfitInterfaceCub::wzz() const
{
	double result, result_bx, result_by, result_bz;

	if (bx2 != 0.0)
	{
		result_bx = Qx2 * Wxzxz_bx() + Qy2 * Wxzxz_bx() + 2 * Qz2 * Wzzzz_bx();
	}
	else
		result_bx = 0.0;

	if (by2 != 0.0)
	{
		result_by = Qx2 * Wyzyz_by() + Qy2 * Wyzyz_by();
	}
	else
		result_by = 0.0;

	if (bz2 != 0.0)
	{
		result_bz = Qx2 * Wxzxz_bz() + Qy2 * Wxzxz_bz() + 2 * Qz2 * Wzzzz_bz();
	}
	else
		result_bz = 0.0;

	result = result_bx + result_by + result_bz;
	return result;
}

double AnalyticalMisfitInterfaceCub::wxy() const
{
	static double result, result_bx, result_by, result_bz;

	if (bx2 != 0.0)
	{
		result_bx = Wxxxx_bx()
				* ((Qx2 - Qy2) * sin_4phi0 + 2 * QxQy * (1 - cos_4phi0)) / 2;
	}
	else
		result_bx = 0.0;

	if (by2 != 0.0)
	{
		result_by = -Wyxyx_by()
				* ((Qx2 - Qy2) * sin_4phi0 + 2 * QxQy * (1 - cos_4phi0)) / 2;
	}
	else
		result_by = 0.0;

	if (bz2 != 0.0)
	{
		result_bz = Wxxxx_bz()
				* ((Qx2 - Qy2) * sin_4phi0 + 2 * QxQy * (1 - cos_4phi0)) / 2;
	}
	else
		result_bz = 0.0;

	result = result_bx + result_by + result_bz;
	return result;
}

double AnalyticalMisfitInterfaceCub::wxz() const
{
	static double result, result_bx, result_bz;

	if (bx2 != 0.0)
	{
		result_bx = 2 * QxQz * (Wxxzz_bx() + Wxzzx_bx());
	}
	else
		result_bx = 0.0;

	if (bz2 != 0.0)
	{
		result_bz = 2 * QxQz * (Wxxzz_bz() + Wxzzx_bz());
	}
	else
		result_bz = 0.0;

	result = result_bx + result_bz;
	return result;
}

double AnalyticalMisfitInterfaceCub::wyz() const
{
	static double result, result_bx, result_bz;

	if (bx2 != 0.0)
	{
		result_bx = 2 * QyQz * (Wxxzz_bx() + Wxzzx_bx());
	}
	else
		result_bx = 0.0;

	if (bz2 != 0.0)
	{
		result_bz = 2 * QyQz * (Wxxzz_bz() + Wxzzx_bz());
	}
	else
		result_bz = 0.0;

	result = result_bx + result_bz;
	return result;
}

