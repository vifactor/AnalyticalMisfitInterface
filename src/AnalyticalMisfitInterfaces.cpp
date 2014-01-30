/*
 * AnalyticalMisfitInterfaces.cpp
 *
 *  Created on: 23 jan 2014
 *      Author: kopp
 */

#include "AnalyticalMisfitInterfaces.h"

AnalyticalMisfitInterfaceBase::AnalyticalMisfitInterfaceBase(double rho, double bx, double by, double bz, double Qx, double Qy, double Qz,
		double nu, double d)
{
	alpha = 1.0 / (2 * (1- nu));
	alpha2 = alpha * alpha;

	bx2 = bx * bx;
	by2 = by * by;
	bz2 = bz * bz;

	Qx2 = Qx * Qx;
	Qy2 = Qy * Qy;
	Qz2 = Qz * Qz;
	QxQz = Qx * Qz;
	QxQy = Qx * Qy;
	QyQz = Qy * Qz;

	m_d = d;
	m_rho = rho;

	/*dummy initialization*/
	xi = 1.0;
	xi2 = 1.0;
	xi3 = 1.0;
	xi4 = 1.0;
	xi5 = 1.0;
	xi6 = 1.0;
	xi7 = 1.0;
	xi8 = 1.0;

	denom = 1.0;
}

AnalyticalMisfitInterfaceBase::~AnalyticalMisfitInterfaceBase()
{
}

double AnalyticalMisfitInterfaceBase::T(double x, double y, double z1, double z2) const
{
	static double z, result;

	if (m_rho != 0.0)
	{
		init(z1);
		z = z1 - z2;

		/*
		 * division coefficient 3 appears due to 3 dislocation sets
		 * it is written here in order to equalize "real" Monte-Carlo dislocation density
		 *  and
		 * density present here
		*/
		result = m_rho / 2
				* (wxx() * x * x + wxz() * x * z + wzz() * z * z);
	}
	else
	{
		result = 0.0;
	}

	return result;
}

void AnalyticalMisfitInterfaceBase::init(double z) const
{
	xi = z / m_d;

	xi2 = xi * xi;
	xi3 = xi2 * xi;
	xi4 = xi3 * xi;
	xi5 = xi4 * xi;
	xi6 = xi5 * xi;
	xi7 = xi6 * xi;
	xi8 = xi7 * xi;

	denom = (8. * m_d * M_PI * (-1 + xi) * gsl_pow_5(1 + xi));
}

double AnalyticalMisfitInterfaceBase::AboveWxxxx_bx() const
{
	static double result;

	result = bx2
			* (-2 - 6 * xi - 2 * (5 + 2 * alpha) * xi2
					+ 2 * (-5 + 4 * alpha) * xi3
					+ (-4 + 18 * alpha - 21 * alpha2) * xi4
					+ (8 - 9 * alpha) * alpha * xi5
					+ alpha * (2 + 5 * alpha) * xi6 + 7 * alpha2 * xi7
					+ 2 * alpha2 * xi8) / denom;

	return result;
}

double AnalyticalMisfitInterfaceBase::AboveWzzzz_bx() const
{
	static double result;

	result = bx2
			* (-2 * gsl_pow_2(1 + xi) * (1 + xi + 2 * xi2)
					- 2 * alpha
							* (-4 - 12 * xi - 22 * xi2 - 16 * xi3 + xi4
									+ 4 * xi5 + xi6)
					+ alpha2
							* (-8 - 24 * xi - 48 * xi2 - 24 * xi3 - xi4
									+ 7 * xi5 + 9 * xi6 + 7 * xi7 + 2 * xi8))
			/ denom;

	return result;
}

double AnalyticalMisfitInterfaceBase::AboveWxzxz_bx() const
{
	static double result;

	result = -bx2
			* (2 + (6 - 4 * alpha) * xi
					+ 2 * (5 + 2 * alpha + 4 * alpha2) * xi2
					+ (10 + 12 * alpha - 4 * alpha2) * xi3
					+ (4 + 10 * alpha - 3 * alpha2) * xi4
					- (-8 + alpha) * alpha * xi5
					+ alpha * (2 + 7 * alpha) * xi6 + 7 * alpha2 * xi7
					+ 2 * alpha2 * xi8) / denom;
	return result;
}


