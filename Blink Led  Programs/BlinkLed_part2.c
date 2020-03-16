
//#########################################################################################################
//							Turning on of 2.3 for 5 sec and then off for 10 sec
//#########################################################################################################

#include <msp430.h>
#define delay 1000
unsigned int x=0,y=0,z=0,a=0,b=0,c=0;

void main(void)
{
    while(1)
    {
        WDTCTL = WDTPW + WDTHOLD; // Stop WDT

        P2DIR |= BIT3;		//Configure P7.0 as Output
        P2OUT |= BIT3;      //Drive Output High for P2.3


        TA0CCTL0 = CCIE;   // CCR0 interrupt enabled
        TA0CCR0 = 1000-1;
        TA0CTL = TASSEL_2 + MC_1; // SMCLK, contmode
        _BIS_SR(LPM0_bits + GIE); // Enter LPM0 w/ interrupt
    }
}

// Timer A0 interrupt service routine
#pragma vector=TIMER0_A0_VECTOR
__interrupt void Timer_A (void)
{
    x++;
    y++;

    if(x>5000)
    {
        P2OUT &= ~BIT3;
        x=0;
    }
    if(y>15000)
    {
        P2OUT |= BIT3;
        x=0;
        y=0;
    }


}
