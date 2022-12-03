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
include_directories("${CMAKE_CURRENT_LIST_DIR}/stm32-bsp/Middlewares/Third_Party/FreeRTOS/Source/include"
"${CMAKE_CURRENT_LIST_DIR}/stm32-bsp/Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F"
"${CMAKE_CURRENT_LIST_DIR}/stm32-bsp/Drivers/CMSIS/Device/ST/STM32H7xx/Include"
"${CMAKE_CURRENT_LIST_DIR}/stm32-bsp/Drivers/STM32H7xx_HAL_Driver/Inc"
"${CMAKE_CURRENT_LIST_DIR}/stm32-bsp/Drivers/CMSIS/Include/"
"${CMAKE_CURRENT_LIST_DIR}/stm32-bsp/Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2"
"${CMAKE_CURRENT_LIST_DIR}/stm32-bsp/Core/Inc"					
)
register_fprime_module()