double AnalyticalMisfitInterfaceBase::AboveWxxzz_bx() const
{
	static double result;

	result = -bx2
			* (2 * gsl_pow_2(1 + xi) * (1 + xi + 2 * xi2)
					- 4 * alpha * gsl_pow_2(1 + xi) * (1 + xi + 2 * xi2)
					+ alpha2 * xi2
							* (-4 + 8 * xi - 3 * xi2 - xi3 + 7 * xi4 + 7 * xi5
									+ 2 * xi6)) / denom;
	return result;
}

double AnalyticalMisfitInterfaceBase::AboveWzxzx_bx() const
{
	static double result;

	result = -bx2
			* (2 + (6 + 4 * alpha) * xi
					+ 2 * (5 - 2 * alpha + 4 * alpha2) * xi2
					- 2 * (-5 + 6 * alpha + 2 * alpha2) * xi3
					+ (4 - 10 * alpha - 3 * alpha2) * xi4
					- alpha * (8 + alpha) * xi5
					+ alpha * (-2 + 7 * alpha) * xi6 + 7 * alpha2 * xi7
					+ 2 * alpha2 * xi8) / denom;

	return result;
}

double AnalyticalMisfitInterfaceBase::AboveWxzzx_bx() const
{
	static double result;

	result = bx2
			* (2 + 6 * xi + (10 - 8 * alpha2) * xi2 + 2 * (5 + 2 * alpha2) * xi3
					+ (4 + 3 * alpha2) * xi4 + alpha2 * xi5 - 7 * alpha2 * xi6
					- 7 * alpha2 * xi7 - 2 * alpha2 * xi8) /denom;

	return result;
}

double AnalyticalMisfitInterfaceBase::AboveWxxxx_bz() const
{

	static double result;

	result = bz2
			* (-2 + 2 * xi - 2 * (-5 + 6 * alpha) * xi2 + (-2 + 8 * alpha) * xi3
					- 5 * (4 - 10 * alpha + 9 * alpha2) * xi4
					+ (-16 + 40 * alpha - 45 * alpha2) * xi5
					+ (-4 + 10 * alpha - 5 * alpha2) * xi6 + 11 * alpha2 * xi7
					+ 4 * alpha2 * xi8) / denom;
	return result;
}

double AnalyticalMisfitInterfaceBase::AboveWzzzz_bz() const
{
	static double result;

	result = bz2
			* (-2 * gsl_pow_2(1 + xi) * (1 - 3 * xi + 4 * xi3 + 2 * xi4)
					+ alpha
							* (8 - 8 * xi - 28 * xi2 + 30 * xi4 + 24 * xi5
									+ 6 * xi6)
					+ alpha2
							* (-8 + 8 * xi + 16 * xi2 + 8 * xi3 - 25 * xi4
									- 29 * xi5 - xi6 + 11 * xi7 + 4 * xi8))
			/ denom;
	return result;
}

double AnalyticalMisfitInterfaceBase::AboveWxzxz_bz() const
{
	static double result;

	result = -bz2
			* (10 + (30 - 20 * alpha) * xi
					+ (30 - 28 * alpha + 24 * alpha2) * xi2
					+ 2 * (1 - 2 * alpha + 6 * alpha2) * xi3
					- 5 * (4 - 2 * alpha + 3 * alpha2) * xi4
					+ (-16 + 8 * alpha - 21 * alpha2) * xi5
					+ (-4 + 2 * alpha + alpha2) * xi6 + 11 * alpha2 * xi7
					+ 4 * alpha2 * xi8) / denom;
	return result;
}

