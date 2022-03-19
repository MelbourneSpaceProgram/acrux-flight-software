// ======================================================================
// \title  EPSController.cpp
// \author phoebebear
// \brief  cpp file for EPSController component implementation class
//
// \copyright
// Copyright 2009-2015, by the California Institute of Technology.
// ALL RIGHTS RESERVED.  United States Government Sponsorship
// acknowledged.
//
// ======================================================================


#include <Ref/EPSController/EPSController.hpp>
#include "Fw/Types/BasicTypes.hpp"

namespace Ref {

  // ----------------------------------------------------------------------
  // Construction, initialization, and destruction
  // ----------------------------------------------------------------------

  EPSController ::
    EPSController(
        const char *const compName
    ) : EPSControllerComponentBase(compName)
  {

  }

  void EPSController ::
    init(
        const NATIVE_INT_TYPE queueDepth,
        const NATIVE_INT_TYPE msgSize,
        const NATIVE_INT_TYPE instance
    )
  {
    EPSControllerComponentBase::init(queueDepth, msgSize, instance);
  }

  EPSController ::
    ~EPSController()
  {

  }

  // ----------------------------------------------------------------------
  // Handler implementations for user-defined typed input ports
  // ----------------------------------------------------------------------

  void EPSController ::
    conopsIn_handler(
        const NATIVE_INT_TYPE portNum,
        const Ref::InternalType &conopscommand
    )
  {
    // TODO
  }

  void EPSController ::
    stateIn_handler(
        const NATIVE_INT_TYPE portNum,
        const Ref::InternalType &state
    )
  {
    // TODO
  }

  // ----------------------------------------------------------------------
  // Handler implementations for user-defined serial input ports
  // ----------------------------------------------------------------------

  void EPSController ::
    batterySerialIn_handler(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Fw::SerializeBufferBase &Buffer /*!< The serialization buffer*/
    )
  {
    // TODO
  }

  // ----------------------------------------------------------------------
  // Command handler implementations
  // ----------------------------------------------------------------------

  void EPSController ::
    SEND_BATTERY_COMMAND_cmdHandler(
        const FwOpcodeType opCode,
        const U32 cmdSeq,
        Ref::InternalType c
    )
  {
    // TODO
    this->cmdResponse_out(opCode,cmdSeq,Fw::CmdResponse::OK);
  }

  void EPSController ::
    GET_STATE_cmdHandler(
        const FwOpcodeType opCode,
        const U32 cmdSeq,
        Ref::InternalType c
    )
  {
    // TODO
    this->cmdResponse_out(opCode,cmdSeq,Fw::CmdResponse::OK);
  }

  void EPSController ::
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
