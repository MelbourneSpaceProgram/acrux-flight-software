// ======================================================================
// \title  STM32SerialDriverComponentImpl.cpp
// \author rawinza555
// \brief  cpp file for STM32SerialDriver component implementation class
//
// \copyright
// Copyright 2009-2015, by the California Institute of Technology.
// ALL RIGHTS RESERVED.  United States Government Sponsorship
// acknowledged.
//
// ======================================================================


#include <STM32Blink/STM32SerialDriver/STM32SerialDriverComponentImpl.hpp>
#include "Fw/Types/BasicTypes.hpp"

namespace STM32Blink {

  // ----------------------------------------------------------------------
  // Construction, initialization, and destruction
  // ----------------------------------------------------------------------

  STM32SerialDriverComponentImpl ::
    STM32SerialDriverComponentImpl(
        const char *const compName
    ) : STM32SerialDriverComponentBase(compName)
  {

  }

  void STM32SerialDriverComponentImpl ::
    init(
        const NATIVE_INT_TYPE instance
    )
  {
    STM32SerialDriverComponentBase::init(instance);
    MX_USART3_UART_Init();
  }

  STM32SerialDriverComponentImpl ::
    ~STM32SerialDriverComponentImpl(void)
  {

  }

  // ----------------------------------------------------------------------
  // Handler implementations for user-defined typed input ports
  // ----------------------------------------------------------------------

  void STM32SerialDriverComponentImpl ::
    write_handler(
        const NATIVE_INT_TYPE portNum,
        Fw::Buffer &fwBuffer
    )
  {
    // TODO
    HAL_UART_Transmit(&huart3, fwBuffer.getData(), fwBuffer.getSize(), HAL_MAX_DELAY);
  }

  void STM32SerialDriverComponentImpl ::
    readPoll_handler(
        const NATIVE_INT_TYPE portNum,
        Fw::Buffer &fwBuffer
    )
  {
    // TODO
    HAL_UART_Receive(&huart3, fwBuffer.getData(), fwBuffer.getSize(),150);
  }

  void STM32SerialDriverComponentImpl ::
    schedIn_handler(
        const NATIVE_INT_TYPE portNum,
        NATIVE_UINT_TYPE context
    )
  {
    // TODO
    Fw::Buffer rx;
      U8 rxData[50];

      HAL_UART_Receive(&huart3, rxData, 50,150);
  }

} // end namespace STM32Blink
