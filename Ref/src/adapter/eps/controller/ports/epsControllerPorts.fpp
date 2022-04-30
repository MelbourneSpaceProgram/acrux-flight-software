module Ref {
  @ need 6 ports: 2 going in and out from conops, 2 going in and out from state, 
  @ 2 going in and out from battery level 

  @ receiving battery from state 
  port controller_state_in(battery_level: F32)

  @ receiving command from conops
  port controller_conops_in(
                              conopscommand: bool @< boolean val, true -> ON, false -> OFF
                            )

  @ receiving battery level from battery component
  port controller_battery_in(battery: F32)

  @ sending battery level to state
  port controller_state_out(battery_level: F32)

  @ sending command down to payload power component 
  port controller_battery_out(
                                power: bool @< boolean val, true -> ON, false -> OFF
                              ) -> ReturnType

  @ receive payload confirmation from payload power component 
  port controller_payload_in(
                              status: bool @< boolean val, true -> SUCCESS, false -> FAILURE
                            )
  
  @ sending battery up to conops
  port controller_conops_out(battery: F32)

}
