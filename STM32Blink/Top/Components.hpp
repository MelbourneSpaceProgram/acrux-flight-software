#ifndef __LIST_COMPONENTS_HEADER__
#define __LIST_COMPONENTS_HEADER__
#include <Svc/ActiveRateGroup/ActiveRateGroupImpl.hpp>
#include <Svc/RateGroupDriver/RateGroupDriverImpl.hpp>

#include <Svc/CmdDispatcher/CommandDispatcherImpl.hpp>

#include <Svc/ActiveLogger/ActiveLoggerImpl.hpp>

#include <Svc/RTOSTime/RTOSTimeImpl.hpp>

#include <Svc/TlmChan/TlmChanImpl.hpp>
#include <Fw/Obj/SimpleObjRegistry.hpp>
#include <Drv/BlockDriver/BlockDriverImpl.hpp>
#include <Svc/Health/HealthComponentImpl.hpp>
#include <Svc/GroundInterface/GroundInterface.hpp>


#include <Svc/AssertFatalAdapter/AssertFatalAdapterComponentImpl.hpp>
#include <Svc/FatalHandler/FatalHandlerComponentImpl.hpp>

#include <STM32Blink/LedBlinker/LedBlinkerComponentImpl.hpp>
#include <STM32Blink/STM32SerialDriver/STM32SerialDriverComponentImpl.hpp>
#include <STM32Blink/STM32GpioDriver/STM32GpioDriverComponentImpl.hpp>


void constructSTM32BlinkArchitecture(void);
void constructApp();
void exitTasks(void);


extern Svc::RateGroupDriverImpl rateGroupDriverComp;
extern Svc::ActiveRateGroupImpl rateGroup1Comp, rateGroup2Comp, rateGroup3Comp;
extern Svc::ActiveLoggerImpl eventLogger;
extern Svc::TlmChanImpl chanTlm;
extern Svc::CommandDispatcherImpl cmdDisp;
extern Svc::GroundInterfaceComponentImpl ground;
extern Drv::BlockDriverImpl blockDrv;
extern Svc::AssertFatalAdapterComponentImpl fatalAdapter;
extern Svc::FatalHandlerComponentImpl fatalHandler;
extern Svc::HealthImpl health;
extern STM32Blink::STM32SerialDriverComponentImpl serial;
extern STM32Blink::STM32GpioDriverComponentImpl ledDrv;
extern STM32Blink::LedBlinkerComponentImpl blinker;
extern Svc::RTOSTimeImpl RTOSTime;


#endif
