#include <Fw/Types/Assert.hpp>
#include <Os/Queue.hpp>
#include <stm32-bsp/Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2/cmsis_os.h>

namespace Os
{

Queue::Queue() :
        m_handle(NULL) 
{}

Queue::~Queue() 
{
    vQueueDelete(this->m_handle);
}

Queue::QueueStatus 
Queue::createInternal(const Fw::StringBase &name, NATIVE_INT_TYPE depth, NATIVE_INT_TYPE msgSize) 
{
    this->m_name = "/QP_";
    this->m_name += name;
    QueueHandle_t xQueue;
    UBaseType_t uxQueueLength = depth;
    UBaseType_t uxItemSize = msgSize;

    xQueue = xQueueCreate(uxQueueLength,uxItemSize);
    
    if (NULL == xQueue) 
    {
        return QUEUE_UNINITIALIZED;
    }
    this->m_handle = xQueue;
    
    Queue::s_numQueues++;

    return QUEUE_OK;
}

Queue::QueueStatus 
Queue::send(const U8* buffer, NATIVE_INT_TYPE size, NATIVE_INT_TYPE priority, QueueBlocking block) 
{

    QueueHandle_t queueHandle = this->m_handle;

    if (NULL == queueHandle) 
    {
        return QUEUE_UNINITIALIZED;
    }
    
    if (NULL == buffer) 
    {
        return QUEUE_EMPTY_BUFFER;
    }

    bool keepTrying = true;
    
    while (keepTrying) 
    {
        BaseType_t stat = xQueueSend(queueHandle, buffer, 5);
        if (stat == errQUEUE_FULL)
        {
            return QUEUE_FULL;
        }
        else if (stat == pdTRUE)
        {
            keepTrying = false;
        }
        
    }
    
    return QUEUE_OK;
}

Queue::QueueStatus 
Queue::receive(U8* buffer, NATIVE_INT_TYPE capacity, NATIVE_INT_TYPE &actualSize, NATIVE_INT_TYPE &priority, QueueBlocking block) 
{

    QueueHandle_t queueHandle = this->m_handle;

    if (NULL == queueHandle) 
    {
        return QUEUE_UNINITIALIZED;
    }

    bool notFinished = true;
    while (notFinished) 
    {
        BaseType_t stat = xQueueReceive(queueHandle, buffer, 5);

        if (stat == pdFALSE)
        {
            return QUEUE_RECEIVE_ERROR; //rawinza used QUEUE_UNKNOWN_ERROR
        }
        else 
        {
            notFinished = false;
        }
    }

    actualSize = (NATIVE_INT_TYPE) capacity; //TODO Need a way to find actual size??
    return QUEUE_OK;
}

NATIVE_INT_TYPE 
Queue::getNumMsgs(void) const 
{
    QueueHandle_t queueHandle = this->m_handle;
    if (NULL == queueHandle) 
    {
        return QUEUE_UNINITIALIZED;
    }

    UBaseType_t numMsg;
    numMsg = uxQueueMessagesWaiting(queueHandle);

    return (U32) numMsg;
}

/**
*   The max number of items that has been in the queue, the "high water mark". This is not available in FreeRTOS
*/
NATIVE_INT_TYPE 
Queue::getMaxMsgs(void) const 
{
    //FW_ASSERT(0);
    return 0;
}

NATIVE_INT_TYPE 
Queue::getQueueSize(void) const 
{
    QueueHandle_t queueHandle = this->m_handle;
    if (NULL == queueHandle) 
    {
        return QUEUE_UNINITIALIZED;
    }

    return (U32)(uxQueueMessagesWaiting(queueHandle)+uxQueueSpacesAvailable(queueHandle));
}

NATIVE_INT_TYPE Queue::getMsgSize(void) const 
{
    QueueHandle_t queueHandle = this->m_handle;
    if (NULL == queueHandle) 
    {
        return QUEUE_UNINITIALIZED;
    }

    //TODO to get actual msg size, or FreeRTOS doesn't support?

    return 0;
}

} // namespace Os
