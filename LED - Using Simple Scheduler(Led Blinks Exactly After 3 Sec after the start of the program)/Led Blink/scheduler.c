/*
 * scheduler.c
 *
 *  Created on: 30-Apr-2020
 *      Author: psp316r(Shashi Preetham)
 */


#include "led.h"
#include "scheduler.h"

extern struct Task ledTimingTask;

void scheduler_execute_task(void)
{
    ledTimingTask.elapsedTime++;
    if(ledTimingTask.elapsedTime >= ledTimingTask.period)
    {
        led_red_on();
        led_green_on();
    }
}
