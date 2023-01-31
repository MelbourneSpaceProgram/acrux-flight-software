// ======================================================================
// \title  LedBlinker.cpp
// \author root
// \brief  cpp file for LedBlinker component implementation class
// ======================================================================


#include <Ref/LedBlinker/LedBlinker.hpp>
#include "Fw/Types/BasicTypes.hpp"
#include "Ref/NucleoH7_freeRTOS/Core/Inc/main.h"
#include "Ref/NucleoH7_freeRTOS/Drivers/CMSIS/Device/ST/STM32H7xx/Include/stm32h743xx.h"
#include "Ref/NucleoH7_freeRTOS/Drivers/STM32H7xx_HAL_Driver/Inc/stm32h7xx_hal_gpio.h"

namespace Ref {

  // ----------------------------------------------------------------------
  // Construction, initialization, and destruction
  // ----------------------------------------------------------------------

  LedBlinker ::
    LedBlinker(
        const char *const compName
    ) : LedBlinkerComponentBase(compName)
  {

  }

  void LedBlinker ::
    init(
        const NATIVE_INT_TYPE instance
    )
  {
    LedBlinkerComponentBase::init(instance);
  }

  LedBlinker ::
    ~LedBlinker()
  {

  }

  // ----------------------------------------------------------------------
  // Handler implementations for user-defined typed input ports
  // ----------------------------------------------------------------------

  void LedBlinker ::
    schedIn_handler(
        const NATIVE_INT_TYPE portNum,
        NATIVE_UINT_TYPE context
    )
  {
    HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_0);
  }

} // end namespace Ref
