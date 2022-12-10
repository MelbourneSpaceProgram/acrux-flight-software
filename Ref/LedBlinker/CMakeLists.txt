####
# F prime CMakeLists.txt:
#
# SOURCE_FILES: combined list of source and autocoding diles
# MOD_DEPS: (optional) module dependencies
#
####
set(SOURCE_FILES
  "${CMAKE_CURRENT_LIST_DIR}/LedBlinker.fpp"
  "${CMAKE_CURRENT_LIST_DIR}/LedBlinker.cpp"
)
include_directories(
"${FPRIME_FRAMEWORK_PATH}/Os/stm32-bsp/Core/Inc"					
"${FPRIME_FRAMEWORK_PATH}/Os/stm32-bsp/Drivers/CMSIS/Device/ST/STM32H7xx/Include"
"${FPRIME_FRAMEWORK_PATH}/Os/stm32-bsp/Drivers/CMSIS/Include/"
"${FPRIME_FRAMEWORK_PATH}/Os/stm32-bsp/Drivers/STM32H7xx_HAL_Driver/Inc"
"${FPRIME_FRAMEWORK_PATH}/Os/stm32-bsp/Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2"
"${FPRIME_FRAMEWORK_PATH}/Os/stm32-bsp/Middlewares/Third_Party/FreeRTOS/Source/include"
"${FPRIME_FRAMEWORK_PATH}/Os/stm32-bsp/Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F"
)
register_fprime_module()
