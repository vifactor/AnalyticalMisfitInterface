#include "AnalyticalMisfitInterfaces.h"
#include <gtest/gtest.h>

namespace {

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
		double phi = M_PI / 9;
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
		wxx = 0.195903;
		wyy = 0.173499;
		wzz = 0.150516;
		wxy = 0.0187993;
		wxz = -0.175359;
		wyz = -0.263038;

		interface = new AnalyticalMisfitInterfaceCub(rho, bx, by, bz, Qx, Qy,
				Qz, phi, nu, d);
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
    double wxx, wyy, wzz, wxy, wxz, wyz;

    AnalyticalMisfitInterfaceCub * interface;
};

// Tests that the Foo::Bar() method does Abc.
TEST_F(AnalyticalMisfitInterfaceBaseTest, DummyTest) 
{
  EXPECT_EQ(1 + 1, 2);
}

}  // namespace

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
