//Did not use rawinza's implementation
// xTaskGetTickCount() returns 16-bit or 32-bit tick values, and it may overflow. 
// see: https://www.freertos.org/FreeRTOS_Support_Forum_Archive/February_2012/freertos_Tick_count_overflow_5005076.html

#include <Os/IntervalTimer.hpp>
#include <Fw/Types/Assert.hpp>
#include <stm32-bsp/Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2/cmsis_os.h>

namespace Os {

void 
IntervalTimer::getRawTime(RawTime& time)
{
    TickType_t t = xTaskGetTickCount();
    time.lower = t;

    //https://www.freertos.org/FreeRTOS-Coding-Standard-and-Style-Guide.html#:~:text=port.%20These%20are%3A-,TickType_t,-If%20configUSE_16_BIT_TICKS%20is
}

U32
IntervalTimer::getDiffUsec(const RawTime& stopTime, const RawTime& startTime)
{
    //arithmic involving roll-over is well-defined in c++
    //https://stackoverflow.com/questions/28779803/is-subtracting-larger-unsigned-value-from-smaller-in-c-undefined-behaviour
    #ifdef configUSE_16_BIT_TICKS
    FW_ASSERT (configUSE_16_BIT_TICKS == 0);
    #endif

    #ifdef configTICK_RATE_HZ
    FW_ASSERT (configTICK_RATE_HZ == (TickType_t)1000);
    #endif
    
    return 1000*(stopTime.lower - startTime.lower);
}


}