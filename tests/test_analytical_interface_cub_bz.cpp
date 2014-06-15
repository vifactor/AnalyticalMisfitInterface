//============================================================================
// Name        : test_interface_cub_bz.cpp
// Author      : Viktor Kopp
// Version     :
// Copyright   : Your copyright notice
// Description : Tests for cubic interface class with bz component dislocations
//============================================================================
#include "AnalyticalMisfitInterfaceCub.h"
#include <gtest/gtest.h>

namespace {
class AnalyticalMisfitInterfaceCubBzTest : public ::testing::Test {
protected:
	virtual void SetUp()
    {
		/*dummy parameters used in Mathematica file*/
		double rho = 0.1;
		double bx = 0.0;
		double by = 0.0;
		double bz = 1.0;
		double Qx = 2.2;
		double Qy = 3.3;
		double Qz = 4.4;
		double phi = M_PI / 9;
		double nu = 1.0 / 3;
		double d = 12;
		double z = 2;

		/**values obtained in the Mathematica*/
		wxx = 0.717299;
		wyy = 0.706512;
		wzz = 0.413883;
		wxy = 0.00905059;
		wxz = -0.580902;
		wyz = -0.871353;

		interface = new AnalyticalMisfitInterfaceCub(rho, bx, by, bz, Qx, Qy,
				Qz, phi, nu, d);
		interface->init(z);
    }

    virtual void TearDown()
    {
        if(interface)
        	delete interface;
        interface = NULL;
    }
    double wxx, wyy, wzz, wxy, wxz, wyz;

    AnalyticalMisfitInterfaceCub * interface;
};

TEST_F(AnalyticalMisfitInterfaceCubBzTest, wxx)
{
	EXPECT_NEAR(interface->wxx(), wxx, 1e-2);
}

TEST_F(AnalyticalMisfitInterfaceCubBzTest, wzz)
{
	EXPECT_NEAR(interface->wzz(), wzz, 1e-2);
}

TEST_F(AnalyticalMisfitInterfaceCubBzTest, wxz)
{
	EXPECT_NEAR(interface->wxz(), wxz, 1e-2);
}

TEST_F(AnalyticalMisfitInterfaceCubBzTest, wyy)
{
	EXPECT_NEAR(interface->wyy(), wyy, 1e-2);
}

TEST_F(AnalyticalMisfitInterfaceCubBzTest, wxy)
{
	EXPECT_NEAR(interface->wxy(), wxy, 1e-2);
}

TEST_F(AnalyticalMisfitInterfaceCubBzTest, wyz)
{
	EXPECT_NEAR(interface->wyz(), wyz, 1e-2);
}

}//namespace
