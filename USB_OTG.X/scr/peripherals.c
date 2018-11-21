#include <xc.h>
#include <plib.h>
#include <proc/p32mx440f256h.h>
#include "hw_profile.h"
#include "peripherals.h"
#include "pic32_uart.h"
#include "pic32_usb.h"
#include "pic32_timers.h"
	

void pheripherals_leds_init(void )
{
	mPORTDSetPinsDigitalOut(BIT_1);
}

void pheripherals_init(void)
{
	SYSTEMConfig(GetSystemClock(), SYS_CFG_WAIT_STATES | SYS_CFG_PCACHE);
	timers_coretimer_setup();  
 	initialize_UART_x(UART2,115200);
	pheripherals_leds_init();
}




