#include <msp430.h> 
#include "timer.h"
#include "led.h"
unsigned char ledToggleFlag = 0;

int main(void)
{
	WDTCTL = WDTPW | WDTHOLD;	// stop watchdog timer
	P1DIR |= 0x01;
	
	timer_init();
	while(1)
	{
	    if(ledToggleFlag == 1)
	    {
	        ledToggleFlag = 0;
	        led_toggle();
	    }
	    //Go to Sleep
	    __bis_SR_register(LPM0_bits + GIE);
	}



}


