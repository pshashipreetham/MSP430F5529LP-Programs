/*
 * led.c
 *
 *  Created on: 30-Apr-2020
 *      Author: psp
 */


#include "led.h"
#include <msp430.h>

void led_toggle(void)
{
    P1OUT ^= 0x01;
}

