#include <msp430.h> 

unsigned int timercount = 0;

int main(void)
{
	WDTCTL = WDTPW | WDTHOLD;	// stop watchdog timer
	P1DIR |= 0x01;
	TA0CTL |= 0x0100;    // Choose ACLK
	TA0CTL |= 0x0010;    // Count up mode
	TA0CTL |= 0x0004;    // Clear the Timer
	
	TA0CCR0 = 4096;       // Set capture and control threshold to 1/8th of the second.
	TA0CCTL0 |= 0x0010;  // Enable interrupt in capture and control register.
	__bis_SR_register(LPM0_bits + GIE);

}

#pragma vector = TIMER0_A0_VECTOR
__interrupt void TIMER_AO_ISR(void)
{
    timercount++;

    if(timercount >= 8)
    {
        timercount = 0;

        P1OUT ^= 0x01;
    }

}
