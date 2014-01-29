//============================================================================
// Name        : test_interface_cub_by.cpp
// Author      : Viktor Kopp
// Version     :
// Copyright   : Your copyright notice
// Description : Tests for cubic interface class with by component dislocations
//============================================================================

#include <boost/test/unit_test.hpp>
#include "AnalyticalMisfitInterfaces.h"

struct FixtureInterfaceCubBy
{
	FixtureInterfaceCubBy()
    {
		BOOST_TEST_MESSAGE("Setup FixtureInterfaceCub");

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
		Wxxxx_bx = 0;
		Wzzzz_bx = 0;
		Wxzxz_bx = 0;
		Wxxzz_bx = 0;
		Wzxzx_bx = 0;
		Wxzzx_bx = 0;
		Wxxxx_bz = 0;
		Wzzzz_bz = 0;
		Wxzxz_bz = 0;
		Wxxzz_bz = 0;
		Wzxzx_bz = 0;
		Wxzzx_bz = 0;
		Wyxyx_by = 0.0134524;
		Wyzyz_by = 0.00018947;
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

    ~FixtureInterfaceCubBy()
    {
        BOOST_TEST_MESSAGE("Teardown FixtureInterfaceCub");
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

BOOST_FIXTURE_TEST_SUITE(meanDistorsions, FixtureInterfaceCubBy)

BOOST_AUTO_TEST_CASE(Burgers_by_component_Wxxxx_bx)
{
	BOOST_CHECK_CLOSE(interface->Wxxxx_bx(), Wxxxx_bx, 1e-2);
}

BOOST_AUTO_TEST_CASE(Burgers_by_component_Wzzzz_bx)
{
	BOOST_CHECK_CLOSE(interface->Wzzzz_bx(), Wzzzz_bx, 1e-2);
}

BOOST_AUTO_TEST_CASE(Burgers_by_component_Wxzxz_bx)
{
	BOOST_CHECK_CLOSE(interface->Wxzxz_bx(), Wxzxz_bx, 1e-2);
}

BOOST_AUTO_TEST_CASE(Burgers_by_component_Wxxzz_bx)
{
	BOOST_CHECK_CLOSE(interface->Wxxzz_bx(), Wxxzz_bx, 1e-2);
}

BOOST_AUTO_TEST_CASE(Burgers_by_component_Wzxzx_bx)
{
	BOOST_CHECK_CLOSE(interface->Wzxzx_bx(), Wzxzx_bx, 1e-2);
}

BOOST_AUTO_TEST_CASE(Burgers_by_component_Wxzzx_bx)
{
	BOOST_CHECK_CLOSE(interface->Wxzzx_bx(), Wxzzx_bx, 1e-2);
}

BOOST_AUTO_TEST_CASE(Burgers_by_component_Wxxxx_bz)
{
	BOOST_CHECK_CLOSE(interface->Wxxxx_bz(), Wxxxx_bz, 1e-2);
}

BOOST_AUTO_TEST_CASE(Burgers_by_component_Wzzzz_bz)
{
	BOOST_CHECK_CLOSE(interface->Wzzzz_bz(), Wzzzz_bz, 1e-2);
}

BOOST_AUTO_TEST_CASE(Burgers_by_component_Wxzxz_bz)
{
	BOOST_CHECK_CLOSE(interface->Wxzxz_bz(), Wxzxz_bz, 1e-2);
}

BOOST_AUTO_TEST_CASE(Burgers_by_component_Wxxzz_bz)
{
	BOOST_CHECK_CLOSE(interface->Wxxzz_bz(), Wxxzz_bz, 1e-2);
}

BOOST_AUTO_TEST_CASE(Burgers_by_component_Wzxzx_bz)
{
	BOOST_CHECK_CLOSE(interface->Wzxzx_bz(), Wzxzx_bz, 1e-2);
}

BOOST_AUTO_TEST_CASE(Burgers_by_component_Wxzzx_bz)
{
	BOOST_CHECK_CLOSE(interface->Wxzzx_bz(), Wxzzx_bz, 1e-2);
}

BOOST_AUTO_TEST_CASE(Burgers_by_component_Wyxyx_by)
{
	BOOST_CHECK_CLOSE(interface->Wyxyx_by(), Wyxyx_by, 1e-2);
}

BOOST_AUTO_TEST_CASE(Burgers_by_component_Wyzyz_by)
{
	BOOST_CHECK_CLOSE(interface->Wyzyz_by(), Wyzyz_by, 1e-2);
}

BOOST_AUTO_TEST_CASE(Burgers_by_component_wxx)
{
	BOOST_CHECK_CLOSE(interface->wxx(), wxx, 1e-2);
}

BOOST_AUTO_TEST_CASE(Burgers_by_component_wzz)
{
	BOOST_CHECK_CLOSE(interface->wzz(), wzz, 1e-2);
}

BOOST_AUTO_TEST_CASE(Burgers_by_component_wxz)
{
	BOOST_CHECK_CLOSE(interface->wxz(), wxz, 1e-2);
}

BOOST_AUTO_TEST_CASE(Burgers_by_component_wyy)
{
	BOOST_CHECK_CLOSE(interface->wyy(), wyy, 1e-2);
}

BOOST_AUTO_TEST_CASE(Burgers_by_component_wxy)
{
	BOOST_CHECK_CLOSE(interface->wxy(), wxy, 1e-2);
}

BOOST_AUTO_TEST_CASE(Burgers_by_component_wyz)
{
	BOOST_CHECK_CLOSE(interface->wyz(), wyz, 1e-2);
}

BOOST_AUTO_TEST_SUITE_END()
