#ifndef MAIN_H
#define MAIN_H

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
#include "vibrator.h"
#include "dac.h"
#include "PWM.h"

#define GPIO_TRIGGER_PORT 3 //para el Trigger usamos GPIO0
#define GPIO_TRIGGER_PIN 0
#define GPIO_ECHO_PORT 3	//para el echo usamos GPIO2
#define GPIO_ECHO_PIN 4
#define GPIO_PWM_PORT	3	//para el PWM usamos GPIO1
#define GPIO_PWM_PIN	3
#define	SCU_TRIGGER_GROUP 6
#define	SCU_TRIGGER_PIN 1
#define	SCU_ECHO_GROUP 6
#define	SCU_ECHO_PIN 5
#define SCU_PWM_GROUP	6
#define SCU_PWM_PIN		4

#define uint32_t unsigned int

void DAC_init();
void SCU_init();
void GPIO_init();
void TIMERS_init();
void NVIC_init();
//handler de interrupcion --> void GPIO0_IRQHandler(void)


#endif
