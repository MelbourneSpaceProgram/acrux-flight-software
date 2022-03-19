module Ref {
  @ need 6 ports: 2 going in and out from conops, 2 going in and out from state, 
  @ 2 going in and out from battery level 

  @ receiving data packet from state
  port controller_state_in(state: InternalType)

  @ receiving command from conops
  port controller_conops_in(conopscommand: InternalType)

  @ receiving battery level from battery component
  port controller_battery_in(battery: InternalType)

  @ sending data packet to state
  port controller_state_out(packet: InternalType)

  @ sending command down to battery component
  port controller_battery_out(conopscommand: InternalType)
  
  @ sending data packet up to conops
  port controller_conops_out(packet: InternalType)

}