double AnalyticalMisfitInterfaceBase::AboveWxxzz_bz() const
{
	static double result;

	result = -bz2
			* (2 * gsl_pow_2(1 + xi) * (1 - 3 * xi + 4 * xi3 + 2 * xi4)
					- 4 * alpha * gsl_pow_2(1 + xi)
							* (1 - 3 * xi + 4 * xi3 + 2 * xi4)
					+ alpha2 * xi2
							* (-12 + 8 * xi + 5 * xi2 - 5 * xi3 + 5 * xi4
									+ 11 * xi5 + 4 * xi6)) / denom;
	return result;
}

double AnalyticalMisfitInterfaceBase::AboveWzxzx_bz() const
{
	static double result;

	result = -bz2
			* (10 + 10 * (3 + 2 * alpha) * xi
					+ (30 + 28 * alpha + 24 * alpha2) * xi2
					+ 2 * (1 + 2 * alpha + 6 * alpha2) * xi3
					- 5 * (4 + 2 * alpha + 3 * alpha2) * xi4
					- (16 + 8 * alpha + 21 * alpha2) * xi5
					+ (-4 - 2 * alpha + alpha2) * xi6 + 11 * alpha2 * xi7
					+ 4 * alpha2 * xi8) / denom;

	return result;
}

double AnalyticalMisfitInterfaceBase::AboveWxzzx_bz() const
{
	static double result;

	result = -(bz2
			* (-10 - 30 * xi + 6 * (-5 + 4 * alpha2) * xi2
					+ 2 * (-1 + 6 * alpha2) * xi3 - 5 * (-4 + 3 * alpha2) * xi4
					+ (16 - 21 * alpha2) * xi5 + (4 + alpha2) * xi6
					+ 11 * alpha2 * xi7 + 4 * alpha2 * xi8)) / denom;

	return result;
}

double AnalyticalMisfitInterfaceBase::AboveWyxyx_by() const
{
	static double result;

	result = by2 * (-2 + xi2) / (4 * m_d * M_PI * (-1 + xi2));

	return result;
}

double AnalyticalMisfitInterfaceBase::AboveWyzyz_by() const
{
	static double result;

	result = by2 * xi2 / (4 * m_d * M_PI * (1 - xi2));

	return result;
}

double AnalyticalMisfitInterfaceBase::BelowWxxxx_bx() const
{
	static double result;

	result = bx2
			* (2 * xi * gsl_pow_2(1 + xi) * (-1 - xi + 2 * xi2 + 4 * xi3)
					- 2 * alpha
							* (1 + xi - 6 * xi2 - 11 * xi3 + xi4 + 18 * xi5
									+ 12 * xi6)
					+ alpha2
							* (4 + 11 * xi + xi2 - 21 * xi3 - 15 * xi4
									+ 12 * xi5 + 24 * xi6))
			/ (denom * xi3);

	return result;
}

double AnalyticalMisfitInterfaceBase::BelowWzzzz_bx() const
{
	static double result;

	result = bx2
			* (2 * xi * gsl_pow_2(1 + xi) * (-1 - xi + 2 * xi2 + 4 * xi3)
					+ alpha2 * xi
							* (-1 + xi + 15 * xi2 + 37 * xi3 + 20 * xi4
									+ 8 * xi5)
					- 2 * alpha
							* (-1 - 5 * xi - 6 * xi2 + 7 * xi3 + 27 * xi4
									+ 22 * xi5 + 4 * xi6))
			/ (denom * xi3);

	return result;
}

double AnalyticalMisfitInterfaceBase::BelowWxzxz_bx() const
{
	static double result;

	result = bx2
			* (2 * xi * gsl_pow_2(1 + xi) * (-1 - xi + 2 * xi2 + 4 * xi3)
					+ alpha
							* (-2 - 6 * xi + 18 * xi3 + 26 * xi4 + 4 * xi5
									- 8 * xi6)
					+ alpha2
							* (2 + 7 * xi + 7 * xi2 - xi3 - 3 * xi4 - 4 * xi5
									+ 8 * xi6))
			/ (denom * xi3);

	return result;
}


