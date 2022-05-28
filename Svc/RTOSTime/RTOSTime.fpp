module Svc {

  @ A component for getting time
  passive component RTOSTime {

    @ Port to retrieve time
    sync input port timeGetPort: Fw.Time

  }

}
