module OBC {

  @ A data packet
  struct DataPacket {
    destination: SubSystemEnum @< The subsystem the packet is sending to
    message: string size 20 
  }

}