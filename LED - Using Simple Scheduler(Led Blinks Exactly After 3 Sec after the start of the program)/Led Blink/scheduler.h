/*
 * scheduler.h
 *
 *  Created on: 30-Apr-2020
 *      Author: psp
 */

#ifndef SCHEDULER_H_
#define SCHEDULER_H_


typedef struct Task{
    unsigned long period;       // How oftern it should happen in time ticks
    unsigned long elapsedTime;  // Keep the tack of how many timer ticks have elapsed

}Task;
void scheduler_execute_task(void);


#endif /* SCHEDULER_H_ */
