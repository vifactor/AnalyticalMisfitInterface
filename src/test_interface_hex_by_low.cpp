/*
 * test_interface_hex_by_low.cpp
 *
 *  Created on: 14 jun. 2014
 *      Author: kopp
 */

#include <boost/test/unit_test.hpp>
#include "AnalyticalMisfitInterfaces.h"

struct FixtureInterfaceHexByLow
{
	FixtureInterfaceHexByLow()
    {
		BOOST_TEST_MESSAGE("Setup FixtureInterfaceHexByLow");

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
		double z = 14;


		/**values obtained in the Mathematica*/
		wxx = 0.0954713;
		wyy = 0.152128;
		wzz = 0.2476;
		wxy = -0.0475409;
		wxz = 0;
		wyz = 0;
        interface = new AnalyticalMisfitInterfaceHex(rho, bx, by, bz, Qx, Qy,
				Qz, nu, d);
		interface->init(z);
    }

    ~FixtureInterfaceHexByLow()
    {
        BOOST_TEST_MESSAGE("Teardown FixtureInterfaceHexByLow");
        if(interface)
        	delete interface;
        interface = NULL;
    }
    double wxx, wyy, wzz, wxy, wxz, wyz;

    AnalyticalMisfitInterfaceHex * interface;
};

BOOST_FIXTURE_TEST_SUITE(TestsInterfaceLow, FixtureInterfaceHexByLow)

BOOST_AUTO_TEST_CASE(Hex_Burgers_by_component_wxx_low)
{
	BOOST_CHECK_CLOSE(interface->wxx(), wxx, 1e-2);
}

BOOST_AUTO_TEST_CASE(Hex_Burgers_by_component_wzz_low)
{
	BOOST_CHECK_CLOSE(interface->wzz(), wzz, 1e-2);
}

BOOST_AUTO_TEST_CASE(Hex_Burgers_by_component_wxz_low)
{
	BOOST_CHECK_CLOSE(interface->wxz(), wxz, 1e-2);
}

BOOST_AUTO_TEST_CASE(Hex_Burgers_by_component_wyy_low)
{
	BOOST_CHECK_CLOSE(interface->wyy(), wyy, 1e-2);
}

BOOST_AUTO_TEST_CASE(Hex_Burgers_by_component_wxy_low)
{
	BOOST_CHECK_CLOSE(interface->wxy(), wxy, 1e-2);
}

BOOST_AUTO_TEST_CASE(Hex_Burgers_by_component_wyz_low)
{
	BOOST_CHECK_CLOSE(interface->wyz(), wyz, 1e-2);
}

BOOST_AUTO_TEST_SUITE_END()


