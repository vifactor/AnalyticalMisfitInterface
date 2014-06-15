#include "mock_analytical_interface_base.h"

namespace {

// The fixture for testing class AnalyticalMisfitInterfaceBase when z < d
class AnalyticalMisfitInterfaceBaseAboveBzTest : public ::testing::Test {
 protected:

    AnalyticalMisfitInterfaceBaseAboveBzTest() {
    // You can do set-up work for each test here.
  }

    virtual ~AnalyticalMisfitInterfaceBaseAboveBzTest() {
    // You can do clean-up work that doesn't throw exceptions here.
  }

  // If the constructor and destructor are not enough for setting up
  // and cleaning up each test, you can define the following methods:

    virtual void SetUp() {
    // Code here will be called immediately after the constructor (right
    // before each test).
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

		/**values obtained in the Mathematica*/
		Wxxxx_bx = 0.0;
		Wzzzz_bx = 0.0;
		Wxzxz_bx = 0.0;
		Wxxzz_bx = 0;
		Wzxzx_bx = 0;
		Wxzzx_bx = 0;

		Wxxxx_bz = 0.00299662;
		Wzzzz_bz = 0.000867747;
		Wxzxz_bz = 0.0241757;
		Wxxzz_bz = -0.0016064;
		Wzxzx_bz = 0.0355546;
		Wxzzx_bz = -0.0283989;

		Wyxyx_by = 0;
		Wyzyz_by = 0;

		interface = new MockAnalyticalMisfitInterfaceBase(rho, bx, by, bz, Qx, Qy,
				Qz, nu, d);
		interface->init(z);
  }

    virtual void TearDown() {
    // Code here will be called immediately after each test (right
    // before the destructor).
        if(interface) delete interface;
        interface = NULL;
  }

    // Objects declared here can be used by all tests 
    // in the test case for AnalyticalMisfitInterfaceBase
    double Wxxxx_bx, Wzzzz_bx, Wxzxz_bx, Wxxzz_bx, Wzxzx_bx, Wxzzx_bx;
    double Wxxxx_bz, Wzzzz_bz, Wxzxz_bz, Wxxzz_bz, Wzxzx_bz, Wxzzx_bz;
    double Wyxyx_by, Wyzyz_by;

    MockAnalyticalMisfitInterfaceBase * interface;
};

// Tests Wijkl methods when z < d
TEST_F(AnalyticalMisfitInterfaceBaseAboveBzTest, Wxxxx_bx) 
{
    EXPECT_NEAR(interface->Wxxxx_bx(), Wxxxx_bx, 1e-3);
}

TEST_F(AnalyticalMisfitInterfaceBaseAboveBzTest, Wzzzz_bx)
{
	EXPECT_NEAR(interface->Wzzzz_bx(), Wzzzz_bx, 1e-2);
}

TEST_F(AnalyticalMisfitInterfaceBaseAboveBzTest, Wxzxz_bx)
{
	EXPECT_NEAR(interface->Wxzxz_bx(), Wxzxz_bx, 1e-2);
}

TEST_F(AnalyticalMisfitInterfaceBaseAboveBzTest, Wxxzz_bx)
{
	EXPECT_NEAR(interface->Wxxzz_bx(), Wxxzz_bx, 1e-2);
}

TEST_F(AnalyticalMisfitInterfaceBaseAboveBzTest, Wzxzx_bx)
{
	EXPECT_NEAR(interface->Wzxzx_bx(), Wzxzx_bx, 1e-2);
}

TEST_F(AnalyticalMisfitInterfaceBaseAboveBzTest, Wxzzx_bx)
{
	EXPECT_NEAR(interface->Wxzzx_bx(), Wxzzx_bx, 1e-2);
}

TEST_F(AnalyticalMisfitInterfaceBaseAboveBzTest, Wxxxx_bz)
{
	EXPECT_NEAR(interface->Wxxxx_bz(), Wxxxx_bz, 1e-2);
}

TEST_F(AnalyticalMisfitInterfaceBaseAboveBzTest, Wzzzz_bz)
{
	EXPECT_NEAR(interface->Wzzzz_bz(), Wzzzz_bz, 1e-2);
}

TEST_F(AnalyticalMisfitInterfaceBaseAboveBzTest, Wxzxz_bz)
{
	EXPECT_NEAR(interface->Wxzxz_bz(), Wxzxz_bz, 1e-2);
}

TEST_F(AnalyticalMisfitInterfaceBaseAboveBzTest, Wxxzz_bz)
{
	EXPECT_NEAR(interface->Wxxzz_bz(), Wxxzz_bz, 1e-2);
}

TEST_F(AnalyticalMisfitInterfaceBaseAboveBzTest, Wzxzx_bz)
{
	EXPECT_NEAR(interface->Wzxzx_bz(), Wzxzx_bz, 1e-2);
}

TEST_F(AnalyticalMisfitInterfaceBaseAboveBzTest, Wxzzx_bz)
{
	EXPECT_NEAR(interface->Wxzzx_bz(), Wxzzx_bz, 1e-2);
}

TEST_F(AnalyticalMisfitInterfaceBaseAboveBzTest, Wyxyx_by)
{
	EXPECT_NEAR(interface->Wyxyx_by(), Wyxyx_by, 1e-2);
}

TEST_F(AnalyticalMisfitInterfaceBaseAboveBzTest, Wyzyz_by)
{
	EXPECT_NEAR(interface->Wyzyz_by(), Wyzyz_by, 1e-2);
}

}  // namespace
