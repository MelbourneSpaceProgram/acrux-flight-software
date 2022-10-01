add_definitions(-DTGT_OS_TYPE_FREERTOS)

# If required, specify compiler flags here

if (NOT DEFINED FPRIME_USE_BAREMETAL_SCHEDULER)
   set(FPRIME_USE_BAREMETAL_SCHEDULER OFF)
   message(STATUS "Requiring thread library")
   FIND_PACKAGE ( Threads REQUIRED )
endif()
set(FPRIME_USE_POSIX OFF)

# Specify a directory containing the "StandardTypes.hpp" headers, as well
# as other system headers. Other global headers can be placed here.
# Note: Typically, the Linux directory is a good default, as it grabs
# standard types from <stdint.h>. 
include_directories(SYSTEM "${FPRIME_FRAMEWORK_PATH}/Fw/Types/FreeRTOS")
