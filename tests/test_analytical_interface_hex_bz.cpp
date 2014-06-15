//============================================================================
// Name        : test_interface_cub_bz.cpp
// Author      : Viktor Kopp
// Version     :
// Copyright   : Your copyright notice
// Description : Tests for cubic interface class with bz component dislocations
//============================================================================
#include "AnalyticalMisfitInterfaces.h"
#include <gtest/gtest.h>

namespace {
class AnalyticalMisfitInterfaceHexBzTest : public ::testing::Test {
protected:
	virtual void SetUp()
    {

		/*arbitrary parameters used in Mathematica file*/
		double rho = 0.1;
		double bx = 0.0;
		double by = 0.0;
		double bz = 1.0;
		double Qx = 2.2;
		double Qy = 3.3;
		double Qz = 4.4;
		double nu = 1.0 / 3;
		double d = 12;
		double z = 14;

		/**values obtained in the Mathematica*/
		wxx = 0.900463;
		wyy = 0.915156;
		wzz = 0.682897;
		wxy = 0.0352631;
		wxz = -0.352103;
		wyz = -0.528155;

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

TEST_F(AnalyticalMisfitInterfaceHexBzTest, wxx)
{
	EXPECT_NEAR(interface->wxx(), wxx, 1e-2);
}

TEST_F(AnalyticalMisfitInterfaceHexBzTest, wzz)
{
	EXPECT_NEAR(interface->wzz(), wzz, 1e-2);
}

TEST_F(AnalyticalMisfitInterfaceHexBzTest, wyy)
{
	EXPECT_NEAR(interface->wyy(), wyy, 1e-2);
}

TEST_F(AnalyticalMisfitInterfaceHexBzTest, wxy)
{
	EXPECT_NEAR(interface->wxy(), wxy, 1e-2);
}

TEST_F(AnalyticalMisfitInterfaceHexBzTest, wxz)
{
	EXPECT_NEAR(interface->wxz(), wxz, 1e-2);
}

TEST_F(AnalyticalMisfitInterfaceHexBzTest, wyz)
{
	EXPECT_NEAR(interface->wyz(), wyz, 1e-2);
}

}// namespace
