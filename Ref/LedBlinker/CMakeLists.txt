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
include_directories("${FPRIME_FRAMEWORK_PATH}/Ref/NucleoH7_freeRTOS/Middlewares/Third_Party/FreeRTOS/Source/include"
                    "${FPRIME_FRAMEWORK_PATH}/Ref/NucleoH7_freeRTOS/Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F"
                    "${FPRIME_FRAMEWORK_PATH}/Ref/NucleoH7_freeRTOS/Drivers/CMSIS/Device/ST/STM32H7xx/Include"
                    "${FPRIME_FRAMEWORK_PATH}/Ref/NucleoH7_freeRTOS/Drivers/STM32H7xx_HAL_Driver/Inc"
                    "${FPRIME_FRAMEWORK_PATH}/Ref/NucleoH7_freeRTOS/Drivers/CMSIS/Include/"
                    "${FPRIME_FRAMEWORK_PATH}/Ref/NucleoH7_freeRTOS/Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2"
                    "${FPRIME_FRAMEWORK_PATH}/Ref/NucleoH7_freeRTOS/Core/Inc"
                    "${FPRIME_FRAMEWORK_PATH}/Ref/NucleoH7_freeRTOS/Drivers/STM32H7xx_HAL_Driver/Inc/Legacy/"
                    )
register_fprime_module()
