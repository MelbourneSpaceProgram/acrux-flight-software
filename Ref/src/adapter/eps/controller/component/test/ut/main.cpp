#include "Tester.hpp"

TEST(Nominal, EPSInStateOut) {
    Ref::Tester tester;
    tester.testerEPSInStateOut();
}

TEST(Nominal, StateInConopsOut) {
    Ref::Tester tester;
    tester.testerStateInConopsOut();
}

TEST(Nominal, ConopsInStateOut) {
    Ref::Tester tester;
    tester.testerConopsInStateOut();
}


TEST(Nominal, ConopsInEPSOut) {
    Ref::Tester tester;
    tester.testerConopsInEPSOut();
}

TEST(Nominal, EPSInPwrStatusOut) {
    Ref::Tester tester;
    tester.testerEPSInPwrStatusOut();
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

