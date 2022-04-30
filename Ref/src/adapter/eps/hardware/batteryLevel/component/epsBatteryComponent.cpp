// ======================================================================
// \title  epsBatteryComponent.cpp
// \author danny
// \brief  cpp file for epsBatteryComponent component implementation class
//
// \copyright
// Copyright 2009-2015, by the California Institute of Technology.
// ALL RIGHTS RESERVED.  United States Government Sponsorship
// acknowledged.
//
// ======================================================================


#include <Ref/adapter/eps/hardware/batteryLevel/component/epsBatteryComponent.hpp>
#include "Fw/Types/BasicTypes.hpp"

namespace Ref {

  // ----------------------------------------------------------------------
  // Construction, initialization, and destruction
  // ----------------------------------------------------------------------

  epsBatteryComponent ::
    epsBatteryComponent(
        const char *const compName
    ) : epsBatteryComponentComponentBase(compName)
  {

  }

  void epsBatteryComponent ::
    init(
        const NATIVE_INT_TYPE queueDepth,
        const NATIVE_INT_TYPE instance
    )
  {
    epsBatteryComponentComponentBase::init(queueDepth, instance);
  }

  epsBatteryComponent ::
    ~epsBatteryComponent()
  {

  }

  // ----------------------------------------------------------------------
  // Handler implementations for user-defined typed input ports
  // ----------------------------------------------------------------------

  Ref::ReturnType epsBatteryComponent ::
    epsBatLogicIn_handler(
        const NATIVE_INT_TYPE portNum,
        F32 battery_level
    )
  {
    // TODO return
    this->cmdResponse_out(portNum, battery_level);
  }

  // ----------------------------------------------------------------------
  // Command handler implementations
  // ----------------------------------------------------------------------

  void epsBatteryComponent ::
    SEND_BATTERY_LEVEL_cmdHandler(
        const FwOpcodeType opCode,
        const U32 cmdSeq,
        F32 battery
    )
  {
    // TODO
    this->cmdResponse_out(opCode,cmdSeq,Fw::CmdResponse::OK);
  }

} // end namespace Ref
