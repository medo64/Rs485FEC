#pragma once

#include <xc.h>


void io_init();

#define io_led_activity_off()     LATC3 = 0
#define io_led_activity_on()      LATC3 = 1
#define io_led_activity_toggle()  LATC3 = !LATC3
