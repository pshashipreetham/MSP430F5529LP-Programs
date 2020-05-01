#include <msp430.h> 
#include "timer.h"

int main(void)
{
	WDTCTL = WDTPW | WDTHOLD;	// stop watchdog timer
	P1DIR |= 0x01;
	
	timer_init();

	__bis_SR_register(LPM0_bits + GIE);

}


