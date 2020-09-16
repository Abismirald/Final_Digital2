#ifndef DISTANCE_SENSOR_H
#define DISTANCE_SENSOR_H

#include "main.h"

#define MAX_ECHO_TIME 500000 //0.5 SEGUNDOS
#define TIME_TRIGGER 10 //us
#define uint32_t unsigned int
void distance_sensor_trigger();
void Distance_interrupt(int interrupt);
uint32_t distance_sensor_listen_echo();
uint32_t distance_cm(uint32_t time_echo);

#endif
