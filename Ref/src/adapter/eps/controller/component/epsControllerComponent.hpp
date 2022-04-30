// ======================================================================
// \title  epsControllerComponent.hpp
// \author nishq
// \brief  hpp file for epsControllerComponent component implementation class
//
// \copyright
// Copyright 2009-2015, by the California Institute of Technology.
// ALL RIGHTS RESERVED.  United States Government Sponsorship
// acknowledged.
//
// ======================================================================

#ifndef epsControllerComponent_HPP
#define epsControllerComponent_HPP

#include "Ref/adapter/eps/controller/component/epsControllerComponentComponentAc.hpp"

namespace Ref {

  class epsControllerComponent :
    public epsControllerComponentComponentBase
  {

    public:

      // ----------------------------------------------------------------------
      // Construction, initialization, and destruction
      // ----------------------------------------------------------------------

      //! Construct object epsControllerComponent
      //!
      epsControllerComponent(
          const char *const compName /*!< The component name*/
      );

      //! Initialize object epsControllerComponent
      //!
      void init(
          const NATIVE_INT_TYPE queueDepth, /*!< The queue depth*/
          const NATIVE_INT_TYPE instance = 0 /*!< The instance number*/
      );

      //! Destroy object epsControllerComponent
      //!
      ~epsControllerComponent();

    PRIVATE:

      // ----------------------------------------------------------------------
      // Handler implementations for user-defined typed input ports
      // ----------------------------------------------------------------------

      //! Handler implementation for recvBatteryFromEPSIn
      //!
      void recvBatteryFromEPSIn_handler(
          const NATIVE_INT_TYPE portNum, /*!< The port number*/
          F32 battery_level 
      );

      //! Handler implementation for recvBatteryFromStateIn
      //!
      void recvBatteryFromStateIn_handler(
          const NATIVE_INT_TYPE portNum, /*!< The port number*/
          F32 battery_level 
      );

      //! Handler implementation for recvBatteryReqFromConopsIn
      //!
      void recvBatteryReqFromConopsIn_handler(
          const NATIVE_INT_TYPE portNum, /*!< The port number*/
          bool req_status /*!< 
      boolean val, true -> get status
      */
      );

      //! Handler implementation for recvPwrCmdFromConopsIn
      //!
      void recvPwrCmdFromConopsIn_handler(
          const NATIVE_INT_TYPE portNum, /*!< The port number*/
          bool power /*!< 
      boolean val, true -> ON, false -> OFF
      */
      );

      //! Handler implementation for recvPwrStatusFromEPSIn
      //!
      void recvPwrStatusFromEPSIn_handler(
          const NATIVE_INT_TYPE portNum, /*!< The port number*/
          bool status /*!< 
      boolean val, true -> SUCCESS, false -> FAILURE
      */
      );

    PRIVATE:

      // ----------------------------------------------------------------------
      // Command handler implementations
      // ----------------------------------------------------------------------

      //! Implementation for SEND_BATTERY_COMMAND command handler
      //! send commmand down to battery logic component
      void SEND_BATTERY_COMMAND_cmdHandler(
          const FwOpcodeType opCode, /*!< The opcode*/
          const U32 cmdSeq, /*!< The command sequence number*/
          Ref::InternalType c 
      );

      //! Implementation for GET_STATE command handler
      //! request something from state
      void GET_STATE_cmdHandler(
          const FwOpcodeType opCode, /*!< The opcode*/
          const U32 cmdSeq, /*!< The command sequence number*/
          Ref::InternalType c 
      );

      //! Implementation for SEND_DATA_CONOPS command handler
      //! send data packet up to conops
      void SEND_DATA_CONOPS_cmdHandler(
          const FwOpcodeType opCode, /*!< The opcode*/
          const U32 cmdSeq, /*!< The command sequence number*/
          Ref::InternalType c 
      );


    };

} // end namespace Ref

#endif
