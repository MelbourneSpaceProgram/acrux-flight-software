module OBC {
    @ SComponent for sending a packet to the Adapter
    active component PacketSender {

        # One async command/port is required for active components
        # This should be overridden by the developers with a useful command/port
        @ Port for sending the transfer request
        output port packetTransfer: PacketTransfer

        @ Port for receiving the result
        async input port transferResult: PacketTransferResult
        
        @ Send a packet
        async command SEND_PACKET(
            packet: DataPacket
        )

        @ Send command received
        event COMMAND_RECV(
            packet: DataPacket
        ) severity activity low format "Packet sending command received: {}"

        event RESULT(
            result: U8 @< The result of packet transfer
        ) severity activity high format "Transfer result is {}"

        @ A count of the number of packet received
        telemetry PacketCount: U32

        ##############################################################################
        #### Uncomment the following examples to start customizing your component ####
        ##############################################################################

        # @ Example async command
        # async command COMMAND_NAME(param_name: U32)

        # @ Example telemetry counter
        # telemetry ExampleCounter: U64

        # @ Example event
        # event ExampleStateEvent(example_state: Fw.On) severity activity high id 0 format "State set to {}"

        # @ Example port: receiving calls from the rate group
        # sync input port run: Svc.Sched

        # @ Example parameter
        # param PARAMETER_NAME: U32

        ###############################################################################
        # Standard AC Ports: Required for Channels, Events, Commands, and Parameters  #
        ###############################################################################
        @ Port for requesting the current time
        time get port timeCaller

        @ Port for sending command registrations
        command reg port cmdRegOut

        @ Port for receiving commands
        command recv port cmdIn

        @ Port for sending command responses
        command resp port cmdResponseOut

        @ Port for sending textual representation of events
        text event port logTextOut

        @ Port for sending events to downlink
        event port logOut

        @ Port for sending telemetry channels to downlink
        telemetry port tlmOut

    }
}