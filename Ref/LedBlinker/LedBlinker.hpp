// ======================================================================
// \title  LedBlinker.hpp
// \author root
// \brief  hpp file for LedBlinker component implementation class
// ======================================================================

#ifndef LedBlinker_HPP
#define LedBlinker_HPP

#include "Ref/LedBlinker/LedBlinkerComponentAc.hpp"

namespace Ref {

  class LedBlinker :
    public LedBlinkerComponentBase
  {

    public:

      // ----------------------------------------------------------------------
      // Construction, initialization, and destruction
      // ----------------------------------------------------------------------

      //! Construct object LedBlinker
      //!
      LedBlinker(
          const char *const compName /*!< The component name*/
      );

      //! Initialize object LedBlinker
      //!
      void init(
          const NATIVE_INT_TYPE instance = 0 /*!< The instance number*/
      );

      //! Destroy object LedBlinker
      //!
      ~LedBlinker();

    PRIVATE:

      // ----------------------------------------------------------------------
      // Handler implementations for user-defined typed input ports
      // ----------------------------------------------------------------------

      //! Handler implementation for schedIn
      //!
      void schedIn_handler(
          const NATIVE_INT_TYPE portNum, /*!< The port number*/
          NATIVE_UINT_TYPE context /*!< 
      The call order
      */
      );


    };

} // end namespace Ref

#endif
