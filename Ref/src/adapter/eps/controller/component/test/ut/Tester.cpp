// ======================================================================
// \title  epsControllerComponent.hpp
// \author danny
// \brief  cpp file for epsControllerComponent test harness implementation class
//
// \copyright
// Copyright 2009-2015, by the California Institute of Technology.
// ALL RIGHTS RESERVED.  United States Government Sponsorship
// acknowledged.
//
// ======================================================================

#include "Tester.hpp"

#define INSTANCE 0
#define MAX_HISTORY_SIZE 10
#define QUEUE_DEPTH 10

namespace Ref {

  // ----------------------------------------------------------------------
  // Construction and destruction
  // ----------------------------------------------------------------------

  Tester ::
    Tester() :
#if FW_OBJECT_NAMES == 1
      epsControllerComponentGTestBase("Tester", MAX_HISTORY_SIZE),
      component("epsControllerComponent")
#else
      epsControllerComponentGTestBase(MAX_HISTORY_SIZE),
      component()
#endif
  {
    this->initComponents();
    this->connectPorts();
  }

  Tester ::
    ~Tester()
  {

  }

  // ----------------------------------------------------------------------
  // Tests
  // ----------------------------------------------------------------------

  void Tester ::
    toDo()
  {
    // TODO
  }

  // ----------------------------------------------------------------------
  // Handlers for typed from ports
  // ----------------------------------------------------------------------

  Ref::ReturnType Tester ::
    from_batteryOut_handler(
        const NATIVE_INT_TYPE portNum,
        bool power
    )
  {
    this->pushFromPortEntry_batteryOut(power);
    return ReturnType::SUCCESS; // TODO: Return a value
  }

  void Tester ::
    from_conopsOut_handler(
        const NATIVE_INT_TYPE portNum,
        F32 battery
    )
  {
    this->pushFromPortEntry_conopsOut(battery);
  }

  // ----------------------------------------------------------------------
  // Handlers for serial from ports
  // ----------------------------------------------------------------------

  void Tester ::
    from_stateSerialOut_handler(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Fw::SerializeBufferBase &Buffer /*!< The serialization buffer*/
    )
  {
    // TODO
  }

  // ----------------------------------------------------------------------
  // Helper methods
  // ----------------------------------------------------------------------

  void Tester ::
    testConopsIn( NATIVE_INT_TYPE portNum, bool conopscommand)
  {
       this->from_batteryOut_handler(portNum, true);
      // verify that that one output port was invoked overall
      //ASSERT_IN_PORT_HISTORY_SIZE(1);
      // verify the arguments of the operation port
      //ASSERT_from_conopsIn(portNum, conopscommand);
      ASSERT_from_batteryOut_SIZE(1);

  }
  void Tester::
    testPorts(){
	    this->testConopsIn(0, true);
  }
  void Tester:: 
    connectPorts()
  {

    // cmdIn
    this->connect_to_cmdIn(
        0,
        this->component.get_cmdIn_InputPort(0)
    );

    // conopsIn
    this->connect_to_conopsIn(
        0,
        this->component.get_conopsIn_InputPort(0)
    );

    // stateIn
    this->connect_to_stateIn(
        0,
        this->component.get_stateIn_InputPort(0)
    );

    // batteryOut
    this->component.set_batteryOut_OutputPort(
        0,
        this->get_from_batteryOut(0)
    );

    // cmdRegOut
    this->component.set_cmdRegOut_OutputPort(
        0,
        this->get_from_cmdRegOut(0)
    );

    // cmdResponseOut
    this->component.set_cmdResponseOut_OutputPort(
        0,
        this->get_from_cmdResponseOut(0)
    );

    // conopsOut
    this->component.set_conopsOut_OutputPort(
        0,
        this->get_from_conopsOut(0)
    );

    // eventOut
    this->component.set_eventOut_OutputPort(
        0,
        this->get_from_eventOut(0)
    );

    // textEventOut
    this->component.set_textEventOut_OutputPort(
        0,
        this->get_from_textEventOut(0)
    );

    // timeGetOut
    this->component.set_timeGetOut_OutputPort(
        0,
        this->get_from_timeGetOut(0)
    );

    // tlmOut
    this->component.set_tlmOut_OutputPort(
        0,
        this->get_from_tlmOut(0)
    );


  // ----------------------------------------------------------------------
  // Connect serial output ports
  // ----------------------------------------------------------------------
    this->component.set_stateSerialOut_OutputPort(
        0,
        this->get_from_stateSerialOut(0)
    );


  // ----------------------------------------------------------------------
  // Connect serial input ports
  // ----------------------------------------------------------------------
    // batterySerialIn
    this->connect_to_batterySerialIn(
        0,
        this->component.get_batterySerialIn_InputPort(0)
    );


  }

  void Tester ::
    initComponents()
  {
    this->init();
    this->component.init(
        QUEUE_DEPTH, INSTANCE
    );
  }

} // end namespace Ref
