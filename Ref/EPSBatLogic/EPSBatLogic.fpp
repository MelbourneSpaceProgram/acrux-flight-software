module Ref {

  @ EPS Battery Logic Component (in adapter layer)
  active component EPSBatLogic {

    # ----------------------------------------------------------------------
    # General ports
    # ----------------------------------------------------------------------

    @ Port for sending the battery level to the controller component
    output port epsBatLogicOut: eps_logic_bat_output

    @ Port for receiving the result
    sync input port epsBatLogicIn: eps_logic_bat_input

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

    @ Send battery level
    async command SEND_BATTERY_LEVEL(
                           battery: F32 @< the battery level to send through
                         )

    # ----------------------------------------------------------------------
    # Events
    # ----------------------------------------------------------------------

    @ Battery level recieved
    event COMMAND_RECV(
                        battery_level: F32 @< the battery level
                      ) \
      severity activity low \
      format "Battery level received: {f}"

    @ Battery level sent 
    event RESULT(
                  battery: F32 @< Battery sent to state
                ) \
      severity activity high \
      format "Battery sent to state is {f}"

    # ----------------------------------------------------------------------
    # Telemetry
    # ----------------------------------------------------------------------


    @ The battery level received from hardware
    telemetry battery_level: F32

    @ The battery level sent through to Adapter
    telemetry battery: F32

  }

}
