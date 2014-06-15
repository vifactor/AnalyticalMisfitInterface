/*
 * AnalyticalMisfitInterfaces.cpp
 *
 *  Created on: 23 jan 2014
 *      Author: kopp
 */

#include "AnalyticalMisfitInterfaceHex.h"

/*----------------------Hexagonal interface---------------------------------------*/
AnalyticalMisfitInterfaceHex::AnalyticalMisfitInterfaceHex(double rho,
		double bx, double by, double bz, double Qx, double Qy, double Qz,
		double nu, double d) :
		AnalyticalMisfitInterfaceBase(rho, bx, by, bz, Qx, Qy, Qz, nu, d)
{
}

double AnalyticalMisfitInterfaceHex::wxx() const
{
	static double result, result_bx, result_by, result_bz;

	if (bx2 != 0.0)
	{
		result_bx = 3.0 / 8
				* (3 * Qx2 * Wxxxx_bx() + Qy2 * Wxxxx_bx()
						+ 4 * Qz2 * Wzxzx_bx());
	}
	else
		result_bx = 0;

	if(by2 != 0.0)
	{
		result_by = 3.0 / 8
				* (Qx2 * Wyxyx_by()
						+ 3 * Qy2 * Wyxyx_by());
	}
	else
		result_by = 0;

	if (bz2 != 0.0)
	{
		result_bz = 3.0 / 8
				* (3 * Qx2 * Wxxxx_bz() + Qy2 * Wxxxx_bz()
						+ 4 * Qz2 * Wzxzx_bz());
	}
	else
		result_bz = 0;

	result = result_bx + result_by + result_bz;

	return result;
}

double AnalyticalMisfitInterfaceHex::wzz() const
{
	double result, result_bx, result_by, result_bz;

	if (bx2 != 0.0)
	{
		result_bx = 3.0 / 2 * Wxzxz_bx() * (Qx2 + Qy2)
				+ 3 * Qz2 * Wzzzz_bx();
	}
	else
		result_bx = 0.0;

	if (by2 != 0.0)
	{
		result_by = 3.0 / 2 * Wyzyz_by() * (Qx2 + Qy2);
	}
	else
		result_by = 0.0;

	if (bz2 != 0.0)
	{
		result_bz = 3.0 / 2 * Qx2 * Wxzxz_bz() + 3.0 / 2 * Qy2 * Wxzxz_bz()
				+ 3 * Qz2 * Wzzzz_bz();
	}
	else
		result_bz = 0.0;

	result = result_bx + result_by + result_bz;
	return result;
}

double AnalyticalMisfitInterfaceHex::wxz() const
{
	double result, result_bx, result_bz;

	if (bx2 != 0.0)
	{
		result_bx = 3 * QxQz * (Wxxzz_bx() + Wxzzx_bx());
	}
	else
		result_bx = 0.0;

	if (bz2 != 0.0)
	{
		result_bz = 3 * QxQz * (Wxxzz_bz() + Wxzzx_bz());
	}
	else
		result_bz = 0.0;

	result = result_bx + result_bz;
	return result;
}

double AnalyticalMisfitInterfaceHex::wyy() const
{
	static double result, result_bx, result_by, result_bz;

	if (bx2 != 0.0)
	{
		result_bx = 3.0 / 8 * (Qx2 * Wxxxx_bx()  + Qy2 * 3 * Wxxxx_bx() +
				   4 * Qz2 * Wzxzx_bx());
	}
	else
		result_bx = 0.0;

	if (by2 != 0.0)
	{
		result_by = 3.0 / 8 * (Qx2 *  3 * Wyxyx_by() + Qy2 * Wyxyx_by());
	}
	else
		result_by = 0.0;

	if (bz2 != 0.0)
	{
		result_bz = 3.0 / 8 * (Qx2 * Wxxxx_bz()  + Qy2 * 3 * Wxxxx_bz() +
				   4 * Qz2 * Wzxzx_bz());
	}
	else
		result_bz = 0.0;

	result = result_bx + result_by + result_bz;
	return result;
}

double AnalyticalMisfitInterfaceHex::wxy() const
{
	static double result, result_bx, result_by, result_bz;

	if (bx2 != 0.0)
	{
		result_bx = 3.0 / 2 * QxQy * Wxxxx_bx();
	}
	else
		result_bx = 0.0;

	if (by2 != 0.0)
	{
		result_by =  - 3.0 / 2 * QxQy * Wyxyx_by();
	}
	else
		result_by = 0.0;

	if (bz2 != 0.0)
	{
		result_bz = 3.0 / 2 * QxQy * Wxxxx_bz();
	}
	else
		result_bz = 0.0;

	result = result_bx + result_by + result_bz;
	return result;
}

double AnalyticalMisfitInterfaceHex::wyz() const
{
	static double result, result_bx, result_bz;

	if (bx2 != 0.0)
	{
		result_bx = 3 * QyQz * (Wxxzz_bx() + Wxzzx_bx());
	}
	else
		result_bx = 0.0;

	if (bz2 != 0.0)
	{
		result_bz = 3 * QyQz * (Wxxzz_bz() + Wxzzx_bz());
	}
	else
		result_bz = 0.0;

	result = result_bx + result_bz;
	return result;
}
