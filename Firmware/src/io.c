#include <xc.h>

void io_init() {
    LATC3 = 0;  // start with Active off
    TRISC3 = 0; // enable Active
}
