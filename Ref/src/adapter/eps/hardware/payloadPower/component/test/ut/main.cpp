#include "Tester.hpp"

TEST(Nominal, MainTest) {
    Ref::Tester tester;
    tester.testMainTest();
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
