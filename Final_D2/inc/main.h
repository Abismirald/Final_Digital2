/*
 * Copyright (c) 2020
 * Lucas Mancini <mancinilucas95@gmail.com>.
 * Sasha Muscio <sashamuscio@gmail.com>
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * 3. Neither the name of the copyright holder nor the names of its
 *    contributors may be used to endorse or promote products derived from
 *    this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 * COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
 * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING
 * IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 * @file	app_hmi.cpp
 * @date	2020-3-12
 * @author:
 *  - LM		Lucas Mancini <mancinilucas95@gmail.com>.
 *  - SM 		Sasha Muscio <sashamuscio@gmail.com>.
 * @version	v1.3.2 - Camel
 */

#ifndef MAIN_H
#define MAIN_H

/********************** inclusions *******************************************/

#include <math.h>
#include <stdbool.h>
#include "distance_sensor.h"
#include "gpio_set.h"
#include "interruptions.h"
#include "leds_setup.h"
#include "scu_set.h"
#include "status.h"
#include "zones.h"
#include "struct_base.h"
#include "tec_setup.h"
#include "timers.h"
#include "PWM.h"

/********************** macros ***********************************************/

#define GPIO_TRIGGER_PORT 3 //TRIGGER => GPIO0
#define GPIO_TRIGGER_PIN 0
#define GPIO_ECHO_PORT 3	//ECHO => GPIO2
#define GPIO_ECHO_PIN 4
#define GPIO_PWM_PORT	3	//PWM => GPIO1
#define GPIO_PWM_PIN	3
#define	SCU_TRIGGER_GROUP 6
#define	SCU_TRIGGER_PIN 1
#define	SCU_ECHO_GROUP 6
#define	SCU_ECHO_PIN 5
#define SCU_PWM_GROUP	6
#define SCU_PWM_PIN		4
#define DELAY_TRIGGER 7 //delay between samples

#define Z1	  80 //testing => 10
#define Z2		150 //testing => 20
#define Z3		250 //testing => 30

#define uint32_t unsigned int

/********************** typedef **********************************************/

/********************** external data declaration ****************************/

/********************** external functions declaration ***********************/
void SCU_init();
void GPIO_init();
void TIMERS_init();
void NVIC_init();
//handler de interrupcion --> void GPIO0_IRQHandler(void)

#endif

/********************** end of file ******************************************/
