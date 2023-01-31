/*
 * TestCommand1Impl.cpp
 *
 *  Created on: Mar 28, 2014
 *      Author: tcanham
 */

#include <Svc/LinuxTime/LinuxTimeImpl.hpp>
#include <Fw/Time/Time.hpp>
#include <Ref/NucleoH7_freeRTOS/Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2/cmsis_os.h>

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
        TickType_t tick_count = xTaskGetTickCount(); //assume 32bit tick counts
        uint64_t new_sys_time_usec = tick_count*1000;
        
        uint64_t time_total_usec = time.getSeconds ()*1000000 + time.getUSeconds ();
        uint32_t new_time_total_usec = new_sys_time_usec + (new_sys_time_usec - time_total_usec%(UINT32_MAX*1000)); //to handle rollover in 32bit tick counts

        uint32_t new_time_sec = new_time_total_usec/1000000; //calculate the second portion
        uint32_t new_time_usec = new_time_total_usec%1000000; //calculate the microsecond portion
        time.set(TB_WORKSTATION_TIME, 0, new_time_sec, new_time_usec);
    }

    void LinuxTimeImpl::init(NATIVE_INT_TYPE instance)
    {
        TimeComponentBase::init(instance);
    }

}
