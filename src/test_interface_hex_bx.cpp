//============================================================================
// Name        : test_interface_cub_bz.cpp
// Author      : Viktor Kopp
// Version     :
// Copyright   : Your copyright notice
// Description : Tests for cubic interface class with bz component dislocations
//============================================================================

#include <boost/test/unit_test.hpp>
#include "AnalyticalMisfitInterfaces.h"

struct FixtureInterfaceHexBx
{
	FixtureInterfaceHexBx()
    {
		BOOST_TEST_MESSAGE("Setup FixtureInterfaceBzHex");

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

    ~FixtureInterfaceHexBx()
    {
        BOOST_TEST_MESSAGE("Teardown FixtureInterfaceBzHex");
        if(interface)
        	delete interface;
        interface = NULL;
    }
    double wxx, wyy, wzz, wxy, wxz, wyz;

    AnalyticalMisfitInterfaceHex * interface;
};

BOOST_FIXTURE_TEST_SUITE(HexInterfaceWij, FixtureInterfaceHexBx)

BOOST_AUTO_TEST_CASE(Hex_Burgers_bx_component_wxx)
{
	BOOST_CHECK_CLOSE(interface->wxx(), wxx, 1e-2);
}

BOOST_AUTO_TEST_CASE(Hex_Burgers_bx_component_wzz)
{
	BOOST_CHECK_CLOSE(interface->wzz(), wzz, 1e-2);
}

BOOST_AUTO_TEST_CASE(Hex_Burgers_bx_component_wxz)
{
	BOOST_CHECK_CLOSE(interface->wxz(), wxz, 1e-2);
}

BOOST_AUTO_TEST_CASE(Hex_Burgers_bx_component_wyy)
{
	BOOST_CHECK_CLOSE(interface->wyy(), wyy, 1e-2);
}

BOOST_AUTO_TEST_CASE(Hex_Burgers_bx_component_wxy)
{
	BOOST_CHECK_CLOSE(interface->wxy(), wxy, 1e-2);
}

BOOST_AUTO_TEST_CASE(Hex_Burgers_bx_component_wyz)
{
	BOOST_CHECK_CLOSE(interface->wyz(), wyz, 1e-2);
}

BOOST_AUTO_TEST_SUITE_END()
