module Ref {

  @ EPS Controller (logic layer)
  active component epsControllerComponent {

    # ----------------------------------------------------------------------
    # General ports
    # ----------------------------------------------------------------------

    async input port recvBatteryReqFromConopsIn: recv_battery_level_req_from_conops_in

    output port reqBatteryFromStateOut: req_battery_level_from_state_out

    async input port recvBatteryFromStateIn: recv_battery_level_from_state_in

    output port sendBatteryToConopsOut: send_battery_level_to_conops_out

    async input port recvBatteryFromEPSIn: recv_battery_level_from_eps_in

    output port sendBatteryToStateOut: send_battery_level_to_state_out

    async input port recvPwrCmdFromConopsIn: recv_payload_power_cmd_from_conops_in

    output port sendPwrCmdToEPSOut: send_payload_power_command_to_eps_out

    async input port recvPwrStatusFromEPSIn: recv_power_command_status_from_eps_in

    # ----------------------------------------------------------------------
    # Special ports
    # ----------------------------------------------------------------------

    @ Command receive port
    command recv port cmdIn

    @ Command registration port
    command reg port cmdRegOut

    @ Command response port
    command resp port cmdResponseOut

    @ Event port
    event port eventOut

    @ Telemetry port
    telemetry port tlmOut

    @ Text event port
    text event port textEventOut

    @ Time get port
    time get port timeGetOut

    # ----------------------------------------------------------------------
    # Commands
    # ----------------------------------------------------------------------

    @ send commmand down to battery logic component
    sync command SEND_BATTERY_COMMAND(c: InternalType)

    @ request something from state
    sync command GET_STATE(c: InternalType)

    @ send data packet up to conops
    sync command SEND_DATA_CONOPS(c: InternalType)

    # ----------------------------------------------------------------------
    # Events
    # ----------------------------------------------------------------------

    @ Command recieved
    event COMMAND_RECV(
                        command_conops: InternalType @< Command from conops recieved
                      ) \
      severity activity high \
      format "Command received from conops {}"

    @ State received
    event RESULT(
                  state: InternalType @< Battery sent to state
                ) \
      severity activity low \
      format "Receieved a state {}"

    # ----------------------------------------------------------------------
    # Telemetry
    # ----------------------------------------------------------------------


    @ The battery level received from state
    telemetry state_check: InternalType

    @ The Command received from conops
    telemetry command_received: InternalType

  }

}
