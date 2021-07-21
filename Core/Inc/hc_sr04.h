/*
 * hc_sr04.h
 *
 *  Created on: Jul 19, 2021
 *      Author: Igor_S
 */

#ifndef INC_HC_SR04_H_
#define INC_HC_SR04_H_

#include "tim.h"

// Sensor pins and Timers to define

#define TIMER_IC &htim1 // timer for Input Capture mode
#define TIMER_DELAY &htim3 // timer for internal delay in us
#define TRIG_PIN GPIO_PIN_9
#define ECHO_PIN GPIO_PIN_8
#define TRIG_PORT GPIOA
#define ECHO_PORT GPIOA

volatile uint16_t IC_RisingEdge;
volatile uint16_t pulse_time;
volatile uint8_t measure_flag;


// function declarations
void delay_us(uint16_t us);
uint16_t HCSR04_get_distance_cm();

#endif /* INC_HC_SR04_H_ */
