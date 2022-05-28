#include <Components.hpp>
#include <Fw/Logger/Logger.hpp>
#include <Fw/Types/Assert.hpp>
#include <Fw/Types/MallocAllocator.hpp>
#include <Os/Log.hpp>
#include <Os/Task.hpp>

#if defined TGT_OS_TYPE_LINUX || TGT_OS_TYPE_DARWIN
#include <ctype.h>
#include <getopt.h>
#include <stdlib.h>
#endif

// List of context IDs

Os::Log osLogger;

// Registry
#if FW_OBJECT_REGISTRATION == 1
static Fw::SimpleObjRegistry simpleReg;
#endif

// Component instance pointers
static NATIVE_INT_TYPE rgDivs[Svc::RateGroupDriverImpl::DIVIDER_SIZE] = {1, 2, 4};
Svc::RateGroupDriverImpl rateGroupDriverComp(FW_OPTIONAL_NAME("RGDvr"), rgDivs, FW_NUM_ARRAY_ELEMENTS(rgDivs));

static NATIVE_UINT_TYPE rg1Context[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
Svc::ActiveRateGroupImpl rateGroup1Comp(FW_OPTIONAL_NAME("RG1"), rg1Context, FW_NUM_ARRAY_ELEMENTS(rg1Context));

static NATIVE_UINT_TYPE rg2Context[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
Svc::ActiveRateGroupImpl rateGroup2Comp(FW_OPTIONAL_NAME("RG2"), rg2Context, FW_NUM_ARRAY_ELEMENTS(rg2Context));

static NATIVE_UINT_TYPE rg3Context[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
Svc::ActiveRateGroupImpl rateGroup3Comp(FW_OPTIONAL_NAME("RG3"), rg3Context, FW_NUM_ARRAY_ELEMENTS(rg3Context));

// Driver Component
Drv::BlockDriverImpl blockDrv(FW_OPTIONAL_NAME("BDRV"));

// Reference Implementation Components

Svc::ActiveLoggerImpl eventLogger(FW_OPTIONAL_NAME("ELOG"));

Svc::TlmChanImpl chanTlm(FW_OPTIONAL_NAME("TLM"));

Svc::CommandDispatcherImpl cmdDisp(FW_OPTIONAL_NAME("CMDDISP"));

Fw::MallocAllocator mallocator;

Svc::HealthImpl health(FW_OPTIONAL_NAME("health"));

Svc::AssertFatalAdapterComponentImpl fatalAdapter(FW_OPTIONAL_NAME("fatalAdapter"));

Svc::FatalHandlerComponentImpl fatalHandler(FW_OPTIONAL_NAME("fatalHandler"));

Svc::GroundInterfaceComponentImpl ground(FW_OPTIONAL_NAME("ground"));

STM32Blink::STM32SerialDriverComponentImpl serial(FW_OPTIONAL_NAME("serial"));

STM32Blink::STM32GpioDriverComponentImpl ledDrv(FW_OPTIONAL_NAME("ledDrv"));

Svc::RTOSTimeImpl RTOSTime(FW_OPTIONAL_NAME("RTOSTime"));

STM32Blink::LedBlinkerComponentImpl blinker(FW_OPTIONAL_NAME("blinker"));

const char* getHealthName(Fw::ObjBase& comp) {
#if FW_OBJECT_NAMES == 1
    return comp.getObjName();
#else
    return "[no object name]"
#endif
}

void constructApp() {
    rateGroupDriverComp.init();

    // Initialize the rate groups
    rateGroup1Comp.init(10, 0);

    rateGroup2Comp.init(10, 1);

    rateGroup3Comp.init(10, 2);

    // Initialize block driver
    blockDrv.init(10);

    // Send/Receive example hardware components

    eventLogger.init(10, 0);

    RTOSTime.init(0);

    chanTlm.init(10, 0);

    cmdDisp.init(20, 0);

    fatalAdapter.init(0);
    fatalHandler.init(0);
    health.init(25, 0);
    ground.init(0);
    blinker.init(0);
    serial.init(0);
    ledDrv.init(0);

    // Connect rate groups to rate group driver
    constructSTM32BlinkArchitecture();

    // dump topology if requested

    /* Register commands */
    cmdDisp.regCommands();
    eventLogger.regCommands();
    health.regCommands();

    // read parameters
    // set up BufferManager instances

    // set health ping entries

    Svc::HealthImpl::PingEntry pingEntries[] = {
        {3, 5, getHealthName(rateGroup1Comp)},  // 0
        {3, 5, getHealthName(rateGroup2Comp)},  // 1
        {3, 5, getHealthName(rateGroup3Comp)},  // 2
        {3, 5, getHealthName(cmdDisp)},         // 3
        {3, 5, getHealthName(eventLogger)},     // 4
        {3, 5, getHealthName(chanTlm)},         // 6
        {3, 5, getHealthName(blockDrv)},        // 10
    };

    // register ping table
    health.setPingEntries(pingEntries, FW_NUM_ARRAY_ELEMENTS(pingEntries), 0x123);

    // Active component startup
    // start rate groups
    rateGroup1Comp.start(
        static_cast<NATIVE_UINT_TYPE>(120),
        static_cast<NATIVE_UINT_TYPE>(10 * 1024),
        Os::Task::TASK_DEFAULT,  // Default CPU
        static_cast<NATIVE_UINT_TYPE>(10));
    rateGroup2Comp.start(
        static_cast<NATIVE_UINT_TYPE>(119),
        static_cast<NATIVE_UINT_TYPE>(10 * 1024),
        Os::Task::TASK_DEFAULT,  // Default CPU
        static_cast<NATIVE_UINT_TYPE>(11));
    rateGroup2Comp.start(
        static_cast<NATIVE_UINT_TYPE>(118),
        static_cast<NATIVE_UINT_TYPE>(10 * 1024),
        Os::Task::TASK_DEFAULT,  // Default CPU
        static_cast<NATIVE_UINT_TYPE>(12));
    // start driver
    blockDrv.start(
        static_cast<NATIVE_UINT_TYPE>(98),
        static_cast<NATIVE_UINT_TYPE>(10 * 1024),
        Os::Task::TASK_DEFAULT,  // Default CPU
        static_cast<NATIVE_UINT_TYPE>(0));
    // start dispatcher
    cmdDisp.start(
        static_cast<NATIVE_UINT_TYPE>(101),
        static_cast<NATIVE_UINT_TYPE>(10 * 1024),
        Os::Task::TASK_DEFAULT,  // Default CPU
        static_cast<NATIVE_UINT_TYPE>(1));
    // start sequencer
    // start telemetry
    eventLogger.start(
        static_cast<NATIVE_UINT_TYPE>(98),
        static_cast<NATIVE_UINT_TYPE>(10 * 1024),
        Os::Task::TASK_DEFAULT,  // Default CPU
        static_cast<NATIVE_UINT_TYPE>(2));
    chanTlm.start(
        static_cast<NATIVE_UINT_TYPE>(97),
        static_cast<NATIVE_UINT_TYPE>(10 * 1024),
        Os::Task::TASK_DEFAULT,  // Default CPU
        static_cast<NATIVE_UINT_TYPE>(3));
    ledDrv.open();
}

void exitTasks(void) {
    rateGroup1Comp.exit();
    rateGroup2Comp.exit();
    rateGroup3Comp.exit();
    blockDrv.exit();
    cmdDisp.exit();
    eventLogger.exit();
    chanTlm.exit();
    // join the component threads with NULL pointers to free them
    (void)rateGroup1Comp.ActiveComponentBase::join(NULL);
    (void)rateGroup2Comp.ActiveComponentBase::join(NULL);
    (void)rateGroup3Comp.ActiveComponentBase::join(NULL);
    (void)blockDrv.ActiveComponentBase::join(NULL);
    (void)cmdDisp.ActiveComponentBase::join(NULL);
    (void)eventLogger.ActiveComponentBase::join(NULL);
    (void)chanTlm.ActiveComponentBase::join(NULL);
}
