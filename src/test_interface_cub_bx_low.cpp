/*
 * test_interface_cub_by_low.cpp
 *
 *  Created on: 29 jan. 2014
 *      Author: kopp
 */

#include <boost/test/unit_test.hpp>
#include "AnalyticalMisfitInterfaces.h"

struct FixtureInterfaceCubBxLow
{
	FixtureInterfaceCubBxLow()
    {
		BOOST_TEST_MESSAGE("Setup FixtureInterfaceCubBxLow");

		/*dummy parameters used in the Mathematica file*/
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
		double z = 14;


		/**values obtained in the Mathematica*/
		Wxxxx_bx = 0.00756013;
		Wzzzz_bx = 0.00202806;
		Wxzxz_bx = 0.0344693;
		Wxxzz_bx = -0.00231252;
		Wzxzx_bx = 0.0123414;
		Wxzzx_bx = -0.0162987;
		Wxxxx_bz = 0.0;
		Wzzzz_bz = 0.0;
		Wxzxz_bz = 0.0;
		Wxxzz_bz = 0.0;
		Wzxzx_bz = 0.0;
		Wxzzx_bz = 0.0;
		Wyxyx_by = 0.0;
		Wyzyz_by = 0.0;
		wxx = 0.311996;
		wyy = 0.284784;
		wzz = 0.620729;
		wxy = 0.0228336;
		wxz = -0.360314;
		wyz = -0.540471;

		interface = new AnalyticalMisfitInterfaceCub(rho, bx, by, bz, Qx, Qy,
				Qz, phi, nu, d);
		interface->init(z);
    }

    ~FixtureInterfaceCubBxLow()
    {
        BOOST_TEST_MESSAGE("Teardown FixtureInterfaceCubBxLow");
        if(interface)
        	delete interface;
        interface = NULL;
    }
    double Wxxxx_bx, Wzzzz_bx, Wxzxz_bx, Wxxzz_bx, Wzxzx_bx, Wxzzx_bx;
    double Wxxxx_bz, Wzzzz_bz, Wxzxz_bz, Wxxzz_bz, Wzxzx_bz, Wxzzx_bz;
    double Wyxyx_by, Wyzyz_by;
    double wxx, wyy, wzz, wxy, wxz, wyz;

    AnalyticalMisfitInterfaceCub * interface;
};

BOOST_FIXTURE_TEST_SUITE(TestsInterfaceLow, FixtureInterfaceCubBxLow)

BOOST_AUTO_TEST_CASE(Burgers_bx_component_Wxxxx_bx_low)
{
	BOOST_CHECK_CLOSE(interface->Wxxxx_bx(), Wxxxx_bx, 1e-2);
}

BOOST_AUTO_TEST_CASE(Burgers_bx_component_Wzzzz_bx_low)
{
	BOOST_CHECK_CLOSE(interface->Wzzzz_bx(), Wzzzz_bx, 1e-2);
}

BOOST_AUTO_TEST_CASE(Burgers_bx_component_Wxzxz_bx_low)
{
	BOOST_CHECK_CLOSE(interface->Wxzxz_bx(), Wxzxz_bx, 1e-2);
}

BOOST_AUTO_TEST_CASE(Burgers_bx_component_Wxxzz_bx_low)
{
	BOOST_CHECK_CLOSE(interface->Wxxzz_bx(), Wxxzz_bx, 1e-2);
}

BOOST_AUTO_TEST_CASE(Burgers_bx_component_Wzxzx_bx_low)
{
	BOOST_CHECK_CLOSE(interface->Wzxzx_bx(), Wzxzx_bx, 1e-2);
}

BOOST_AUTO_TEST_CASE(Burgers_bx_component_Wxzzx_bx_low)
{
	BOOST_CHECK_CLOSE(interface->Wxzzx_bx(), Wxzzx_bx, 1e-2);
}

BOOST_AUTO_TEST_CASE(Burgers_bx_component_Wxxxx_bz_low)
{
	BOOST_CHECK_CLOSE(interface->Wxxxx_bz(), Wxxxx_bz, 1e-2);
}

BOOST_AUTO_TEST_CASE(Burgers_bx_component_Wzzzz_bz_low)
{
	BOOST_CHECK_CLOSE(interface->Wzzzz_bz(), Wzzzz_bz, 1e-2);
}

BOOST_AUTO_TEST_CASE(Burgers_bx_component_Wxzxz_bz_low)
{
	BOOST_CHECK_CLOSE(interface->Wxzxz_bz(), Wxzxz_bz, 1e-2);
}

BOOST_AUTO_TEST_CASE(Burgers_bx_component_Wxxzz_bz_low)
{
	BOOST_CHECK_CLOSE(interface->Wxxzz_bz(), Wxxzz_bz, 1e-2);
}

BOOST_AUTO_TEST_CASE(Burgers_bx_component_Wzxzx_bz_low)
{
	BOOST_CHECK_CLOSE(interface->Wzxzx_bz(), Wzxzx_bz, 1e-2);
}

BOOST_AUTO_TEST_CASE(Burgers_bx_component_Wxzzx_bz_low)
{
	BOOST_CHECK_CLOSE(interface->Wxzzx_bz(), Wxzzx_bz, 1e-2);
}

BOOST_AUTO_TEST_CASE(Burgers_bx_component_Wyxyx_by_low)
{
	BOOST_CHECK_CLOSE(interface->Wyxyx_by(), Wyxyx_by, 1e-2);
}

BOOST_AUTO_TEST_CASE(Burgers_bx_component_Wyzyz_by_low)
{
	BOOST_CHECK_CLOSE(interface->Wyzyz_by(), Wyzyz_by, 1e-2);
}

BOOST_AUTO_TEST_CASE(Burgers_bx_component_wxx_low)
{
	BOOST_CHECK_CLOSE(interface->wxx(), wxx, 1e-2);
}

BOOST_AUTO_TEST_CASE(Burgers_bx_component_wzz_low)
{
	BOOST_CHECK_CLOSE(interface->wzz(), wzz, 1e-2);
}

BOOST_AUTO_TEST_CASE(Burgers_bx_component_wxz_low)
{
	BOOST_CHECK_CLOSE(interface->wxz(), wxz, 1e-2);
}

BOOST_AUTO_TEST_CASE(Burgers_bx_component_wyy_low)
{
	BOOST_CHECK_CLOSE(interface->wyy(), wyy, 1e-2);
}

BOOST_AUTO_TEST_CASE(Burgers_bx_component_wxy_low)
{
	BOOST_CHECK_CLOSE(interface->wxy(), wxy, 1e-2);
}

BOOST_AUTO_TEST_CASE(Burgers_bx_component_wyz_low)
{
	BOOST_CHECK_CLOSE(interface->wyz(), wyz, 1e-2);
}

BOOST_AUTO_TEST_SUITE_END()


