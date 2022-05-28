#include <Fw/Types/Assert.hpp>
#include <Os/Queue.hpp>
#include <NucleoH7_freeRTOS/Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2/cmsis_os.h>

namespace Os {

    
    Queue::Queue() :
        m_handle(-1) {
    }

    Queue::QueueStatus Queue::createInternal(const Fw::StringBase &name, NATIVE_INT_TYPE depth, NATIVE_INT_TYPE msgSize) {

        this->m_name = "/QP_";
        this->m_name += name;
        QueueHandle_t xQueue
        UBaseType_t uxQueueLength = depth;
        UBaseType_t uxItemSize = msgSize;

        xQueue = xQueueCreate(uxQueueLength,uxItemSize);
        
        if (NULL == xQueue) {
          return QUEUE_UNINITIALIZED;
        }
        this->m_handle = (POINTER_CAST) xQueue;
        
        Queue::s_numQueues++;

        return QUEUE_OK;
    }

    Queue::~Queue() {
        vQueueDelete(this->m_handle);
        delete 
    }

    Queue::QueueStatus Queue::send(const U8* buffer, NATIVE_INT_TYPE size, NATIVE_INT_TYPE priority, QueueBlocking block) {

        QueueHandle_t* queueHandle = (QueueHandle_t*) this->m_handle;

        if (-1 == handle) {
            return QUEUE_UNINITIALIZED;
        }
        
        if (NULL == buffer) {
            return QUEUE_EMPTY_BUFFER;
        }

        bool keepTrying = true;
        
        while (keepTrying) {
            BaseType_t stat = xQueueSend(queueHandle, buffer, 5);
            if (stat == errQUEUE_FULL){
                return QUEUE_FULL;
            }else if (stat ==pdTRUE){
                keepTrying = false;
            }
            
        }
       
        return QUEUE_OK;
    }

    Queue::QueueStatus Queue::receive(U8* buffer, NATIVE_INT_TYPE capacity, NATIVE_INT_TYPE &actualSize, NATIVE_INT_TYPE &priority, QueueBlocking block) {

        QueueHandle_t* queueHandle = (QueueHandle_t*) this->m_handle;


        if (-1 == handle) {
            return QUEUE_UNINITIALIZED;
        }


        bool notFinished = true;
        while (notFinished) {
            BaseType_t stat = xQueueReceive(queueHandle, buffer, 5);

            if (stat == pdFALSE){
                        return QUEUE_UNKNOWN_ERROR;
                }
            else {
                notFinished = false;
            }
        }

        actualSize = (NATIVE_INT_TYPE) capacity;
        return QUEUE_OK;
    }

    NATIVE_INT_TYPE Queue::getNumMsgs(void) const {
        QueueHandle_t* queueHandle = (QueueHandle_t*) this->m_handle;
        UBaseType_t numMsg;
        numMsg = uxQueueMessagesWaiting(queueHandle);

        return (U32) numMsg;
    }

    NATIVE_INT_TYPE Queue::getMaxMsgs(void) const {
        //FW_ASSERT(0);
        return 0;
    }

    NATIVE_INT_TYPE Queue::getQueueSize(void) const {
        QueueHandle_t* queueHandle = (QueueHandle_t*) this->m_handle;
        return (U32)(uxQueueMessagesWaiting(queueHandle)+uxQueueSpacesAvailable(queueHandle));
    }

    NATIVE_INT_TYPE Queue::getMsgSize(void) const {
        return 0;
    }

}

