// ======================================================================
// \title  STM32SerialDriverComponentImpl.hpp
// \author rawinza555
// \brief  hpp file for STM32SerialDriver component implementation class
//
// \copyright
// Copyright 2009-2015, by the California Institute of Technology.
// ALL RIGHTS RESERVED.  United States Government Sponsorship
// acknowledged.
//
// ======================================================================

#ifndef STM32SerialDriver_HPP
#define STM32SerialDriver_HPP

#include "STM32Blink/STM32SerialDriver/STM32SerialDriverComponentAc.hpp"
#include "NucleoH7_freeRTOS/Core/Inc/usart.h"
namespace STM32Blink {

  class STM32SerialDriverComponentImpl :
    public STM32SerialDriverComponentBase
  {

    public:

      // ----------------------------------------------------------------------
      // Construction, initialization, and destruction
      // ----------------------------------------------------------------------

      //! Construct object STM32SerialDriver
      //!
      STM32SerialDriverComponentImpl(
          const char *const compName /*!< The component name*/
      );

      //! Initialize object STM32SerialDriver
      //!
      void init(
          const NATIVE_INT_TYPE instance = 0 /*!< The instance number*/
      );

      //! Destroy object STM32SerialDriver
      //!
      ~STM32SerialDriverComponentImpl(void);

    PRIVATE:

      // ----------------------------------------------------------------------
      // Handler implementations for user-defined typed input ports
      // ----------------------------------------------------------------------

      //! Handler implementation for write
      //!
      void write_handler(
          const NATIVE_INT_TYPE portNum, /*!< The port number*/
          Fw::Buffer &fwBuffer 
      );

      //! Handler implementation for readPoll
      //!
      void readPoll_handler(
          const NATIVE_INT_TYPE portNum, /*!< The port number*/
          Fw::Buffer &fwBuffer 
      );

      //! Handler implementation for schedIn
      //!
      void schedIn_handler(
          const NATIVE_INT_TYPE portNum, /*!< The port number*/
          NATIVE_UINT_TYPE context /*!< The call order*/
      );


    };

} // end namespace STM32Blink

#endif
