// ======================================================================
// \title  LedBlinker.cpp
// \author root
// \brief  cpp file for LedBlinker component implementation class
// ======================================================================


#include <Ref/LedBlinker/LedBlinker.hpp>
#include "Fw/Types/BasicTypes.hpp"
#include "Os/stm32-bsp/Core/Inc/main.h"

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
    HAL_GPIO_TogglePin(LD2_GPIO_Port, LD2_Pin);
  }

} // end namespace Ref
