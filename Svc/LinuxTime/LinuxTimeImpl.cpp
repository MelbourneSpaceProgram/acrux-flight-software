/*
 * TestCommand1Impl.cpp
 *
 *  Created on: Mar 28, 2014
 *      Author: tcanham
 */

#include <Svc/LinuxTime/LinuxTimeImpl.hpp>
#include <Fw/Time/Time.hpp>
#include <Os/stm32-bsp/Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2/cmsis_os.h>

namespace Svc
{

    LinuxTimeImpl::LinuxTimeImpl(const char *name) : TimeComponentBase(name)
    {
    }

    LinuxTimeImpl::~LinuxTimeImpl()
    {
    }

    void LinuxTimeImpl::timeGetPort_handler(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Fw::Time &time           /*!< The U32 cmd argument*/
    )
    {
        // tick_count - ms
        // TODO(Daniel/Bill): Fix this to avoid overflow
        TickType_t tick_count = xTaskGetTickCount();
        uint32_t time_seconds = tick_count / 1000;
        uint32_t time_microseconds = time_seconds * 1000000;
        time.set(TB_WORKSTATION_TIME, 0, time_seconds, time_microseconds);
    }

    void LinuxTimeImpl::init(NATIVE_INT_TYPE instance)
    {
        TimeComponentBase::init(instance);
    }

}
