#include <Os/Mutex.hpp>
#include <Fw/Types/Assert.hpp>
#include <NucleoH7_freeRTOS/Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2/cmsis_os.h>

namespace Os {
    
    Mutex::Mutex(void) {
        SemaphoreHandle_t handle;

        handle = xSemaphoreCreateMutex( void );
        
        this->m_handle = (POINTER_CAST) handle;
    }
    
    Mutex::~Mutex(void) {
        vSemaphoreDelete(this->m_handle);
        delete this->m_handle;
    }
    
    void Mutex::lock(void) {
        NATIVE_INT_TYPE stat = xSemaphoreTake( this->m_handle, ( TickType_t ) 10 );
        FW_ASSERT(stat == pdTRUE,stat);
    }

    void Mutex::unLock(void) {
        NATIVE_INT_TYPE stat = xSemaphoreGive( this->m_handle, ( TickType_t ) 10 );
        FW_ASSERT(stat == pdTRUE,stat);
    }
            
}


