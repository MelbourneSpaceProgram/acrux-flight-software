module Ref {

  @ EPS Controller (logic layer)
  active component epsControllerComponent {

    # ----------------------------------------------------------------------
    # General ports
    # ----------------------------------------------------------------------

    async input port conopsIn: controller_conops_in

    async input port stateIn: controller_state_in

    output port conopsOut: controller_conops_out

    output port batteryOut: controller_battery_out

    async input port batterySerialIn: serial

    output port stateSerialOut: serial

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