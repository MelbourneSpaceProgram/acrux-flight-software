// ======================================================================
// \title  epsControllerComponent/test/ut/Tester.hpp
// \author danny
// \brief  hpp file for epsControllerComponent test harness implementation class
//
// \copyright
// Copyright 2009-2015, by the California Institute of Technology.
// ALL RIGHTS RESERVED.  United States Government Sponsorship
// acknowledged.
//
// ======================================================================

#ifndef TESTER_HPP
#define TESTER_HPP

#include "GTestBase.hpp"
#include "Ref/src/adapter/eps/controller/component/epsControllerComponent.hpp"

namespace Ref {

class Tester : public epsControllerComponentGTestBase {
    // ----------------------------------------------------------------------
    // Construction and destruction
    // ----------------------------------------------------------------------

   public:
    //! Construct object Tester
    //!
    Tester();

    //! Destroy object Tester
    //!
    ~Tester();

   public:
    // ----------------------------------------------------------------------
    // Tests
    // ----------------------------------------------------------------------

    //! To do
    //!
    void toDo();
    void testerEPSInStateOut();
    void testerStateInConopsOut();
    void testerConopsInStateOut();
    void testerConopsInEPSOut();
    void testerEPSInPwrStatusOut();

   private:
    // ----------------------------------------------------------------------
    // Handlers for typed from ports
    // ----------------------------------------------------------------------

    //! Handler for from_reqBatteryFromStateOut
    //!
    void from_reqBatteryFromStateOut_handler(
        const NATIVE_INT_TYPE portNum, /*!< The port number*/
        bool req_status                /*!<
                   boolean val, true -> get status
                   */
    );

    //! Handler for from_sendBatteryToConopsOut
    //!
    void from_sendBatteryToConopsOut_handler(
        const NATIVE_INT_TYPE portNum, /*!< The port number*/
        F32 battery_level);

    //! Handler for from_sendBatteryToStateOut
    //!
    void from_sendBatteryToStateOut_handler(
        const NATIVE_INT_TYPE portNum, /*!< The port number*/
        F32 battery_level);

    //! Handler for from_sendPwrCmdToEPSOut
    //!
    void from_sendPwrCmdToEPSOut_handler(
        const NATIVE_INT_TYPE portNum, /*!< The port number*/
        bool power                     /*!<
                        boolean val, true -> ON, false -> OFF
                        */
    );

    //! Handler for from_sendPwrStatusOut
    //!
    void from_sendPwrStatusOut_handler(
        const NATIVE_INT_TYPE portNum, /*!< The port number*/
        bool status                    /*!<
                       boolean val, true -> SUCCESS, false -> FAILURE
                       */
    );

   private:
    // ----------------------------------------------------------------------
    // Helper methods
    // ----------------------------------------------------------------------

    //! Connect ports
    //!
    void connectPorts();

    //! Initialize components
    //!
    void initComponents();

    void testEPSInStateOut(F32 battery_level);
    void testStateInConopsOut(F32 battery_level);
    void testConopsInStateOut(bool req_status);
    void testConopsInEPSOut(bool power);
    void testEPSInPwrStatusOut(bool status);

   private:
    // ----------------------------------------------------------------------
    // Variables
    // ----------------------------------------------------------------------

    //! The component under test
    //!
    epsControllerComponent component;
};

}  // end namespace Ref

#endif