double AnalyticalMisfitInterfaceBase::BelowWxxzz_bx() const
{
	static double result;

	result =
			-bx2
					* (-2 * xi * gsl_pow_2(1 + xi)
							* (-1 - xi + 2 * xi2 + 4 * xi3)
							+ 4 * alpha * xi * gsl_pow_2(1 + xi)
									* (-1 - xi + 2 * xi2 + 4 * xi3)
							+ alpha2
									* (2 + 9 * xi + 13 * xi2 + xi3 - 17 * xi4
											- 24 * xi5))
					/ (denom * xi3);
	return result;
}

double AnalyticalMisfitInterfaceBase::BelowWzxzx_bx() const
{
	static double result;

	result = bx2
			* (2 * xi * gsl_pow_2(1 + xi) * (-1 - xi + 2 * xi2 + 4 * xi3)
					+ 2 * alpha
							* (1 + 3 * xi - 9 * xi3 - 13 * xi4 - 2 * xi5
									+ 4 * xi6)
					+ alpha2
							* (2 + 7 * xi + 7 * xi2 - xi3 - 3 * xi4 - 4 * xi5
									+ 8 * xi6))
			/ (denom * xi3);

	return result;
}

double AnalyticalMisfitInterfaceBase::BelowWxzzx_bx() const
{
	static double result;

	result = bx2
			* (-2 * xi * gsl_pow_2(1 + xi) * (-1 - xi + 2 * xi2 + 4 * xi3)
					+ alpha2
							* (2 + 7 * xi + 7 * xi2 - xi3 - 3 * xi4 - 4 * xi5
									+ 8 * xi6))
			/ (denom * xi3);

	return result;
}

double AnalyticalMisfitInterfaceBase::BelowWxxxx_bz() const
{

	static double result;

	result = bz2
			* (2 * xi * gsl_pow_2(1 + xi) * (1 + 3 * xi)
					+ alpha * (2 + 2 * xi - 20 * xi2 - 50 * xi3 - 30 * xi4)
					+ alpha2 * (-4 - 11 * xi + 5 * xi2 + 45 * xi3 + 45 * xi4))
			/ (denom * xi3);

	return result;
}

double AnalyticalMisfitInterfaceBase::BelowWzzzz_bz() const
{
	static double result;

	result = bz2
			* (2 * xi * gsl_pow_2(1 + xi) * (1 + 3 * xi)
					+ alpha2 * xi * (1 + 5 * xi + xi2 + 9 * xi3)
					+ 2 * alpha * (-1 - 5 * xi - 10 * xi2 - 3 * xi3 + 3 * xi4))
			/ (denom * xi3);

	return result;
}

double AnalyticalMisfitInterfaceBase::BelowWxzxz_bz() const
{
	static double result;

	result = bz2
			* (2 * xi * gsl_pow_2(1 + xi) * (1 + 3 * xi)
					+ alpha * (2 + 6 * xi - 22 * xi3 - 18 * xi4)
					+ alpha2 * (-2 - 7 * xi - 5 * xi2 + 9 * xi3 + 21 * xi4))
			/ (denom * xi3);

	return result;
}

double AnalyticalMisfitInterfaceBase::BelowWxxzz_bz() const
{
	static double result;

	result = -bz2
			* (-2 * xi * gsl_pow_2(1 + xi) * (1 + 3 * xi)
					+ 4 * alpha * xi * gsl_pow_2(1 + xi) * (1 + 3 * xi)
					+ alpha2 * (-2 - 9 * xi - 15 * xi2 - 5 * xi3 + 15 * xi4))
			/ (denom * xi3);

	return result;
}

double AnalyticalMisfitInterfaceBase::BelowWzxzx_bz() const
{
	static double result;

	result = bz2
			* (2 * xi * gsl_pow_2(1 + xi) * (1 + 3 * xi)
					+ 2 * alpha * (-1 - 3 * xi + 11 * xi3 + 9 * xi4)
					+ alpha2 * (-2 - 7 * xi - 5 * xi2 + 9 * xi3 + 21 * xi4))
			/ (denom * xi3);

	return result;
}

