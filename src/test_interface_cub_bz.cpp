//============================================================================
// Name        : test_interface_cub_bz.cpp
// Author      : Viktor Kopp
// Version     :
// Copyright   : Your copyright notice
// Description : Tests for cubic interface class with bz component dislocations
//============================================================================

#include <boost/test/unit_test.hpp>
#include "AnalyticalMisfitInterfaces.h"

struct FixtureInterfaceCubBz
{
	FixtureInterfaceCubBz()
    {
		BOOST_TEST_MESSAGE("Setup FixtureInterfaceCub");

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

		interface = new AnalyticalMisfitInterfaceCub(rho, bx, by, bz, Qx, Qy,
				Qz, phi, nu, d);
		interface->init(z);
    }

    ~FixtureInterfaceCubBz()
    {
        BOOST_TEST_MESSAGE("Teardown FixtureInterfaceCub");
        if(interface)
        	delete interface;
        interface = NULL;
    }
    AnalyticalMisfitInterfaceCub * interface;
};

BOOST_FIXTURE_TEST_SUITE(meanDistorsions, FixtureInterfaceCubBz)

BOOST_AUTO_TEST_CASE(Burgers_bz_component_Wxxxx_bx)
{
	double val = 0.00622437;
	BOOST_CHECK_CLOSE(interface->Wxxxx_bx(), val, 1e-2);
}

BOOST_AUTO_TEST_CASE(Burgers_bz_component_Wzzzz_bx)
{
	double val = 0.00158983;
	BOOST_CHECK_CLOSE(interface->Wzzzz_bx(), val, 1e-2);
}

BOOST_AUTO_TEST_CASE(Burgers_bz_component_Wxzxz_bx)
{
	double val = 0.0056553;
	BOOST_CHECK_CLOSE(interface->Wxzxz_bx(), val, 1e-2);
}

BOOST_AUTO_TEST_CASE(Burgers_bz_component_Wxxzz_bx)
{
	double val = -0.00314146;
	BOOST_CHECK_CLOSE(interface->Wxxzz_bx(), val, 1e-2);
}

BOOST_AUTO_TEST_CASE(Burgers_bz_component_Wzxzx_bx)
{
	double val = 0.00701169;
	BOOST_CHECK_CLOSE(interface->Wzxzx_bx(), val, 1e-2);
}

BOOST_AUTO_TEST_CASE(Burgers_bz_component_Wxzzx_bx)
{
	double val = -0.00591633;
	BOOST_CHECK_CLOSE(interface->Wxzzx_bx(), val, 1e-2);
}

BOOST_AUTO_TEST_CASE(Burgers_bz_component_Wxxxx_bz)
{
	double val = 0.00299662;
	BOOST_CHECK_CLOSE(interface->Wxxxx_bz(), val, 1e-2);
}

BOOST_AUTO_TEST_CASE(Burgers_bz_component_Wzzzz_bz)
{
	double val = 0.000867747;
	BOOST_CHECK_CLOSE(interface->Wzzzz_bz(), val, 1e-2);
}

BOOST_AUTO_TEST_CASE(Burgers_bz_component_Wxzxz_bz)
{
	double val = 0.0241759;
	BOOST_CHECK_CLOSE(interface->Wxzxz_bz(), val, 1e-2);
}

BOOST_AUTO_TEST_CASE(Burgers_bz_component_Wxxzz_bz)
{
	double val = -0.0016064;
	BOOST_CHECK_CLOSE(interface->Wxxzz_bz(), val, 1e-2);
}

BOOST_AUTO_TEST_CASE(Burgers_bz_component_Wzxzx_bz)
{
	double val = 0.0355543;
	BOOST_CHECK_CLOSE(interface->Wzxzx_bz(), val, 1e-2);
}

BOOST_AUTO_TEST_CASE(Burgers_bz_component_Wxzzx_bz)
{
	double val = -0.0283989;
	BOOST_CHECK_CLOSE(interface->Wxzzx_bz(), val, 1e-2);
}

BOOST_AUTO_TEST_CASE(Burgers_bz_component_Wyxyx_by)
{
	double val = 0.0134524;
	BOOST_CHECK_CLOSE(interface->Wyxyx_by(), val, 1e-2);
}

BOOST_AUTO_TEST_CASE(Burgers_bz_component_Wyzyz_by)
{
	double val = 0.00018947;
	BOOST_CHECK_CLOSE(interface->Wyzyz_by(), val, 1e-2);
}

BOOST_AUTO_TEST_CASE(Burgers_bz_component_wxx)
{
	double val = 0.195903;
	BOOST_CHECK_CLOSE(interface->wxx(), val, 1e-2);
}

BOOST_AUTO_TEST_CASE(Burgers_bz_component_wzz)
{
	double val = 0.150516;
	BOOST_CHECK_CLOSE(interface->wzz(), val, 1e-2);
}

BOOST_AUTO_TEST_CASE(Burgers_bz_component_wxz)
{
	double val = -0.175359;
	BOOST_CHECK_CLOSE(interface->wxz(), val, 1e-2);
}

BOOST_AUTO_TEST_CASE(Burgers_bz_component_wyy)
{
	double val = 0.173499;
	BOOST_CHECK_CLOSE(interface->wyy(), val, 1e-2);
}

BOOST_AUTO_TEST_CASE(Burgers_bz_component_wxy)
{
	double val = 0.0187993;
	BOOST_CHECK_CLOSE(interface->wxy(), val, 1e-2);
}

BOOST_AUTO_TEST_CASE(Burgers_bz_component_wyz)
{
	double val = -0.263038;
	BOOST_CHECK_CLOSE(interface->wyz(), val, 1e-2);
}

BOOST_AUTO_TEST_SUITE_END()
