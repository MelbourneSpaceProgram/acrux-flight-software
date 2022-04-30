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

  void Tester ::
    testerEPSInStateOut()
    { 
        const F32 battery_level = 80.02;
        this->testEPSInStateOut(battery_level);
    }

  void Tester ::
    testerStateInConopsOut()
    {
        const F32 battery_level = 80.02;
        this->testStateInConopsOut(battery_level);
    }
  void Tester ::
    testerConopsInStateOut()
    {
        this->testConopsInStateOut(true);
    }

  void Tester ::
    testerConopsInEPSOut()
    {
        this->testConopsInEPSOut(true);
    }

  void Tester ::
    testerEPSInPwrStatusOut()
    {
        this->testEPSInPwrStatusOut(true);
    }


  // ----------------------------------------------------------------------
  // Handlers for typed from ports
  // ----------------------------------------------------------------------

  void Tester ::
    from_reqBatteryFromStateOut_handler(
        const NATIVE_INT_TYPE portNum,
        bool req_status
    )
  {
    this->pushFromPortEntry_reqBatteryFromStateOut(req_status);
  }

  void Tester ::
    from_sendBatteryToConopsOut_handler(
        const NATIVE_INT_TYPE portNum,
        F32 battery_level
    )
  {
    this->pushFromPortEntry_sendBatteryToConopsOut(battery_level);
  }

  void Tester ::
    from_sendBatteryToStateOut_handler(
        const NATIVE_INT_TYPE portNum,
        F32 battery_level
    )
  {
    this->pushFromPortEntry_sendBatteryToStateOut(battery_level);
  }

  void Tester ::
    from_sendPwrCmdToEPSOut_handler(
        const NATIVE_INT_TYPE portNum,
        bool power
    )
  {
    this->pushFromPortEntry_sendPwrCmdToEPSOut(power);
  }

  void Tester ::
    from_sendPwrStatusOut_handler(
        const NATIVE_INT_TYPE portNum,
        bool status
    )
  {
    this->pushFromPortEntry_sendPwrStatusOut(status);
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

    // recvBatteryFromEPSIn
    this->connect_to_recvBatteryFromEPSIn(
        0,
        this->component.get_recvBatteryFromEPSIn_InputPort(0)
    );

    // recvBatteryFromStateIn
    this->connect_to_recvBatteryFromStateIn(
        0,
        this->component.get_recvBatteryFromStateIn_InputPort(0)
    );

    // recvBatteryReqFromConopsIn
    this->connect_to_recvBatteryReqFromConopsIn(
        0,
        this->component.get_recvBatteryReqFromConopsIn_InputPort(0)
    );

    // recvPwrCmdFromConopsIn
    this->connect_to_recvPwrCmdFromConopsIn(
        0,
        this->component.get_recvPwrCmdFromConopsIn_InputPort(0)
    );

    // recvPwrStatusFromEPSIn
    this->connect_to_recvPwrStatusFromEPSIn(
        0,
        this->component.get_recvPwrStatusFromEPSIn_InputPort(0)
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

    // reqBatteryFromStateOut
    this->component.set_reqBatteryFromStateOut_OutputPort(
        0,
        this->get_from_reqBatteryFromStateOut(0)
    );

    // sendBatteryToConopsOut
    this->component.set_sendBatteryToConopsOut_OutputPort(
        0,
        this->get_from_sendBatteryToConopsOut(0)
    );

    // sendBatteryToStateOut
    this->component.set_sendBatteryToStateOut_OutputPort(
        0,
        this->get_from_sendBatteryToStateOut(0)
    );

    // sendPwrCmdToEPSOut
    this->component.set_sendPwrCmdToEPSOut_OutputPort(
        0,
        this->get_from_sendPwrCmdToEPSOut(0)
    );

    // sendPwrStatusOut
    this->component.set_sendPwrStatusOut_OutputPort(
        0,
        this->get_from_sendPwrStatusOut(0)
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
        QUEUE_DEPTH, INSTANCE
    );
  }

  void Tester ::
    testEPSInStateOut(F32 battery_level)
  {
    this->invoke_to_recvBatteryFromEPSIn(0, battery_level);
    this->component.doDispatch();
    ASSERT_from_sendBatteryToStateOut(0, battery_level);
  }
  
  void Tester ::
    testStateInConopsOut(F32 battery_level)
  {
    this->invoke_to_recvBatteryFromStateIn(0, battery_level);
    this->component.doDispatch();
    ASSERT_from_sendBatteryToConopsOut(0,battery_level);
  }

  void Tester ::
    testConopsInStateOut(bool req_status) 
  {
    this->invoke_to_recvBatteryReqFromConopsIn(0, req_status);
    this->component.doDispatch();
    ASSERT_from_reqBatteryFromStateOut(0,req_status);
  }

  void Tester ::
    testConopsInEPSOut(bool power) 
  {
    this->invoke_to_recvPwrCmdFromConopsIn(0, power);
    this->component.doDispatch();
    ASSERT_from_sendPwrCmdToEPSOut(0,power);
  }  
  
  void Tester ::
    testEPSInPwrStatusOut(bool status) 
  {
    this->invoke_to_recvPwrStatusFromEPSIn(0, status);
    ASSERT_from_sendPwrStatusOut(0,status);
  } 
} // end namespace Ref
