#include <Os/stm32-bsp/Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2/cmsis_os.h>
#include <StandardTypes.hpp>
#include <Os/TaskId.hpp>

namespace Os
{
    TaskId::TaskId(void)
    {
        TaskStatus_t taskStatus;
        vTaskGetInfo( NULL, &taskStatus,pdFALSE, eDeleted);
        id = taskStatus.xTaskNumber;
    }
    TaskId::~TaskId(void)
    {
    }
    bool TaskId::operator==(const TaskId& T) const
    {
        return (id == T.id);
    }
    bool TaskId::operator!=(const TaskId& T) const
    {
        return (id != T.id); 
    }
    TaskIdRepr TaskId::getRepr(void) const //TODO: Is TaskIdRepr defined at all? Nope.. Added in TaskIdRepr.hpp
    {
        return this->id;
    }
}