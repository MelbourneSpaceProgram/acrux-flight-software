module Fw {
  port Time
  port Tlm
}
module M {
  passive component Telemetry {
    sync input port tlmIn: Fw.Tlm
  }
  passive component C {
    time get port timeGetOut
  }
  instance $telemetry: Telemetry base id 0x100
  instance c: C base id 0x100
  topology T {
    instance $telemetry
    instance c
    telemetry connections instance $telemetry { c }
  }
}
