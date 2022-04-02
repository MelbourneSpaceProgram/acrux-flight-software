module Ref {
  @ need 6 ports: 2 going in and out from conops, 2 going in and out from state, 
  @ 2 going in and out from battery level 

  @ receiving battery from state 
  port controller_state_in(battery_level: f32)

  @ receiving command from conops
  port controller_conops_in(conopscommand: InternalType)

  @ receiving battery level from battery component
  port controller_battery_in(battery: f32)

  @ sending battery level to state
  port controller_state_out(battery_level: f32)

  @ sending command down to payload power component 
  port controller_battery_out(conopscommand: InternalType) -> ReturnType

  @ receive payload confirmation from payload power component 
  port controller_payload_in(confirmation: ReturnType)
  
  @ sending battery up to conops
  port controller_conops_out(battery: f32)

}