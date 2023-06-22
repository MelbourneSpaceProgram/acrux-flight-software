module OBC {

  @ Port for requesting packet transfer
  port PacketTransfer(
               packet: DataPacket
             )

  @ Port for returning the result of a packet transfer
  port PacketTransferResult(
                   result: U8 @< the result of the operation
                 )

}