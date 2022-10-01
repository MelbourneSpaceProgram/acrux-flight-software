#include <Os/InterruptLock.hpp>
#include <Os/Mutex.hpp>
#include <stm32-bsp/Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2/cmsis_os.h>
STATIC Os::Mutex intLockEmulator;

namespace Os {
    InterruptLock::InterruptLock() : m_key(0) {}
    InterruptLock::~InterruptLock() {}
    
    void InterruptLock::lock(void) {
        intLockEmulator.lock();
    }

    void InterruptLock::unLock(void) {
        intLockEmulator.unLock();
    }
    
        
}
