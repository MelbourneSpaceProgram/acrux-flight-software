// ======================================================================
// \title  MathSender.cpp
// \author root
// \brief  cpp file for MathSender component implementation class
// ======================================================================


#include <Ref/MathSender/MathSender.hpp>
#include "Fw/Types/BasicTypes.hpp"

namespace Ref {

  // ----------------------------------------------------------------------
  // Construction, initialization, and destruction
  // ----------------------------------------------------------------------

  MathSender ::
    MathSender(
        const char *const compName
    ) : MathSenderComponentBase(compName)
  {

  }

  void MathSender ::
    init(
        const NATIVE_INT_TYPE queueDepth,
        const NATIVE_INT_TYPE instance
    )
  {
    MathSenderComponentBase::init(queueDepth, instance);
  }

  MathSender ::
    ~MathSender()
  {

  }

  // ----------------------------------------------------------------------
  // Handler implementations for user-defined typed input ports
  // ----------------------------------------------------------------------

  void MathSender ::
    mathResultIn_handler( // called when MathReceiver component code returns a result by invoking the mathResultIn port.
        const NATIVE_INT_TYPE portNum,
        F32 result
    ) 
  {
    this->tlmWrite_RESULT(result);
    this->log_ACTIVITY_HI_RESULT(result);
  }

  // ----------------------------------------------------------------------
  // Command handler implementations
  // ----------------------------------------------------------------------

  void MathSender ::
    DO_MATH_cmdHandler(
        const FwOpcodeType opCode, // command opcode
        const U32 cmdSeq,          // Command Sequence number
        F32 val1,           // remaining args supplied when command is sent.
        Ref::MathOp op,
        F32 val2
    )
  {
    this->tlmWrite_VAL1(val1);
    this->tlmWrite_OP(op);
    this->tlmWrite_VAL2(val2);
    this->log_ACTIVITY_LO_COMMAND_RECV(val1, op, val2);
    this->mathOpOut_out(0, val1, op, val2);
    this->cmdResponse_out(opCode, cmdSeq, Fw::CmdResponse::OK); // all handlers need to end with cmd resposne.
  }

} // end namespace Ref
