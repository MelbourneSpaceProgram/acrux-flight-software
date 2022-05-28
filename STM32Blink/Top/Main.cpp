#include <getopt.h>
#include <stdlib.h>
#include <ctype.h>

#include <STM32Blink/Top/Components.hpp>


#include <signal.h>
#include <stdio.h>



void run1cycle(void) {
    // call interrupt to emulate a clock
    blockDrv.callIsr();
    Os::Task::delay(1000); //10Hz
}

void runcycles(NATIVE_INT_TYPE cycles) {
    if (cycles == -1) {
        while (true) {
            run1cycle();
        }
    }

    for (NATIVE_INT_TYPE cycle = 0; cycle < cycles; cycle++) {
        run1cycle();
    }
}

int main(int argc, char* argv[]) {
    int cycle = 0;
    
    constructApp();
    while (1) {
//        (void) printf("Cycle %d\n",cycle);
        runcycles(1);
        cycle++;
    }



    return 0;
}
