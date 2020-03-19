#include <msp430.h>
volatile unsigned int x=0,y=0,delayms=0;

int delay_sec(unsigned int delay)
{
   delayms= delay*1000;
   TA0CCTL0 = CCIE;   // CCR0 interrupt enabled
   TA0CCR0 = 1000-1;
   TA0CTL = TASSEL_2 + MC_1; // SMCLK, contmode
   _BIS_SR(LPM0_bits + GIE); // Enter LPM0 w/ interruptl
   return 0;
}

void main(void)
{
    while(1)
    {
        WDTCTL = WDTPW + WDTHOLD; // Stop WDT
        P1DIR |= BIT2;      //Configure P1.2 as Output

        P1OUT |= BIT2;       //Drive Output High for P1.2
        delay_sec(1);


        P1OUT &= ~BIT2;     //Drive Output Low for P1.2
        delay_sec(1);

    }
}

// Timer A0 interrupt service routine
#pragma vector=TIMER0_A0_VECTOR
__interrupt void Timer_A (void)
{
    x++;
    if(x>delayms)
    {
        x=0;
        __low_power_mode_off_on_exit(); //Stop the interrupt and get back to the function
    }

}
