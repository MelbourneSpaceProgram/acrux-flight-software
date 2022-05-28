/*
 * TestTelemRecvImpl.hpp
 *
 *  Created on: Mar 28, 2014
 *      Author: tcanham
 */

#ifndef RTOSTIMEIMPL_HPP_
#define RTOSTIMEIMPL_HPP_

#include <Svc/Time/TimeComponentAc.hpp>

namespace Svc {

class RTOSTimeImpl: public TimeComponentBase {
    public:
        RTOSTimeImpl(const char* compName);
        virtual ~RTOSTimeImpl();
        void init(NATIVE_INT_TYPE instance);
    protected:
        void timeGetPort_handler(
                NATIVE_INT_TYPE portNum, /*!< The port number*/
                Fw::Time &time /*!< The U32 cmd argument*/
            );
    private:
};

}

#endif /* RTOSTIMEIMPL_HPP_ */
