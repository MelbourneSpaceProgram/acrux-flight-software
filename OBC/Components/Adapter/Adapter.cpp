// ======================================================================
// \title  Adapter.cpp
// \author thomas
// \brief  cpp file for Adapter component implementation class
// ======================================================================

#include <Components/Adapter/Adapter.hpp>
#include <FpConfig.hpp>

#include "Fw/Logger/Logger.hpp"

namespace OBC {

// ----------------------------------------------------------------------
// Construction, initialization, and destruction
// ----------------------------------------------------------------------

Adapter ::Adapter(const char* const compName) : AdapterComponentBase(compName) {}

Adapter ::~Adapter() {}

// ----------------------------------------------------------------------
// Handler implementations for user-defined typed input ports
// ----------------------------------------------------------------------

void Adapter ::packetIn_handler(const NATIVE_INT_TYPE portNum, const OBC::DataPacket& packet) {
    OBC::DataPacket::StringSize20 message = packet.getmessage();
    SubSystemEnum ss = packet.getdestination();

    // copy data from string to output buffer
    char inBuf[message.length() + 1];
    Fw::Buffer in;
    in.setData(reinterpret_cast<U8*>(inBuf));
    in.setSize(sizeof(inBuf));

    Fw::Buffer out;
    out.setData(reinterpret_cast<U8*>(const_cast<char*>(message.toChar())));
    out.setSize(message.length());

    if (ss == SubSystemEnum::EPS) {
        Drv::I2cStatus status = this->I2CWriteOut_out(0, 9999, in);
        this->log_ACTIVITY_HI_I2C_WRITE_STATUS(status);
        if (status != Drv::I2cStatus::I2C_OK) {
            this->transferResultOut_out(0, 0);
        } else {
            this->transferResultOut_out(0, 1);
        }
    } else if (ss == SubSystemEnum::COMM) {
        this->log_ACTIVITY_HI_SPI_MSG_OUT(message);
        this->SPIReadWriteOut_out(0, out, in);

        inBuf[sizeof(inBuf) - 1] = 0;
        Fw::LogStringArg arg = inBuf;

        this->log_ACTIVITY_HI_SPI_MSG_IN(arg);
        this->transferResultOut_out(0, 1);
    }
}

void Adapter ::schedIn_handler(const NATIVE_INT_TYPE portNum, NATIVE_UINT_TYPE context) {
    U32 numMsgs = this->m_queue.getNumMsgs();
    for (U32 i = 0; i < numMsgs; ++i) {
        (void)this->doDispatch();
    }
}

}  // end namespace OBC
