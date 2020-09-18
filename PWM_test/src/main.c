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

#define GPIO_TRIGGER_PORT 3 //para el Trigger usamos GPIO0
#define GPIO_TRIGGER_PIN 0
#define GPIO_ECHO_PORT 3	//para el echo usamos GPIO2
#define GPIO_ECHO_PIN 4
#define	SCU_TRIGGER_GROUP 6
#define	SCU_TRIGGER_PIN 1
#define	SCU_ECHO_GROUP 6
#define	SCU_ECHO_PIN 5
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
	SCU_EnableBuffer(SCU, SCU_ECHO_GROUP, SCU_ECHO_PIN);
	SCU_DisableGlitchFilter(SCU, SCU_ECHO_GROUP, SCU_ECHO_PIN); //checkear si hay que usarlo o no
	SCU_enablePD_disablePU(SCU,SCU_ECHO_GROUP, SCU_ECHO_PIN);
}

void GPIO_init(){
	GPIO_SetPinDIR(GPIO, GPIO_TRIGGER_PORT, GPIO_TRIGGER_PIN, OUTPUT);
	GPIO_SetPinDIR(GPIO, GPIO_ECHO_PORT, GPIO_ECHO_PIN, INPUT);
	GPIO_SetPin(GPIO, GPIO_TRIGGER_PORT, GPIO_TRIGGER_PIN, LOW);
	return;
}

void TIMERS_init(){

	TIMER_init(TIMER0);
	TIMER_SetFrequency(TIMER0, US_FREQ); //set timer to us
	TIMER_reset(TIMER0);

	//	Chip_TIMER_Init(LPC_TIMER0);
//	Chip_TIMER_SetMatch(LPC_TIMER0, MATCH(0), SystemCoreClock*0.00001);//Trigger 10us
//	Chip_TIMER_SetMatch(LPC_TIMER1, MATCH(0), SystemCoreClock*0.0000005);//Sampleo 0.5us

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
	int time=0;
    status = PERIPHERAL_init(); //GPIO, TIMERS, PWM/DAC, UART en alto nivel
    if(status != OK_INIT){
    	//MODO MANTENIMIENTO
    }

    while(1){

    	PWM_time(1000, 2);
    	//PWM_variable(1000, 0.8, 0.2);
    }

    return 0;
}


