// ======================================================================
// \title  I2CAdapter.cpp
// \author root
// \brief  cpp file for I2CAdapter component implementation class
// ======================================================================


#include <Ref/I2CAdapter/I2CAdapter.hpp>
#include "Fw/Types/BasicTypes.hpp" // basic driver for I2C. To be subbed out for FreeRTOS.

namespace Ref {

  // ----------------------------------------------------------------------
  // Construction, initialization, and destruction
  // ----------------------------------------------------------------------

  I2CAdapter ::
    I2CAdapter(
        const char *const compName
    ) : I2CAdapterComponentBase(compName)
  {

  }

  void I2CAdapter ::
    init(
        const NATIVE_INT_TYPE queueDepth,
        const NATIVE_INT_TYPE instance
    )
  {
    I2CAdapterComponentBase::init(queueDepth, instance);
  }

  I2CAdapter ::
    ~I2CAdapter()
  {

  }

  // ----------------------------------------------------------------------
  // Handler implementations for user-defined typed input ports
  // ----------------------------------------------------------------------











  void I2CAdapter ::
    adapterIn_handler(
        const NATIVE_INT_TYPE portNum,
        U32 val
    )
  {
    // TODO - write to the port.

  }

} // end namespace Ref
