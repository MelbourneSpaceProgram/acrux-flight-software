module Ref {

  @ Component for sending a math operation 
  active component I2CAdapter {

    # ----------------------------------------------------------------------
    # General ports
    # ----------------------------------------------------------------------

    @ Port for recieving input
    async input port adapterIn: MessagePort

    @ Port for sending output:
    output port adapterOut: MessagePort


    # ----------------------------------------------------------------------
    # Special ports 
    # ----------------------------------------------------------------------

    @ Event port. 
    event port eventOut

    @ Telemetry port
    telemetry port tlmOut

    @ Time get port
    time get port timeGetOut

    @ Text event port
    text event port textEventOut


    # ----------------------------------------------------------------------
    # Events
    # ----------------------------------------------------------------------

    @ Received a message
    event MESSAGE(
                  val: U32 @< The message
                ) \
      severity activity high \
      format "Message is {d}"

    # ----------------------------------------------------------------------
    # Telemetry
    # ----------------------------------------------------------------------

    @ The message
    telemetry MESSAGE: U32
    
  }

}