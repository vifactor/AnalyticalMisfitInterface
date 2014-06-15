//============================================================================
// Name        : test_interface_hex_bx.cpp
// Author      : Viktor Kopp
// Version     :
// Copyright   : Your copyright notice
// Description : Tests for hexagonal interface class with bx component dislocations
//============================================================================
#include "AnalyticalMisfitInterfaceHex.h"
#include <gtest/gtest.h>

namespace {
class AnalyticalMisfitInterfaceHexBxTest : public ::testing::Test {
protected:
	virtual void SetUp()
    {

		/*arbitrary parameters used in Mathematica file*/
		double rho = 0.1;
		double bx = 1.0;
		double by = 0.0;
		double bz = 0.0;
		double Qx = 2.2;
		double Qy = 3.3;
		double Qz = 4.4;
		double nu = 1.0 / 3;
		double d = 12;
		double z = 14;

		/**values obtained in the Mathematica*/
		wxx = 0.430432;
		wyy = 0.464737;
		wzz = 0.931094;
		wxy = 0.0823298;
		wxz = -0.540471;
		wyz = -0.810706;

		interface = new AnalyticalMisfitInterfaceHex(rho, bx, by, bz, Qx, Qy,
				Qz, nu, d);
		interface->init(z);
    }

    virtual void TearDown()
    {
        if(interface)
        	delete interface;
        interface = NULL;
    }
    double wxx, wyy, wzz, wxy, wxz, wyz;

    AnalyticalMisfitInterfaceHex * interface;
};

TEST_F(AnalyticalMisfitInterfaceHexBxTest, wxx)
{
	EXPECT_NEAR(interface->wxx(), wxx, 1e-2);
}

TEST_F(AnalyticalMisfitInterfaceHexBxTest, wzz)
{
	EXPECT_NEAR(interface->wzz(), wzz, 1e-2);
}

TEST_F(AnalyticalMisfitInterfaceHexBxTest, wxz)
{
	EXPECT_NEAR(interface->wxz(), wxz, 1e-2);
}

TEST_F(AnalyticalMisfitInterfaceHexBxTest, wyy)
{
	EXPECT_NEAR(interface->wyy(), wyy, 1e-2);
}

TEST_F(AnalyticalMisfitInterfaceHexBxTest, wxy)
{
	EXPECT_NEAR(interface->wxy(), wxy, 1e-2);
}

TEST_F(AnalyticalMisfitInterfaceHexBxTest, wyz)
{
	EXPECT_NEAR(interface->wyz(), wyz, 1e-2);
}

}//namespace
