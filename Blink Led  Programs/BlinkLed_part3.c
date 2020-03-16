//#########################################################################################################
//							Turning on 7.0 and 7.4 for 10 sec and Truining off for 10 sec
//#########################################################################################################

#include <msp430.h>
#define delay 1000
unsigned int x=0,y=0,z=0,a=0,b=0,c=0;

void main(void)
{
    while(1)
    {
        WDTCTL = WDTPW + WDTHOLD; // Stop WDT

        P7DIR |= BIT0; //Configure P7.0 as Output
        P7DIR |= BIT4; //Configure P7.0 as Output
        P7OUT |= BIT0; //Drive Output High for P7.0
        P7OUT |= BIT4; //Drive Output High for P7.4

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

    if(x>10000)
    {
        P7OUT &= ~BIT0;
        P7OUT &= ~BIT4;
        x=0;
    }
    if(y>20000)
    {
        P7OUT |= BIT0;
        P7OUT |= BIT4;
        x=0;
        y=0;
    }


}
