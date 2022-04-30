// ======================================================================
// \title  epsControllerComponent.cpp
// \author danny
// \brief  cpp file for epsControllerComponent component implementation class
//
// \copyright
// Copyright 2009-2015, by the California Institute of Technology.
// ALL RIGHTS RESERVED.  United States Government Sponsorship
// acknowledged.
//
// ======================================================================


#include <Ref/adapter/eps/controller/component/epsControllerComponent.hpp>
#include "Fw/Types/BasicTypes.hpp"

namespace Ref {

  // ----------------------------------------------------------------------
  // Construction, initialization, and destruction
  // ----------------------------------------------------------------------

  epsControllerComponent ::
    epsControllerComponent(
        const char *const compName
    ) : epsControllerComponentComponentBase(compName)
  {

  }

  void epsControllerComponent ::
    init(
        const NATIVE_INT_TYPE queueDepth,
        const NATIVE_INT_TYPE msgSize,
        const NATIVE_INT_TYPE instance
    )
  {
    epsControllerComponentComponentBase::init(queueDepth, msgSize, instance);
  }

  epsControllerComponent ::
    ~epsControllerComponent()
  {

  }

  // ----------------------------------------------------------------------
  // Handler implementations for user-defined typed input ports
  // ----------------------------------------------------------------------

  void epsControllerComponent ::
    conopsIn_handler(
        const NATIVE_INT_TYPE portNum,
        bool conopscommand
    )
  {
    // TODO
    this->batteryOut_out(portNum, conopscommand);
  }

  void epsControllerComponent ::
    stateIn_handler(
        const NATIVE_INT_TYPE portNum,
        F32 battery_level
    )
  {
    // TODO
    this->conopsOut_out(portNum,battery_level);
  }

  // ----------------------------------------------------------------------
  // Handler implementations for user-defined serial input ports
  // ----------------------------------------------------------------------

  void epsControllerComponent ::
    batterySerialIn_handler(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Fw::SerializeBufferBase &Buffer /*!< The serialization buffer*/
    )
  {
    // TODO
    this->stateSerialOut_out(portNum, Buffer);
  }

  // ----------------------------------------------------------------------
  // Command handler implementations
  // ----------------------------------------------------------------------

  void epsControllerComponent ::
    SEND_BATTERY_COMMAND_cmdHandler(
        const FwOpcodeType opCode,
        const U32 cmdSeq,
        Ref::InternalType c
    )
  {
    // TODO
    this->cmdResponse_out(opCode,cmdSeq,Fw::CmdResponse::OK);
  }

  void epsControllerComponent ::
    GET_STATE_cmdHandler(
        const FwOpcodeType opCode,
        const U32 cmdSeq,
        Ref::InternalType c
    )
  {
    // TODO
    this->cmdResponse_out(opCode,cmdSeq,Fw::CmdResponse::OK);
  }

  void epsControllerComponent ::
    SEND_DATA_CONOPS_cmdHandler(
        const FwOpcodeType opCode,
        const U32 cmdSeq,
        Ref::InternalType c
    )
  {
    // TODO
    this->cmdResponse_out(opCode,cmdSeq,Fw::CmdResponse::OK);
  }

} // end namespace Ref
