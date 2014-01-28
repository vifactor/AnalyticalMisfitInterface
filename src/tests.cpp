//============================================================================
// Name        : tests.cpp
// Author      : Viktor Kopp
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE Fixtures
#include <boost/test/unit_test.hpp>
#include "AnalyticalMisfitInterfaces.h"

struct FixtureInterfaceCub
{
	FixtureInterfaceCub()
    {
		BOOST_TEST_MESSAGE("Setup FixtureInterfaceCub");

		/*dummy parameters used in Mathematica file*/
		double rho = 0.1;
		double bx = 1.0;
		double by = 1.0;
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

    ~FixtureInterfaceCub()
    {
        BOOST_TEST_MESSAGE("Teardown FixtureInterfaceCub");
        if(interface)
        	delete interface;
        interface = NULL;
    }
    AnalyticalMisfitInterfaceCub * interface;
};

BOOST_FIXTURE_TEST_SUITE(meanDistorsions, FixtureInterfaceCub)

BOOST_AUTO_TEST_CASE(Wxxxx_bx)
{
	double val = 0.00622437;
	BOOST_CHECK_CLOSE(interface->Wxxxx_bx(), val, 1e-2);
}

BOOST_AUTO_TEST_CASE(Wzzzz_bx)
{
	double val = 0.00158983;
	BOOST_CHECK_CLOSE(interface->Wzzzz_bx(), val, 1e-2);
}

BOOST_AUTO_TEST_CASE(Wxzxz_bx)
{
	double val = 0.0056553;
	BOOST_CHECK_CLOSE(interface->Wxzxz_bx(), val, 1e-2);
}

BOOST_AUTO_TEST_CASE(Wxxzz_bx)
{
	double val = -0.00314146;
	BOOST_CHECK_CLOSE(interface->Wxxzz_bx(), val, 1e-2);
}

BOOST_AUTO_TEST_CASE(Wzxzx_bx)
{
	double val = 0.00701169;
	BOOST_CHECK_CLOSE(interface->Wzxzx_bx(), val, 1e-2);
}

BOOST_AUTO_TEST_CASE(Wxzzx_bx)
{
	double val = -0.00591633;
	BOOST_CHECK_CLOSE(interface->Wxzzx_bx(), val, 1e-2);
}

BOOST_AUTO_TEST_CASE(Wxxxx_bz)
{
	double val = 0.00299662;
	BOOST_CHECK_CLOSE(interface->Wxxxx_bz(), val, 1e-2);
}

BOOST_AUTO_TEST_CASE(Wzzzz_bz)
{
	double val = 0.000867747;
	BOOST_CHECK_CLOSE(interface->Wzzzz_bz(), val, 1e-2);
}

BOOST_AUTO_TEST_CASE(Wxzxz_bz)
{
	double val = 0.0241759;
	BOOST_CHECK_CLOSE(interface->Wxzxz_bz(), val, 1e-2);
}

BOOST_AUTO_TEST_CASE(Wxxzz_bz)
{
	double val = -0.0016064;
	BOOST_CHECK_CLOSE(interface->Wxxzz_bz(), val, 1e-2);
}

BOOST_AUTO_TEST_CASE(Wzxzx_bz)
{
	double val = 0.0355543;
	BOOST_CHECK_CLOSE(interface->Wzxzx_bz(), val, 1e-2);
}

BOOST_AUTO_TEST_CASE(Wxzzx_bz)
{
	double val = -0.0283989;
	BOOST_CHECK_CLOSE(interface->Wxzzx_bz(), val, 1e-2);
}

BOOST_AUTO_TEST_CASE(Wyxyx_by)
{
	double val = 0.0134524;
	BOOST_CHECK_CLOSE(interface->Wyxyx_by(), val, 1e-2);
}

BOOST_AUTO_TEST_CASE(Wyzyz_by)
{
	double val = 0.00018947;
	BOOST_CHECK_CLOSE(interface->Wyzyz_by(), val, 1e-2);
}

BOOST_AUTO_TEST_CASE(wxx)
{
	double val = -0.0283989;
	BOOST_CHECK_CLOSE(interface->wxx(), val, 1e-2);
}

BOOST_AUTO_TEST_CASE(wzz)
{
	double val = 0.0134524;
	BOOST_CHECK_CLOSE(interface->wzz(), val, 1e-2);
}

BOOST_AUTO_TEST_CASE(wxz)
{
	double val = 0.00018947;
	BOOST_CHECK_CLOSE(interface->wxz(), val, 1e-2);
}

BOOST_AUTO_TEST_CASE(wyy)
{
	double val = -0.0283989;
	BOOST_CHECK_CLOSE(interface->wyy(), val, 1e-2);
}

BOOST_AUTO_TEST_CASE(wxy)
{
	double val = 0.0134524;
	BOOST_CHECK_CLOSE(interface->wxy(), val, 1e-2);
}

BOOST_AUTO_TEST_CASE(wyz)
{
	double val = 0.00018947;
	BOOST_CHECK_CLOSE(interface->wyz(), val, 1e-2);
}

BOOST_AUTO_TEST_SUITE_END()
