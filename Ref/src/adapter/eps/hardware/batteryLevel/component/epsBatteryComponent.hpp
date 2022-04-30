// ======================================================================
// \title  epsBatteryComponent.hpp
// \author danny
// \brief  hpp file for epsBatteryComponent component implementation class
//
// \copyright
// Copyright 2009-2015, by the California Institute of Technology.
// ALL RIGHTS RESERVED.  United States Government Sponsorship
// acknowledged.
//
// ======================================================================

#ifndef epsBatteryComponent_HPP
#define epsBatteryComponent_HPP

#include "Ref/src/adapter/eps/hardware/batteryLevel/component/epsBatteryComponentComponentAc.hpp"

namespace Ref {

class epsBatteryComponent : public epsBatteryComponentComponentBase {
   public:
    // ----------------------------------------------------------------------
    // Construction, initialization, and destruction
    // ----------------------------------------------------------------------

    //! Construct object epsBatteryComponent
    //!
    epsBatteryComponent(
        const char *const compName /*!< The component name*/
    );

    //! Initialize object epsBatteryComponent
    //!
    void init(
        const NATIVE_INT_TYPE queueDepth,  /*!< The queue depth*/
        const NATIVE_INT_TYPE instance = 0 /*!< The instance number*/
    );

    //! Destroy object epsBatteryComponent
    //!
    ~epsBatteryComponent();

    PRIVATE :

        // ----------------------------------------------------------------------
        // Handler implementations for user-defined typed input ports
        // ----------------------------------------------------------------------

        //! Handler implementation for epsBatLogicIn
        //!
        Ref::ReturnType
        epsBatLogicIn_handler(
            const NATIVE_INT_TYPE portNum, /*!< The port number*/
            F32 battery_level);

    PRIVATE :

        // ----------------------------------------------------------------------
        // Command handler implementations
        // ----------------------------------------------------------------------

        //! Implementation for SEND_BATTERY_LEVEL command handler
        //! Send battery level
        void
        SEND_BATTERY_LEVEL_cmdHandler(
            const FwOpcodeType opCode, /*!< The opcode*/
            const U32 cmdSeq,          /*!< The command sequence number*/
            F32 battery                /*!<
                           the battery level to send through
                           */
        );
};

}  // end namespace Ref

#endif
