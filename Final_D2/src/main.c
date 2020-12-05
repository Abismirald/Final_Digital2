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

/********************** inclusions *******************************************/
#include "main.h"

/********************** macros and definitions *******************************/

/********************** internal data declaration ****************************/

/********************** internal data definition *****************************/

bool GPIO_FLAG=0;

/********************** external data definition *****************************/

/********************** internal functions definition ************************/

/* Init of the peripherics (TIMERS, GPIO, NVIC, DAC) */
status_t PERIPHERAL_init(){

	LED_ALL();
	SCU_init();
	GPIO_init();
	TIMERS_init();
	NVIC_init();

	return OK_ZONE;
}

/********************** external functions definition ************************/
void SCU_init(){
	SCU_SetPin(SCU, SCU_TRIGGER_GROUP, SCU_TRIGGER_PIN, 0);
	SCU_SetPin(SCU, SCU_ECHO_GROUP, SCU_ECHO_PIN, 0);
	SCU_SetPin(SCU, SCU_PWM_GROUP, SCU_PWM_PIN, 0);
	SCU_EnableBuffer(SCU, SCU_ECHO_GROUP, SCU_ECHO_PIN);
	SCU_enablePD_disablePU(SCU,SCU_ECHO_GROUP, SCU_ECHO_PIN);

}

void GPIO_init(){
	GPIO_SetPinDIR(GPIO, GPIO_TRIGGER_PORT, GPIO_TRIGGER_PIN, OUTPUT);
	GPIO_SetPinDIR(GPIO, GPIO_ECHO_PORT, GPIO_ECHO_PIN, INPUT);
	GPIO_SetPinDIR(GPIO, GPIO_PWM_PORT, GPIO_PWM_PIN, OUTPUT);
	GPIO_SetPin(GPIO, GPIO_TRIGGER_PORT, GPIO_TRIGGER_PIN, LOW);
	return;
}

void TIMERS_init(){

	TIMER_init(TIMER0);
	TIMER_init(TIMER1);
	TIMER_SetFrequency(TIMER0, US_FREQ); //set timer to us
	TIMER_SetFrequency(TIMER1, US_FREQ); //set timer to us
	TIMER_reset(TIMER0);
	TIMER_reset(TIMER1);

	return;
}

void NVIC_init(){
	Distance_interrupt(0);
	Select_GPIO_interrupt(GPIO_ECHO_PORT, GPIO_ECHO_PIN, 0);
	Enable_NVIC(PIN_INT0_IRQn);

	return;
}


/********************** Interruption handlers ********************************/

//if an echo signal interrupts
void GPIO0_IRQHandler(void){

	/* Clear interruption pin */
	(PIN_INT->IST)|=(1<<0);

	GPIO_FLAG =! GPIO_FLAG; //not
}


/************************* main loop ******************************************/

int main(void) {

    uint32_t distance=0; //esto generaria que esta pegado al sensor la logica tendria que ser infinito
    status_t status=OK_INIT;


    //Inicialization
    status = PERIPHERAL_init(); //GPIO, TIMERS, UART en alto nivel

    if(status != OK_ZONE){
    	//SAFE MODE
    	while(1){
    		LED_toggle(L1);
    		delay_us(TIMER0, 500000);
    	}
    }

    //Loop principal
    while(1){

    	// ULTRASONIC SENSOR --> get actual distance
    	distance_sensor_trigger();
    	distance = distance_sensor_listen_echo();

    	//ZONES OF ACTION
    	/* The distance determinates the zone of action */
    	if(0<distance && distance<Z1){
    		zone(ZONE_1);
    	}
    	if(Z1<distance && distance<Z2){
    		zone(ZONE_2);
    	}
    	if(Z2<distance && distance<Z3){
    		zone(ZONE_3);
    	}
    	if(Z3<distance){
    		zone(ZONE_OUT);
    	}
    	/* delay between sensing */
    	delay_us(TIMER0, DELAY_TRIGGER);

    }
    return 0;
}

/********************** end of file ******************************************/
