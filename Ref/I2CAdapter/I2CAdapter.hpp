// ======================================================================
// \title  I2CAdapter.hpp
// \author root
// \brief  hpp file for I2CAdapter component implementation class
// ======================================================================

#ifndef I2CAdapter_HPP
#define I2CAdapter_HPP

#include "Ref/I2CAdapter/I2CAdapterComponentAc.hpp"

namespace Ref {

  class I2CAdapter :
    public I2CAdapterComponentBase
  {

    public:

      // ----------------------------------------------------------------------
      // Construction, initialization, and destruction
      // ----------------------------------------------------------------------

      //! Construct object I2CAdapter
      //!
      I2CAdapter(
          const char *const compName /*!< The component name*/
      );

      //! Initialize object I2CAdapter
      //!
      void init(
          const NATIVE_INT_TYPE queueDepth, /*!< The queue depth*/
          const NATIVE_INT_TYPE instance = 0 /*!< The instance number*/
      );

      //! Destroy object I2CAdapter
      //!
      ~I2CAdapter();

    PRIVATE:

      // ----------------------------------------------------------------------
      // Handler implementations for user-defined typed input ports
      // ----------------------------------------------------------------------

      //! Handler implementation for adapterIn
      //!
      void adapterIn_handler(
          const NATIVE_INT_TYPE portNum, /*!< The port number*/
          U32 val /*!< 
      The int to send/recieve
      */
      );


    };

} // end namespace Ref

#endif
