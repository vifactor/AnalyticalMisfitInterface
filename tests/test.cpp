#include "AnalyticalMisfitInterfaces.h"
#include <gtest/gtest.h>
#include <gmock/gmock.h>

namespace {

class MockAnalyticalMisfitInterfaceBase : public AnalyticalMisfitInterfaceBase {
public:
    MockAnalyticalMisfitInterfaceBase(double rho, double bx, double by, double bz,
	                             double Qx, double Qy, double Qz,
	                             double nu, double d) :
	                             AnalyticalMisfitInterfaceBase(rho, bx, by, bz,
	                             Qx, Qy, Qz,
	                             nu, d) {}

    //mocking pure virtual methods
    MOCK_CONST_METHOD0(wxx, double());
    MOCK_CONST_METHOD0(wyy, double());
    MOCK_CONST_METHOD0(wzz, double());
    MOCK_CONST_METHOD0(wxy, double());
    MOCK_CONST_METHOD0(wxz, double());
    MOCK_CONST_METHOD0(wyz, double());
};

// The fixture for testing class AnalyticalMisfitInterfaceBase.
class AnalyticalMisfitInterfaceBaseTest : public ::testing::Test {
 protected:

    AnalyticalMisfitInterfaceBaseTest() {
    // You can do set-up work for each test here.
  }

    virtual ~AnalyticalMisfitInterfaceBaseTest() {
    // You can do clean-up work that doesn't throw exceptions here.
  }

  // If the constructor and destructor are not enough for setting up
  // and cleaning up each test, you can define the following methods:

    virtual void SetUp() {
    // Code here will be called immediately after the constructor (right
    // before each test).
        /*dummy parameters used in Mathematica file*/
	    double rho = 0.1;
		double bx = 1.0;
		double by = 0.0;
		double bz = 0.0;
		double Qx = 2.2;
		double Qy = 3.3;
		double Qz = 4.4;
		
		double nu = 1.0 / 3;
		double d = 12;
		double z = 2;

		/**values obtained in the Mathematica*/
		Wxxxx_bx = 0.00622437;
		Wzzzz_bx = 0.00158983;
		Wxzxz_bx = 0.0056553;
		Wxxzz_bx = -0.00314146;
		Wzxzx_bx = 0.00701169;
		Wxzzx_bx = -0.00591633;
		Wxxxx_bz = 0;
		Wzzzz_bz = 0;
		Wxzxz_bz = 0;
		Wxxzz_bz = 0;
		Wzxzx_bz = 0;
		Wxzzx_bz = 0;
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

// Tests Wijkl methods
TEST_F(AnalyticalMisfitInterfaceBaseTest, Wxxxx_bx) 
{
    EXPECT_NEAR(interface->Wxxxx_bx(), Wxxxx_bx, 1e-3);
}

TEST_F(AnalyticalMisfitInterfaceBaseTest, Wzzzz_bx)
{
	EXPECT_NEAR(interface->Wzzzz_bx(), Wzzzz_bx, 1e-2);
}

TEST_F(AnalyticalMisfitInterfaceBaseTest, Wxzxz_bx)
{
	EXPECT_NEAR(interface->Wxzxz_bx(), Wxzxz_bx, 1e-2);
}

TEST_F(AnalyticalMisfitInterfaceBaseTest, Wxxzz_bx)
{
	EXPECT_NEAR(interface->Wxxzz_bx(), Wxxzz_bx, 1e-2);
}

TEST_F(AnalyticalMisfitInterfaceBaseTest, Wzxzx_bx)
{
	EXPECT_NEAR(interface->Wzxzx_bx(), Wzxzx_bx, 1e-2);
}

TEST_F(AnalyticalMisfitInterfaceBaseTest, Wxzzx_bx)
{
	EXPECT_NEAR(interface->Wxzzx_bx(), Wxzzx_bx, 1e-2);
}

TEST_F(AnalyticalMisfitInterfaceBaseTest, Wxxxx_bz)
{
	EXPECT_NEAR(interface->Wxxxx_bz(), Wxxxx_bz, 1e-2);
}

TEST_F(AnalyticalMisfitInterfaceBaseTest, Wzzzz_bz)
{
	EXPECT_NEAR(interface->Wzzzz_bz(), Wzzzz_bz, 1e-2);
}

TEST_F(AnalyticalMisfitInterfaceBaseTest, Wxzxz_bz)
{
	EXPECT_NEAR(interface->Wxzxz_bz(), Wxzxz_bz, 1e-2);
}

TEST_F(AnalyticalMisfitInterfaceBaseTest, Wxxzz_bz)
{
	EXPECT_NEAR(interface->Wxxzz_bz(), Wxxzz_bz, 1e-2);
}

TEST_F(AnalyticalMisfitInterfaceBaseTest, Wzxzx_bz)
{
	EXPECT_NEAR(interface->Wzxzx_bz(), Wzxzx_bz, 1e-2);
}

TEST_F(AnalyticalMisfitInterfaceBaseTest, Wxzzx_bz)
{
	EXPECT_NEAR(interface->Wxzzx_bz(), Wxzzx_bz, 1e-2);
}

TEST_F(AnalyticalMisfitInterfaceBaseTest, Wyxyx_by)
{
	EXPECT_NEAR(interface->Wyxyx_by(), Wyxyx_by, 1e-2);
}

TEST_F(AnalyticalMisfitInterfaceBaseTest, Wyzyz_by)
{
	EXPECT_NEAR(interface->Wyzyz_by(), Wyzyz_by, 1e-2);
}

}  // namespace

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
