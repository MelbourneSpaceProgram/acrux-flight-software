####
# F prime CMakeLists.txt:
#
# SOURCE_FILES: combined list of source and autocoding diles
# MOD_DEPS: (optional) module dependencies
#
####
if(FPRIME_USE_STUBBED_DRIVERS)
    set(SOURCE_FILES
        "${CMAKE_CURRENT_LIST_DIR}/LinuxGpioDriverComponentAi.xml"
        "${CMAKE_CURRENT_LIST_DIR}/LinuxGpioDriverComponentImplCommon.cpp"
        "${CMAKE_CURRENT_LIST_DIR}/LinuxGpioDriverComponentImplStub.cpp"
    )
    register_fprime_module()
elseif(${CMAKE_SYSTEM_NAME} STREQUAL "freertos")
    set(SOURCE_FILES
        "${CMAKE_CURRENT_LIST_DIR}/STM32GpioDriverComponentAi.xml"
        "${CMAKE_CURRENT_LIST_DIR}/STM32GpioDriverComponentImplCommon.cpp"
        "${CMAKE_CURRENT_LIST_DIR}/STM32GpioDriverComponentImpl.cpp"
    )
    register_fprime_module()
else()
    message(STATUS "Cannot use ${CMAKE_CURRENT_LIST_DIR} with platform ${CMAKE_SYSTEM_NAME}. Skipping.")
endif()
set(MOD_DEPS
  NucleoH7_freeRTOS
)


