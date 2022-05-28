####
# Template toolchain.cmake.template: 
#
# This file acts as a template for the cmake toolchains. These toolchain files
# specify what tools to use when performing the build as part of CMake. This
# file can be used to quickly set one up.
#
# Follow all the steps in this template to create a toolchain file. Ensure
# to remove the template-failsafe (step 1) and fill in all <SOMETHING> tags.
#
# **Note:** this file should follow the standard CMake toolchain format. See:
# https://cmake.org/cmake/help/v3.12/manual/cmake-toolchains.7.html
#
# **Note:** If the user desires to set compile flags, or F prime specific build options, a platform
#           file should be constructed. See: [platform.md](platform.md)
#
# ### Filling In CMake Toolchain by Example ###
#
# CMake Toolchain files, at the most basic, define the system name and C and C++ compilers. In
# addition, a find path can be set to search for other utilities. This example will walk through
# setting these values using the appropriate variables. These can be specified using the following
# CMake setting flags:
#
# ```
# CMAKE_SYSTEM_NAME "RaspberryPI"
# # specify the cross compiler
# set(CMAKE_C_COMPILER "/opt/rpi/bin/arm-linux-gnueabihf-gcc")
# set(CMAKE_CXX_COMPILER "/opt/rpi/bin/arm-linux-gnueabihf-g++")
# # where is the target environment
# set(CMAKE_FIND_ROOT_PATH  "/opt/rpi")
# ```
#
# **Note:** if copying the template, delete the message with FATAL_ERROR line. This is a fail-safe
#           to prevent a raw-copy from being treated as a valid toolchain file. 
####

## STEP 1: DELETE the following fail-safe line

## STEP 2: Specify the target system's name. i.e. raspberry-pi-3
set(CMAKE_SYSTEM_NAME "freertos")
set(CMAKE_SYSTEM_PROCESSOR arm)
set(MCU_MODEL STM32H743xx)
set(CMAKE_CROSSCOMPILING 1)
set(CMAKE_C_COMPILER_WORKS 1)
set(CMAKE_CXX_COMPILER_WORKS 1)
set(CMAKE_ASM_COMPILER_WORKS 1)
set(CMAKE_TRY_COMPILE_TARGET_TYPE "STATIC_LIBRARY")

SET(STM32_BSP_PATH "${CMAKE_CURRENT_LIST_DIR}/../../NucleoH7_freeRTOS" CACHE PATH "Path to STM32 BSP")

set(TOOLCHAIN_PREFIX arm-none-eabi-)
# STEP 3: Specify the path to C and CXX cross compilers
set(CMAKE_C_COMPILER ${TOOLCHAIN_PREFIX}gcc)
set(CMAKE_ASM_COMPILER ${CMAKE_C_COMPILER})
set(CMAKE_CXX_COMPILER ${TOOLCHAIN_PREFIX}g++)
set(CMAKE_LINKER ${TOOLCHAIN_PREFIX}ld)
set(CMAKE_OBJCOPY ${TOOLCHAIN_PREFIX}objcopy)
set(CMAKE_SIZE ${TOOLCHAIN_PREFIX}size)

set(MCU_LINKER_SCRIPT ${STM32_BSP_PATH}/STM32H743ZITx_FLASH.ld)

set(CPU_PARAMETERS
    -mcpu=cortex-m7
    -mthumb
    -mfpu=fpv5-sp-d16
    -mfloat-abi=hard)
set(STM32_LD  "-T${MCU_LINKER_SCRIPT} \
    -mcpu=cortex-m7 \
    -mthumb \
    -mfpu=fpv5-sp-d16 \
    -mfloat-abi=hard \
    -Wl,-Map=${CMAKE_PROJECT_NAME}.map \
    --specs=nosys.specs \
    -Wl,--start-group \
    -lc \
    -lm \
    -lstdc++ \
    -lsupc++ \
    -Wl,--end-group") 
set(COMPILER_COMMON_FLAGS
    "-fdata-sections -ffunction-sections \
    -DUSE_HAL_DRIVER \
    -DTGT_OS_TYPE_FREERTOS \
    -mcpu=cortex-m7 \
    -mthumb \
    -mfpu=fpv5-sp-d16 \
    -mfloat-abi=hard \
    -DSTM32H743xx \
    --specs=nano.specs -Wl,--gc-sections"
    )    
set(CMAKE_C_FLAGS
    "${COMPILER_COMMON_FLAGS} \
    -std=c99"
    )

# POSIX C Source required to enable strnlen on baremetal
set(CMAKE_CXX_FLAGS
    "${COMPILER_COMMON_FLAGS} \
    -std=c++14 \
    -fno-rtti \
    -fno-exceptions \
    -fno-threadsafe-statics \
    -D_POSIX_C_SOURCE=200809L"
    )
set(CMAKE_EXE_LINKER_FLAGS ${STM32_LD})


# STEP 4: Specify paths to root of toolchain package, for searching for
#         libraries, executables, etc.
set(CMAKE_FIND_ROOT_PATH  "/home/rawinza555/gcc-arm-none-eabi-10.3-2021.07/")

# DO NOT EDIT: F prime searches the host for programs, not the cross
# compile toolchain
set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
# DO NOT EDIT: F prime searches for libs, includes, and packages in the
# toolchain when cross-compiling.
set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_PACKAGE ONLY)