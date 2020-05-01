/*
 * timer.c
 *
 *  Created on: 30-Apr-2020
 *      Author: psp316r (Shashi Preetham)
 */

#include "timer.h"
#include "led.h"
#include <msp430.h>

unsigned int timercount = 0;
extern unsigned char ledToggleFlag;
extern unsigned char executeTaskFlag;
void timer_init(void)
{
    TA0CTL |= 0x0100;    // Choose ACLK
    TA0CTL |= 0x0010;    // Count up mode
    TA0CTL |= 0x0004;    // Clear the Timer

    TA0CCR0 = 4096;       // Set capture and control threshold to 1/8th of the second.
    TA0CCTL0 |= 0x0010;  // Enable interrupt in capture and control register.

}
#pragma vector = TIMER0_A0_VECTOR
__interrupt void TIMER_AO_ISR(void)
{
    timercount++;

    if(timercount >= 8)
    {
        timercount = 0;

        ledToggleFlag = 1;

    }

    executeTaskFlag = 1;

    //Wake Up
    __bic_SR_register_on_exit(LPM0_bits);

}

