// ======================================================================
// \title  PacketSender.hpp
// \author thomas
// \brief  hpp file for PacketSender component implementation class
// ======================================================================

#ifndef PacketSender_HPP
#define PacketSender_HPP

#include "Components/PacketSender/PacketSenderComponentAc.hpp"

namespace OBC {

class PacketSender : public PacketSenderComponentBase {
  private:
    U32 packetCount;

  public:
    // ----------------------------------------------------------------------
    // Construction, initialization, and destruction
    // ----------------------------------------------------------------------

    //! Construct object PacketSender
    //!
    PacketSender(const char* const compName /*!< The component name*/
    );

    //! Destroy object PacketSender
    //!
    ~PacketSender();

    PRIVATE :

        // ----------------------------------------------------------------------
        // Handler implementations for user-defined typed input ports
        // ----------------------------------------------------------------------

        //! Handler implementation for transferResult
        //!
        void
        transferResult_handler(const NATIVE_INT_TYPE portNum, /*!< The port number*/
                               U8 result                      /*!<
                                                the result of the operation
                                                */
        );

    PRIVATE :

        // ----------------------------------------------------------------------
        // Command handler implementations
        // ----------------------------------------------------------------------

        //! Implementation for SEND_PACKET command handler
        //! Send a packet
        void
        SEND_PACKET_cmdHandler(const FwOpcodeType opCode, /*!< The opcode*/
                               const U32 cmdSeq,          /*!< The command sequence number*/
                               OBC::DataPacket packet);
};

}  // namespace OBC

#endif
