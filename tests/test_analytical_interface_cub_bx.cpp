//============================================================================
// Name        : test_analytical_interface_cub_bx.cpp
// Author      : Viktor Kopp
// Version     :
// Copyright   : Your copyright notice
// Description : Tests for cubic interface class with bx component dislocations
//============================================================================
#include "AnalyticalMisfitInterfaceCub.h"
#include <gtest/gtest.h>

namespace {

class AnalyticalMisfitInterfaceCubBxTest : public ::testing::Test {
protected:
    virtual void SetUp()
    {

		/*dummy parameters used in Mathematica file*/
		double rho = 0.1;
		double bx = 1.0;
		double by = 0.0;
		double bz = 0.0;
		double Qx = 2.2;
		double Qy = 3.3;
		double Qz = 4.4;
		double phi = M_PI / 9;
		double nu = 1.0 / 3;
		double d = 12;
		double z = 2;

		/**values obtained in the Mathematica*/
		wxx = 0.195903;
		wyy = 0.173499;
		wzz = 0.150516;
		wxy = 0.0187993;
		wxz = -0.175359;
		wyz = -0.263038;

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

// Tests wij methods
TEST_F(AnalyticalMisfitInterfaceCubBxTest, wxx)
{
	EXPECT_NEAR(interface->wxx(), wxx, 1e-2);
}

TEST_F(AnalyticalMisfitInterfaceCubBxTest, wzz)
{
	EXPECT_NEAR(interface->wzz(), wzz, 1e-2);
}

TEST_F(AnalyticalMisfitInterfaceCubBxTest, wxz)
{
	EXPECT_NEAR(interface->wxz(), wxz, 1e-2);
}

TEST_F(AnalyticalMisfitInterfaceCubBxTest, wyy)
{
	EXPECT_NEAR(interface->wyy(), wyy, 1e-2);
}

TEST_F(AnalyticalMisfitInterfaceCubBxTest, wxy)
{
	EXPECT_NEAR(interface->wxy(), wxy, 1e-2);
}

TEST_F(AnalyticalMisfitInterfaceCubBxTest, wyz)
{
	EXPECT_NEAR(interface->wyz(), wyz, 1e-2);
}

}  // namespace
