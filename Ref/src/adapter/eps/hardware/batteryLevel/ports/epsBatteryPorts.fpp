module Ref {

  @ need two ports: one port taking input from hardware (eps_logic_bat_input), 
  @ and one port sending this battery level to the controller (eps_logic_bat_output)

  @ Port for receiving battery level from hardware
  port eps_logic_bat_input(battery_level: F32) -> ReturnType 

  @ Port for sending battery level to controller
  port eps_logic_bat_output(battery: F32)

}