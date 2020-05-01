/*
 * led.c
 *
 *  Created on: 30-Apr-2020
 *      Author: psp
 */


#include "led.h"
#include <msp430.h>

void led_init(void)
{
    P1DIR |= BIT0;
    P4DIR |= BIT7;

    led_green_off();
    led_red_off();
}
void led_toggle(void)
{
    P1OUT ^= 0x01;
}

void led_green_on(void)
{
    P4OUT |= BIT7;
}

void led_red_on(void)
{
    P1OUT |= BIT0;
}
void led_green_off(void)
{
    P4OUT &= ~BIT7;
}

void led_red_off(void)
{
    P1OUT &= ~BIT0;
}
