// ======================================================================
// \title  LinuxGpioDriverImpl.hpp
// \author tcanham
// \brief  hpp file for LinuxGpioDriver component implementation class
//
// \copyright
// Copyright 2009-2015, by the California Institute of Technology.
// ALL RIGHTS RESERVED.  United States Government Sponsorship
// acknowledged.
//
// ======================================================================

#ifndef STM32GpioDriver_HPP
#define STM32GpioDriver_HPP

#include "STM32Blink/STM32GpioDriver/STM32GpioDriverComponentAc.hpp"
#include <Os/Task.hpp>
#include "NucleoH7_freeRTOS/Core/Inc/gpio.h"

namespace STM32Blink {

  class STM32GpioDriverComponentImpl :
    public STM32GpioDriverComponentBase
  {

    public:

      // ----------------------------------------------------------------------
      // Construction, initialization, and destruction
      // ----------------------------------------------------------------------

      //! Construct object LinuxGpioDriver
      //!
      STM32GpioDriverComponentImpl(
          const char *const compName /*!< The component name*/
      );

      //! Initialize object LinuxGpioDriver
      //!
      void init(
          const NATIVE_INT_TYPE instance = 0 /*!< The instance number*/
      );

      //! Destroy object LinuxGpioDriver
      //!
      ~STM32GpioDriverComponentImpl(void);

      //! Start interrupt task

      //! configure GPIO


      //! open GPIO
      bool open(void);


    PRIVATE:

      // ----------------------------------------------------------------------
      // Handler implementations for user-defined typed input ports
      // ----------------------------------------------------------------------

      //! Handler implementation for gpioRead
      //!
      void gpioRead_handler(
          const NATIVE_INT_TYPE portNum, /*!< The port number*/
          bool &state
      );

      //! Handler implementation for gpioWrite
      //!
      void gpioWrite_handler(
          const NATIVE_INT_TYPE portNum, /*!< The port number*/
          bool state
      );

      //! keep GPIO ID
      

    };

} // end namespace Drv

#endif
