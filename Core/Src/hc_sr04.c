/*
 * hc_sr04.c
 *
 *  Created on: Jul 19, 2021
 *      Author: igur
 */

#include "main.h"
#include "hc_sr04.h"


void delay_us(uint16_t us)
{
	HAL_TIM_Base_Start(TIMER_DELAY);
	__HAL_TIM_SET_COUNTER(TIMER_DELAY,0);
	while(__HAL_TIM_GET_COUNTER(TIMER_DELAY) < us);
}


static void set_trigger()
{
	HAL_GPIO_WritePin(TRIG_PORT, TRIG_PIN, GPIO_PIN_SET);
	delay_us(10);
	HAL_GPIO_WritePin(TRIG_PORT, TRIG_PIN, GPIO_PIN_RESET);
}

static uint16_t HCSR04_get_measure()
{
	HAL_TIM_IC_Start_IT(TIMER_IC, TIM_CHANNEL_1);
	HAL_TIM_IC_Start_IT(TIMER_IC, TIM_CHANNEL_2);

	measure_flag = 1; // when measure is finished flag will be 0
	set_trigger(); // set trigger pin high for 10us

	while(measure_flag); // wait until measure cycle is finished

	return pulse_time;
}



uint16_t HCSR04_get_distance_cm()
{
	 //1. Set TRIG pin HIGH for 10ms
	 //2. Measure Echo Pin High state time
	uint16_t distance_cm;
	distance_cm = HCSR04_get_measure() / 58;

	return distance_cm;
}
