/*
 * PWM.h
 *
 *  Created on: 17 sep. 2020
 *      Author: manci
 */

#ifndef PWM_H_
#define PWM_H_

#include "gpio_set.h"
#include "struct_base.h"
#include "timers.h"
#include "main.h"

void PWM_pulse(unsigned int T /*us*/,unsigned int voltage);
void PWM_time(unsigned int freq, unsigned int total_time);
void PWM_variable(unsigned int freq /*Hz*/,
		unsigned int percentaje_up,  unsigned int percentaje_down);

#endif /* PWM_H_ */
