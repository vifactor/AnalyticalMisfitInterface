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
  }

  virtual void TearDown() {
    // Code here will be called immediately after each test (right
    // before the destructor).
  }

  // Objects declared here can be used by all tests in the test case for Foo.
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
