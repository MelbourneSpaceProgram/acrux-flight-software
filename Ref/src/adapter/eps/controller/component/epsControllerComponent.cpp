// ======================================================================
// \title  epsControllerComponent.cpp
// \author nishq
// \brief  cpp file for epsControllerComponent component implementation class
//
// \copyright
// Copyright 2009-2015, by the California Institute of Technology.
// ALL RIGHTS RESERVED.  United States Government Sponsorship
// acknowledged.
//
// ======================================================================

#include <Ref/src/adapter/eps/controller/component/epsControllerComponent.hpp>

#include "Fw/Types/BasicTypes.hpp"

namespace Ref {

// ----------------------------------------------------------------------
// Construction, initialization, and destruction
// ----------------------------------------------------------------------

epsControllerComponent ::
    epsControllerComponent(
        const char *const compName) : epsControllerComponentComponentBase(compName) {
}

void epsControllerComponent ::
    init(
        const NATIVE_INT_TYPE queueDepth,
        const NATIVE_INT_TYPE instance) {
    epsControllerComponentComponentBase::init(queueDepth, instance);
}

epsControllerComponent ::
    ~epsControllerComponent() {
}

// ----------------------------------------------------------------------
// Handler implementations for user-defined typed input ports
// ----------------------------------------------------------------------

void epsControllerComponent ::
    recvBatteryFromEPSIn_handler(
        const NATIVE_INT_TYPE portNum,
        F32 battery_level) {
    this->sendBatteryToStateOut_out(portNum, battery_level);
}

void epsControllerComponent ::
    recvBatteryFromStateIn_handler(
        const NATIVE_INT_TYPE portNum,
        F32 battery_level) {
    this->sendBatteryToConopsOut_out(portNum, battery_level);
}

void epsControllerComponent ::
    recvBatteryReqFromConopsIn_handler(
        const NATIVE_INT_TYPE portNum,
        bool req_status) {
    this->reqBatteryFromStateOut_out(portNum, req_status);
}

void epsControllerComponent ::
    recvPwrCmdFromConopsIn_handler(
        const NATIVE_INT_TYPE portNum,
        bool power) {
    this->sendPwrCmdToEPSOut_out(portNum, power);
}

void epsControllerComponent ::
    recvPwrStatusFromEPSIn_handler(
        const NATIVE_INT_TYPE portNum,
        bool status) {
    this->sendPwrStatusOut_out(portNum, status);
}

// ----------------------------------------------------------------------
// Command handler implementations
// ----------------------------------------------------------------------

void epsControllerComponent ::
    SEND_BATTERY_COMMAND_cmdHandler(
        const FwOpcodeType opCode,
        const U32 cmdSeq,
        Ref::InternalType c) {
    // TODO
    this->cmdResponse_out(opCode, cmdSeq, Fw::CmdResponse::OK);
}

void epsControllerComponent ::
    GET_STATE_cmdHandler(
        const FwOpcodeType opCode,
        const U32 cmdSeq,
        Ref::InternalType c) {
    // TODO
    this->cmdResponse_out(opCode, cmdSeq, Fw::CmdResponse::OK);
}

void epsControllerComponent ::
    SEND_DATA_CONOPS_cmdHandler(
        const FwOpcodeType opCode,
        const U32 cmdSeq,
        Ref::InternalType c) {
    // TODO
    this->cmdResponse_out(opCode, cmdSeq, Fw::CmdResponse::OK);
}

}  // end namespace Ref
