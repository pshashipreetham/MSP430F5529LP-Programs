//#########################################################################################################
//							Turning on 1.0 on and 4.7 off for 30mins  and vice-versa
//#########################################################################################################
#include <msp430.h>
volatile unsigned int x=0,y=0,delayms=0;

int delayMs(unsigned int delay)
{
   delayms=2000+delay;
   for(y=0;y<=30;y++)
   {
    TA0CCTL0 = CCIE;   // CCR0 interrupt enabled
    TA0CCR0 = 1000-1;
    TA0CTL = TASSEL_2 + MC_1; // SMCLK, contmode
    _BIS_SR(LPM0_bits + GIE); // Enter LPM0 w/ interruptl
   }
    return 0;
}

void main(void)
{
    while(1)
    {
        WDTCTL = WDTPW + WDTHOLD; // Stop WDT
        P1DIR |= BIT0;      //Configure P1.0 as Output
        P4DIR |= BIT7;      //Configure P4.7 as Output

        P1OUT |= BIT0;       //Drive Output High for P1.0
        P4OUT &= ~BIT7;     //Drive Output Low for P4.7
        delayMs(60000);


        P1OUT &= ~BIT0;     //Drive Output Low for P1.0
        P4OUT |= BIT7;      //Drive Output High for P4.7
        delayMs(60000);

    }
}

// Timer A0 interrupt service routine
#pragma vector=TIMER0_A0_VECTOR
__interrupt void Timer_A (void)
{
    x++;
    if(x>60000)
    {
        x=0;
        __low_power_mode_off_on_exit();
    }

}
