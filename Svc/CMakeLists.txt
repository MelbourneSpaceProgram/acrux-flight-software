# Module subdirectories

# Ports
add_fprime_subdirectory("${CMAKE_CURRENT_LIST_DIR}/Cycle/")
add_fprime_subdirectory("${CMAKE_CURRENT_LIST_DIR}/Fatal/")
add_fprime_subdirectory("${CMAKE_CURRENT_LIST_DIR}/Ping/")
add_fprime_subdirectory("${CMAKE_CURRENT_LIST_DIR}/PolyIf/")
add_fprime_subdirectory("${CMAKE_CURRENT_LIST_DIR}/Sched/")
add_fprime_subdirectory("${CMAKE_CURRENT_LIST_DIR}/Seq/")
add_fprime_subdirectory("${CMAKE_CURRENT_LIST_DIR}/WatchDog/")

# Components
add_fprime_subdirectory("${CMAKE_CURRENT_LIST_DIR}/ActiveLogger/")
add_fprime_subdirectory("${CMAKE_CURRENT_LIST_DIR}/ActiveRateGroup/")
add_fprime_subdirectory("${CMAKE_CURRENT_LIST_DIR}/AssertFatalAdapter/")
add_fprime_subdirectory("${CMAKE_CURRENT_LIST_DIR}/BufferManager/")
add_fprime_subdirectory("${CMAKE_CURRENT_LIST_DIR}/BufferLogger/")
add_fprime_subdirectory("${CMAKE_CURRENT_LIST_DIR}/ComLogger/")
add_fprime_subdirectory("${CMAKE_CURRENT_LIST_DIR}/ComSplitter/")
add_fprime_subdirectory("${CMAKE_CURRENT_LIST_DIR}/CmdDispatcher/")
add_fprime_subdirectory("${CMAKE_CURRENT_LIST_DIR}/CmdSequencer/")
add_fprime_subdirectory("${CMAKE_CURRENT_LIST_DIR}/Deframer/")
add_fprime_subdirectory("${CMAKE_CURRENT_LIST_DIR}/FatalHandler/")
add_fprime_subdirectory("${CMAKE_CURRENT_LIST_DIR}/FileDownlinkPorts/")
add_fprime_subdirectory("${CMAKE_CURRENT_LIST_DIR}/FileDownlink/")
add_fprime_subdirectory("${CMAKE_CURRENT_LIST_DIR}/FileManager/")
add_fprime_subdirectory("${CMAKE_CURRENT_LIST_DIR}/FileUplink/")
add_fprime_subdirectory("${CMAKE_CURRENT_LIST_DIR}/GenericHub/")
add_fprime_subdirectory("${CMAKE_CURRENT_LIST_DIR}/GenericRepeater/")
add_fprime_subdirectory("${CMAKE_CURRENT_LIST_DIR}/GroundInterface/")
add_fprime_subdirectory("${CMAKE_CURRENT_LIST_DIR}/Framer/")
add_fprime_subdirectory("${CMAKE_CURRENT_LIST_DIR}/FramingProtocol/")
add_fprime_subdirectory("${CMAKE_CURRENT_LIST_DIR}/Health/")
add_fprime_subdirectory("${CMAKE_CURRENT_LIST_DIR}/PolyDb/")
add_fprime_subdirectory("${CMAKE_CURRENT_LIST_DIR}/PrmDb/")
add_fprime_subdirectory("${CMAKE_CURRENT_LIST_DIR}/RateGroupDriver/")
add_fprime_subdirectory("${CMAKE_CURRENT_LIST_DIR}/StaticMemory/")
add_fprime_subdirectory("${CMAKE_CURRENT_LIST_DIR}/Time/")
add_fprime_subdirectory("${CMAKE_CURRENT_LIST_DIR}/TlmChan/")
add_fprime_subdirectory("${CMAKE_CURRENT_LIST_DIR}/TlmPacketizer/")
add_fprime_subdirectory("${CMAKE_CURRENT_LIST_DIR}/SystemResources/")

# Text logger components included by default, 
# but can be disabled if FW_ENABLE_TEXT_LOGGING=0 is desired.
if (FPRIME_ENABLE_TEXT_LOGGERS)
	add_fprime_subdirectory("${CMAKE_CURRENT_LIST_DIR}/PassiveConsoleTextLogger/")
	add_fprime_subdirectory("${CMAKE_CURRENT_LIST_DIR}/ActiveTextLogger/")
endif()

if(${CMAKE_SYSTEM_NAME} STREQUAL "Linux" OR ${CMAKE_SYSTEM_NAME} STREQUAL "Darwin")
	add_fprime_subdirectory("${CMAKE_CURRENT_LIST_DIR}/LinuxTime/")
	# add_fprime_subdirectory("${CMAKE_CURRENT_LIST_DIR}/LinuxTimer/")
endif()

if(${CMAKE_SYSTEM_NAME} STREQUAL "FreeRTOS-stm")
	include_directories("${FPRIME_FRAMEWORK_PATH}/Ref/NucleoH7_freeRTOS/Middlewares/Third_Party/FreeRTOS/Source/include"
	"${FPRIME_FRAMEWORK_PATH}/Ref/NucleoH7_freeRTOS/Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F"
	"${FPRIME_FRAMEWORK_PATH}/Ref/NucleoH7_freeRTOS/Drivers/CMSIS/Device/ST/STM32H7xx/Include"
	"${FPRIME_FRAMEWORK_PATH}/Ref/NucleoH7_freeRTOS/Drivers/STM32H7xx_HAL_Driver/Inc"
	"${FPRIME_FRAMEWORK_PATH}/Ref/NucleoH7_freeRTOS/Drivers/CMSIS/Include/"
	"${FPRIME_FRAMEWORK_PATH}/Ref/NucleoH7_freeRTOS/Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2"
	"${FPRIME_FRAMEWORK_PATH}/Ref/NucleoH7_freeRTOS/Core/Inc"
	"${FPRIME_FRAMEWORK_PATH}/Ref/NucleoH7_freeRTOS/Drivers/STM32H7xx_HAL_Driver/Inc/Legacy/"
	)

	add_fprime_subdirectory("${CMAKE_CURRENT_LIST_DIR}/LinuxTime/")
	# add_fprime_subdirectory("${CMAKE_CURRENT_LIST_DIR}/LinuxTimer/")
endif()

