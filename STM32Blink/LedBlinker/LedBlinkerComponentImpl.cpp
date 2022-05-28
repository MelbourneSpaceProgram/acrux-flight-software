// ======================================================================
// \title  LedBlinkerComponentImpl.cpp
// \author rawinza555
// \brief  cpp file for LedBlinker component implementation class
//
// \copyright
// Copyright 2009-2015, by the California Institute of Technology.
// ALL RIGHTS RESERVED.  United States Government Sponsorship
// acknowledged.
//
// ======================================================================


#include <STM32Blink/LedBlinker/LedBlinkerComponentImpl.hpp>
#include "Fw/Types/BasicTypes.hpp"

namespace STM32Blink {

  // ----------------------------------------------------------------------
  // Construction, initialization, and destruction
  // ----------------------------------------------------------------------

  LedBlinkerComponentImpl ::
    LedBlinkerComponentImpl(
        const char *const compName
    ) : LedBlinkerComponentBase(compName)
  {

  }

  void LedBlinkerComponentImpl ::
    init(
        const NATIVE_INT_TYPE instance
    )
  {
    LedBlinkerComponentBase::init(instance);
  }

  LedBlinkerComponentImpl ::
    ~LedBlinkerComponentImpl(void)
  {

  }

  // ----------------------------------------------------------------------
  // Handler implementations for user-defined typed input ports
  // ----------------------------------------------------------------------

  void LedBlinkerComponentImpl ::
    schedIn_handler(
        const NATIVE_INT_TYPE portNum,
        NATIVE_UINT_TYPE context
    )
  {
    bool light = true;
    this->gpioWrite_out(0,light);
    light = !light;
  }

} // end namespace STM32Blink
