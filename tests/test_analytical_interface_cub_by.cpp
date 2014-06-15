//============================================================================
// Name        : test_interface_cub_by.cpp
// Author      : Viktor Kopp
// Version     :
// Copyright   : Your copyright notice
// Description : Tests for cubic interface class with by component dislocations
//============================================================================
#include "AnalyticalMisfitInterfaces.h"
#include <gtest/gtest.h>

namespace {
class AnalyticalMisfitInterfaceCubByTest : public ::testing::Test {
protected:
	virtual void SetUp()
    {

		/*dummy parameters used in the Mathematica file*/
		double rho = 0.1;
		double bx = 0.0;
		double by = 1.0;
		double bz = 0.0;
		double Qx = 2.2;
		double Qy = 3.3;
		double Qz = 4.4;
		double phi = M_PI / 9;
		double nu = 1.0 / 3;
		double d = 12;
		double z = 2;


		/**values obtained in the Mathematica*/
		wxx = 0.0815926;
		wyy = 0.130013;
		wzz = 0.00298037;
		wxy = -0.0406298;
		wxz = 0;
		wyz = 0;

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
TEST_F(AnalyticalMisfitInterfaceCubByTest, wxx)
{
	EXPECT_NEAR(interface->wxx(), wxx, 1e-2);
}

TEST_F(AnalyticalMisfitInterfaceCubByTest, wzz)
{
	EXPECT_NEAR(interface->wzz(), wzz, 1e-2);
}

TEST_F(AnalyticalMisfitInterfaceCubByTest, wxz)
{
	EXPECT_NEAR(interface->wxz(), wxz, 1e-2);
}

TEST_F(AnalyticalMisfitInterfaceCubByTest, wyy)
{
	EXPECT_NEAR(interface->wyy(), wyy, 1e-2);
}

TEST_F(AnalyticalMisfitInterfaceCubByTest, wxy)
{
	EXPECT_NEAR(interface->wxy(), wxy, 1e-2);
}

TEST_F(AnalyticalMisfitInterfaceCubByTest, wyz)
{
	EXPECT_NEAR(interface->wyz(), wyz, 1e-2);
}

} //namespace
