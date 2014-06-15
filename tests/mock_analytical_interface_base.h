#include "AnalyticalMisfitInterfaces.h"
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
}  // namespace
