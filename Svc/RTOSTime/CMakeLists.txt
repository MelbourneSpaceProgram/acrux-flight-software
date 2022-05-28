####
# F prime CMakeLists.txt:
#
# SOURCE_FILES: combined list of source and autocoding diles
# MOD_DEPS: (optional) module dependencies
#
# Note: using PROJECT_NAME as EXECUTABLE_NAME
####
set(SOURCE_FILES
  "${CMAKE_CURRENT_LIST_DIR}/RTOSTime.fpp"
  "${CMAKE_CURRENT_LIST_DIR}/RTOSTimeImpl.cpp"
)


# if(${CMAKE_SYSTEM_NAME} STREQUAL "freertos")
#     get_module_name(${CMAKE_CURRENT_LIST_DIR})
#     add_stm32_dependency("${MODULE_NAME}")
# endif()

register_fprime_module()
### UTs ###
set(UT_SOURCE_FILES
  "${FPRIME_FRAMEWORK_PATH}/Svc/Time/TimeComponentAi.xml"
  "${CMAKE_CURRENT_LIST_DIR}/test/ut/Tester.cpp"
  "${CMAKE_CURRENT_LIST_DIR}/test/ut/Main.cpp"
)
register_fprime_ut()
