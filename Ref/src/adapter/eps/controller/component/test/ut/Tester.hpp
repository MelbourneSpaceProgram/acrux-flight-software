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
#include "Ref/adapter/eps/controller/component/epsControllerComponent.hpp"

namespace Ref {

  class Tester :
    public epsControllerComponentGTestBase
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

      void testPorts();
    private:

      // ----------------------------------------------------------------------
      // Handlers for typed from ports
      // ----------------------------------------------------------------------

      //! Handler for from_batteryOut
      //!
      Ref::ReturnType from_batteryOut_handler(
          const NATIVE_INT_TYPE portNum, /*!< The port number*/
          bool power /*!< 
      boolean val, true -> ON, false -> OFF
      */
      );

      //! Handler for from_conopsOut
      //!
      void from_conopsOut_handler(
          const NATIVE_INT_TYPE portNum, /*!< The port number*/
          F32 battery 
      );

    private:

      // ----------------------------------------------------------------------
      // Handlers for serial from ports
      // ----------------------------------------------------------------------

      //! Handler for from_stateSerialOut
      //!
      void from_stateSerialOut_handler(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Fw::SerializeBufferBase &Buffer /*!< The serialization buffer*/
      );

    private:

      // ----------------------------------------------------------------------
      // Helper methods
      // ----------------------------------------------------------------------
      
      //! Test conopsIn port

      void testConopsIn(NATIVE_INT_TYPE portNum, bool conopscommand);

      //! Connect ports
      //!
      void connectPorts();

      //! Initialize components
      //!
      void initComponents();

    private:

      // ----------------------------------------------------------------------
      // Variables
      // ----------------------------------------------------------------------

      //! The component under test
      //!
      epsControllerComponent component;

  };

} // end namespace Ref

#endif
