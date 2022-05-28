/*
 * TestCommand1Impl.cpp
 *
 *  Created on: Mar 28, 2014
 *      Author: tcanham
 */

#include <NucleoH7_freeRTOS/Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2/cmsis_os.h>

#include <Fw/Time/Time.hpp>
#include <Svc/LinuxTime/LinuxTimeImpl.hpp>
#include <Svc/RTOSTime/RTOSTimeImpl.hpp>

namespace Svc {

RTOSTimeImpl::RTOSTimeImpl(const char* name) : TimeComponentBase(name) {
}

RTOSTimeImpl::~RTOSTimeImpl() {
}

void LinuxTimeImpl::timeGetPort_handler(
    NATIVE_INT_TYPE portNum, /*!< The port number*/
    Fw::Time& time           /*!< The U32 cmd argument*/
) {
    TickType_t t = xTaskGetTickCount();

    U32 seconds = t * 1000;
    U32 useconds = t / 1000;

    time.set(seconds, useconds);
}

void LinuxTimeImpl::init(NATIVE_INT_TYPE instance) {
    TimeComponentBase::init(instance);
}

}  // namespace Svc
