#include "Tester.hpp"

TEST(Nominal, PowerOn) {
    Ref::Tester tester;
    tester.testerPowerOn();
}
TEST(Nominal, PowerOff) {
    Ref::Tester tester;
    tester.testerPowerOff();
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
