set(UT_SOURCE_FILES
  "${CMAKE_CURRENT_LIST_DIR}/epsControllerComponent.fpp"
  "${CMAKE_CURRENT_LIST_DIR}/test/ut/Tester.cpp"
  "${CMAKE_CURRENT_LIST_DIR}/test/ut/main.cpp"
)
set(UT_MOD_DEPS STest)
register_fprime_ut()
