//#########################################################################################################
//							Turning on 1.0 on and 4.7 off for 30mins  and vice-versa(with-out interrupt)
//#########################################################################################################
#include <msp430.h>
volatile unsigned int x=0,y=0,delayms=0;

int delay_sec(unsigned int delay)
{
   for(y=0;y<=delay;y++)
   {
    __delay_cycles(1048576);
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
        delay_sec(5);


        P1OUT &= ~BIT0;     //Drive Output Low for P1.0
        P4OUT |= BIT7;      //Drive Output High for P4.7
        delay_sec(5);

    }
}
