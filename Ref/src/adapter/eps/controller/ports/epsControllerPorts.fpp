module Ref{
    
    @ input port for receiving battery level request from conops
    port recv_battery_level_req_from_conops_in(
                                        req_status: bool
                                        @< boolean val, true -> get status
                                        )

    @ output port for requesting battery level from the state
    port req_battery_level_from_state_out(
                                        req_status: bool @< boolean val, true -> get status
                                        )

    @ input port for receiving battery level from the state
    port recv_battery_level_from_state_in(
                                        battery_level: F32
                                        )

    @ output port for sending battery level to conops
    port send_battery_level_to_conops_out(
                                        battery_level: F32
                                        )

    @ input port for receiving battery level from battery level component
    port recv_battery_level_from_eps_in(
                                        battery_level: F32
                                        )

    @ output port for sending battery level to state
    port send_battery_level_to_state_out(
                                        battery_level: F32
                                        )

    @ input port for receiving payload power command from conops    
    port recv_payload_power_cmd_from_conops_in(
                                        power: bool @< boolean val, true -> ON, false -> OFF
                                        )

    @ output port for sending payload power command to payload power component
    port send_payload_power_command_to_eps_out(
                                        power: bool @< boolean val, true -> ON, false -> OFF
                                        )
                                        
    @ input port for receiving success/failure in carrying out power operation  
    port recv_power_command_status_from_eps_in(
                                        status: bool @< boolean val, true -> SUCCESS, false -> FAILURE
                                        )

    port send_power_command_status_to_conops_out(
                                        status: bool @< boolean val, true -> SUCCESS, false -> FAILURE
                                        )
}