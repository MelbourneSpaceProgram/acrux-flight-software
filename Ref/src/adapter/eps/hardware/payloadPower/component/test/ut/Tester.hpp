// ======================================================================
// \title  epsPayloadPowerComponent/test/ut/Tester.hpp
// \author nishq
// \brief  hpp file for epsPayloadPowerComponent test harness implementation class
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
#include "Ref/src/adapter/eps/hardware/payloadPower/component/epsPayloadPowerComponent.hpp"

namespace Ref {

  class Tester :
    public epsPayloadPowerComponentGTestBase
  {

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

      void testerMainTest();

    private:

      // ----------------------------------------------------------------------
      // Handlers for typed from ports
      // ----------------------------------------------------------------------

      //! Handler for from_requestPowerStatusOut
      //!
      void from_requestPowerStatusOut_handler(
          const NATIVE_INT_TYPE portNum, /*!< The port number*/
          bool req_status /*!< 
      boolean val, true -> get status
      */
      );

      //! Handler for from_sendPowerCommandOut
      //!
      void from_sendPowerCommandOut_handler(
          const NATIVE_INT_TYPE portNum, /*!< The port number*/
          bool power /*!< 
      boolean val, true -> ON, false -> OFF
      */
      );

      //! Handler for from_sendPowerCommandStatusOut
      //!
      void from_sendPowerCommandStatusOut_handler(
          const NATIVE_INT_TYPE portNum, /*!< The port number*/
          bool status /*!< 
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

      void testHelper();

    private:

      // ----------------------------------------------------------------------
      // Variables
      // ----------------------------------------------------------------------

      //! The component under test
      //!
      epsPayloadPowerComponent component;

  };

} // end namespace Ref

#endif
