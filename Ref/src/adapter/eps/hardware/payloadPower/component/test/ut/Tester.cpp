// ======================================================================
// \title  epsPayloadPowerComponent.hpp
// \author nishq
// \brief  cpp file for epsPayloadPowerComponent test harness implementation class
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

namespace Ref {

  // ----------------------------------------------------------------------
  // Construction and destruction
  // ----------------------------------------------------------------------

  Tester ::
    Tester() :
#if FW_OBJECT_NAMES == 1
      epsPayloadPowerComponentGTestBase("Tester", MAX_HISTORY_SIZE),
      component("epsPayloadPowerComponent")
#else
      epsPayloadPowerComponentGTestBase(MAX_HISTORY_SIZE),
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

  void Tester ::
    testerMainTest()
    {
        this->testHelper();
    }

  // ----------------------------------------------------------------------
  // Handlers for typed from ports
  // ----------------------------------------------------------------------

  void Tester ::
    from_requestPowerStatusOut_handler(
        const NATIVE_INT_TYPE portNum,
        bool req_status
    )
  {
    this->pushFromPortEntry_requestPowerStatusOut(req_status);
  }

  void Tester ::
    from_sendPowerCommandOut_handler(
        const NATIVE_INT_TYPE portNum,
        bool power
    )
  {
    this->pushFromPortEntry_sendPowerCommandOut(power);
  }

  void Tester ::
    from_sendPowerCommandStatusOut_handler(
        const NATIVE_INT_TYPE portNum,
        bool status
    )
  {
    this->pushFromPortEntry_sendPowerCommandStatusOut(status);
  }

  // ----------------------------------------------------------------------
  // Helper methods
  // ----------------------------------------------------------------------

  void Tester ::
    connectPorts()
  {

    // cmdIn
    this->connect_to_cmdIn(
        0,
        this->component.get_cmdIn_InputPort(0)
    );

    // receivePowerCommandIn
    this->connect_to_receivePowerCommandIn(
        0,
        this->component.get_receivePowerCommandIn_InputPort(0)
    );

    // receivePowerStatusIn
    this->connect_to_receivePowerStatusIn(
        0,
        this->component.get_receivePowerStatusIn_InputPort(0)
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

    // eventOut
    this->component.set_eventOut_OutputPort(
        0,
        this->get_from_eventOut(0)
    );

    // requestPowerStatusOut
    this->component.set_requestPowerStatusOut_OutputPort(
        0,
        this->get_from_requestPowerStatusOut(0)
    );

    // sendPowerCommandOut
    this->component.set_sendPowerCommandOut_OutputPort(
        0,
        this->get_from_sendPowerCommandOut(0)
    );

    // sendPowerCommandStatusOut
    this->component.set_sendPowerCommandStatusOut_OutputPort(
        0,
        this->get_from_sendPowerCommandStatusOut(0)
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




  }

  void Tester ::
    initComponents()
  {
    this->init();
    this->component.init(
        INSTANCE
    );
  }

  void Tester ::
    testHelper()
    {   
        const bool powerCmdON = true;
        this->invoke_to_receivePowerCommandIn(0, powerCmdON);

        ASSERT_from_requestPowerStatusOut(0, powerCmdON);
    }

} // end namespace Ref
