#include <stdint.h>
#include "Microchip/usb.h"
#include "Microchip/usb_device.h"
#include "Microchip/usb_device_cdc.h"
#include "buffer.h"
#include "io.h"
#include "timer0.h"
#include "settings.h"
#include "system.h"

void main(void) {
    init();
    io_init();
    timer0_init();

    io_led_activity_on(); timer0_waitTick(); io_led_activity_off(); timer0_waitTick();
    io_led_activity_on(); timer0_waitTick(); io_led_activity_off(); timer0_waitTick();
    io_led_activity_on();

    settings_init();
    
#if defined(USB_INTERRUPT)
    interruptsEnable();
#endif
    
    USBDeviceInit();
    USBDeviceAttach();

    io_led_activity_off();
    
    while(true) {
        if (timer0_wasTriggered()) { io_led_activity_off(); }

#if defined(USB_POLLING)
        USBDeviceTasks();
#endif

        if (USBGetDeviceState() < CONFIGURED_STATE) { continue; }
        if (USBIsDeviceSuspended()) { continue; }

        CDCTxService();

        // USB receive
        uint8_t readCount = getsUSBUSART(UsbReadBuffer, USB_READ_BUFFER_MAX); //until the buffer is free.
        if (readCount > 0) {
            io_led_activity_on(); timer0_reset();
            for (uint8_t i = 0; i < readCount; i++) {  // copy to buffer
                uint8_t value = UsbReadBuffer[i];
                if (InputBufferCorrupted && ((value == 0x0A) || (value == 0x0D))) {
                    InputBufferCount = 0;  // clear the whole buffer
                    InputBufferCorrupted = false;
                } else if (InputBufferCount < INPUT_BUFFER_MAX) {
                    InputBuffer[InputBufferCount] = value;
                    InputBufferCount++;
                } else {
                    InputBufferCorrupted = true;  // no more buffer; darn it
                }
            }
        }

        // USB send
        if ((OutputBufferCount > 0) && USBUSARTIsTxTrfReady()) {  // send output if TX is ready
            io_led_activity_on(); timer0_reset();
            uint8_t writeCount = 0;
            for (uint8_t i = 0; i < USB_WRITE_BUFFER_MAX; i++) {  // copy to output buffer
                if (i < OutputBufferCount) {
                    UsbWriteBuffer[i] = OutputBuffer[i];
                    writeCount++;
                } else {
                    break;
                }
            }
            if (writeCount > 0) {
                putUSBUSART(&UsbWriteBuffer[0], writeCount);  // send data
                OutputBufferCount -= writeCount;  // reduce buffer for the length used
                buffer_copy(&OutputBuffer[0], &OutputBuffer[writeCount], OutputBufferCount);  // move buffer content to beginning
            }
        }
    }
}


#if defined(USB_INTERRUPT)
void __interrupt() SYS_InterruptHigh(void) {
    USBDeviceTasks();
}
#endif
