#include <Fw/Types/Assert.hpp>
#include <Os/Task.hpp>
#include <Os/stm32-bsp/Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2/cmsis_os.h>

namespace Os {

Task::Task() : m_handle(0), m_identifier(0), m_affinity(-1), m_started(false), m_suspendedOnPurpose(false), m_routineWrapper()
{
}

Task::~Task() 
{
    // If a registry has been registered, remove task
    if (Task::s_taskRegistry) {
        Task::s_taskRegistry->removeTask(this);
    }

}

Task::TaskStatus 
Task::start(const Fw::StringBase &name, taskRoutine routine, void* arg, NATIVE_UINT_TYPE priority,
             NATIVE_UINT_TYPE stackSize,  NATIVE_UINT_TYPE cpuAffinity, NATIVE_UINT_TYPE identifier) 
{
    TaskHandle_t xHandle;
    this->m_name = "TP_";
    this->m_name += name;
    this->m_identifier = identifier;
    Task::TaskStatus tStat = TASK_OK;
    int basetype;

    basetype = xTaskCreate(routine, (char*)this->m_name.toChar(), stackSize, arg, priority, &xHandle );
    if (basetype !=1){
        tStat = TASK_INVALID_PARAMS;
    }
    else{
        this->m_handle = (POINTER_CAST)xHandle;
    }
    return tStat;
}

Task::TaskStatus 
Task::delay(NATIVE_UINT_TYPE milliseconds)
{
    vTaskDelay(milliseconds);

    return TASK_OK; // for coverage analysis

}

TaskId Task::getOsIdentifier(void) {
    TaskId T;
    return T;
}

// Note: not implemented for Posix threads. See https://nasa.github.io/fprime/UsersGuide/dev/os-docs.html#tasks:~:text=suspend()%20was%20issued.-,Not%20available%20on%20all%20operating%20systems.,-wasSuspended()
// Must be manually done using a mutex or other blocking construct as there
// is not top-level pthreads support for suspend and resume.

void Task::suspend(bool onPurpose) {
    FW_ASSERT(0);
}

void Task::resume(void) {
    FW_ASSERT(0);
}

bool Task::isSuspended(void) {
    FW_ASSERT(0);
    return false;
}

//Task joining not available in FreeRTOS:
//https://github.com/nasa/fprime/discussions/978#:~:text=Not%20sure%20if%20this%20is%20a%20place%20to%20ask%20this%20question%20but%20I%27m%20not%20sure%20if%20and%20how%20thread%20joining%20is%20being%20used%20in%20F%27%3F%20Since%20there%20is%20no%20task%20joining%20in%20freeRTOS%2C%20if%20it%27s%20not%20necessary%20then%20I%20could%20just%20skip%20it%20entirely.
//
Task::TaskStatus Task::join(void **value_ptr) {
    FW_ASSERT(0);
    return TASK_OK;
}

//Need Task Registry implementation?

}