double AnalyticalMisfitInterfaceBase::BelowWxzzx_bz() const
{
	static double result;

	result = bz2
			* (-2 * xi * gsl_pow_2(1 + xi) * (1 + 3 * xi)
					+ alpha2 * (-2 - 7 * xi - 5 * xi2 + 9 * xi3 + 21 * xi4))
			/ (denom * xi3);

	return result;
}

double AnalyticalMisfitInterfaceBase::BelowWyxyx_by() const
{
	static double result;

	result = -by2 / ( 4 * M_PI * m_d * (xi - xi3));;

	return result;
}

double AnalyticalMisfitInterfaceBase::BelowWyzyz_by() const
{
	static double result;

	result = -by2 / ( 4 * M_PI * m_d * (xi - xi3));

	return result;
}

double AnalyticalMisfitInterfaceBase::Wxxxx_bx() const
{
	if(xi <= 1)
	{
		return AboveWxxxx_bx();
	}else
	{
		return BelowWxxxx_bx();
	}
}

double AnalyticalMisfitInterfaceBase::Wzzzz_bx() const
{
	if(xi <= 1)
	{
		return AboveWzzzz_bx();
	}else
	{
		return BelowWzzzz_bx();
	}
}

double AnalyticalMisfitInterfaceBase::Wxzxz_bx() const
{
	if(xi <= 1)
	{
		return AboveWxzxz_bx();
	}else
	{
		return BelowWxzxz_bx();
	}
}
double AnalyticalMisfitInterfaceBase::Wxxzz_bx() const
{
	if(xi <= 1)
	{
		return AboveWxxzz_bx();
	}else
	{
		return BelowWxxzz_bx();
	}
}

double AnalyticalMisfitInterfaceBase::Wzxzx_bx() const
{
	if(xi <= 1)
	{
		return AboveWzxzx_bx();
	}else
	{
		return BelowWzxzx_bx();
	}
}

double AnalyticalMisfitInterfaceBase::Wxzzx_bx() const
{
	if(xi <= 1)
	{
		return AboveWxzzx_bx();
	}else
	{
		return BelowWxzzx_bx();
	}
}

double AnalyticalMisfitInterfaceBase::Wyxyx_by() const
{
	if(xi <= 1)
	{
		return AboveWyxyx_by();
	}else
	{
		return BelowWyxyx_by();
	}
}

double AnalyticalMisfitInterfaceBase::Wyzyz_by() const
{
	if(xi <= 1)
	{
		return AboveWyzyz_by();
	}else
	{
		return BelowWyzyz_by();
	}
}

double AnalyticalMisfitInterfaceBase::Wxxxx_bz() const
{
	if(xi <= 1)
	{
		return AboveWxxxx_bz();
	}else
	{
		return BelowWxxxx_bz();
	}
}

double AnalyticalMisfitInterfaceBase::Wzzzz_bz() const
{
	if(xi <= 1)
	{
		return AboveWzzzz_bz();
	}else
	{
		return BelowWzzzz_bz();
	}
}

double AnalyticalMisfitInterfaceBase::Wxzxz_bz() const
{
	if(xi <= 1)
	{
		return AboveWxzxz_bz();
	}else
	{
		return BelowWxzxz_bz();
	}
}
double AnalyticalMisfitInterfaceBase::Wxxzz_bz() const
{
	if(xi <= 1)
	{
		return AboveWxxzz_bz();
	}else
	{
		return BelowWxxzz_bz();
	}
}

double AnalyticalMisfitInterfaceBase::Wzxzx_bz() const
{
	if(xi <= 1)
	{
		return AboveWzxzx_bz();
	}else
	{
		return BelowWzxzx_bz();
	}
}

double AnalyticalMisfitInterfaceBase::Wxzzx_bz() const
{
	if(xi <= 1)
	{
		return AboveWxzzx_bz();
	}else
	{
		return BelowWxzzx_bz();
	}
}
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
