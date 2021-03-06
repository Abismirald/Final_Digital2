/*
===============================================================================
 Name        : Final_D2_LPCOpen.c
 Author      : Sasha y solo sasha
 Version     :
 Copyright   : $(copyright)
 Description : main definition
===============================================================================
*/

#include "chip.h"

#include <cr_section_macros.h>

#include "main.h"
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

#define DELAY_TRIGGER 5 //se puede variar

#define Z1		80		//cm
#define Z2		150		//cm
#define Z3		250		//cm

bool GPIO_FLAG=0;

status_t PERIPHERAL_init(){
	//en esta funcion se inician todos los perifericos (TIMERS, GPIO, UART)
	LED_ALL();
	DAC_init();
	SCU_init();
	GPIO_init();
	TIMERS_init();
	//UART_init();
//	NVIC_init();

	return OK_ZONE;
}

void DAC_init(){
	Enable_DAC();
	//Values_DAC(0);
	//Chip_DAC_Init(LPC_DAC);
}

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
	TIMER_SetFrequency(TIMER0, US_FREQ); //set timer to us
	TIMER_reset(TIMER0);

	return;
}
//void NVIC_init(){
//	Enable_PIN_INT(0);
//	Select_GPIO_interrupt(GPIO_ECHO_PORT, GPIO_ECHO_PIN, 0);
//	Enable_NVIC(PIN_INT0_IRQn);
//
//	return;
//}



int main(void) {


	status_t status=OK_INIT;
	//int time=0;
    status = PERIPHERAL_init(); //GPIO, TIMERS, PWM/DAC, UART en alto nivel
    if(status != OK_INIT){
    	//MODO MANTENIMIENTO
    }
    /* frec 10kHz => 100us*/
    PWM_pulse(10, 2); //con 2 da 3.57 V O-O
    //con 3 da 2.92 y anda con 1 da 0.7 no anda como era de esperarse
    //GPIO_SetPin(GPIO, GPIO_PWM_PORT, GPIO_PWM_PIN, HIGH);
    while(1){

//    	PWM_time(1000, 2);

    	//PWM_variable(1000, 0.8, 0.2);
    }

    return 0;
}


