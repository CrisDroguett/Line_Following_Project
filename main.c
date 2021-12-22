/* Final Project - EECE 387 - Spring 2021
   Noah Fishman & Cris Droguett */

#include <stdbool.h>
#include <stdint.h>
#include "ADC_Driver.h"
#include "left_motor_timer.h"
#include "right_motor_timer.h"
#include "timer_1_driver.h"
#include "reflective_sensor.h"

#define THRESHOLD 5
#define min_duty_cycle 0
#define max_duty_cycle 255

_Bool read_line_sensor( int8_t *pos);
void steer_robot(uint8_t speed, int8_t steer);
void update_line_sensor(_Bool calibrate);
uint8_t sensor_value;

int main(void)
{
	configure_adc();
	configure_right_motor();
	configure_left_motor();
	configure_timer_1();
	configure_reflective_sensor();
	
	int8_t line_pos;
	_Bool line_is_lost;
	
	turn_on_left_motor_forwards();
	turn_on_right_motor_forwards();
    while (1) 
    {
		wait_for_next_timer_period();
		line_is_lost = read_line_sensor(& line_pos);
		update_line_sensor(line_is_lost);
		if(line_is_lost)
		{
			steer_robot(0,0);
		}
		else
		{
			steer_robot(0x20,-2*line_pos);
		}
    }
}

_Bool read_line_sensor( int8_t *pos)
{
	sensor_value = get_sensor_info();
	int8_t line_position = (sensor_value & (1<<0))? -32:0 +	(sensor_value & (1<<1))? -8:0 +(sensor_value & (1<<3))? 8:0 +(sensor_value & (1<<4))? 32:0;
	static int8_t avg_line_position = 0;
	avg_line_position = (3*avg_line_position + line_position)/4;
	static uint8_t num_times_line_not_detected;
	_Bool line_is_lost;
	if(!sensor_value)
	{
		if (num_times_line_not_detected < THRESHOLD)
		num_times_line_not_detected ++;
	}
	else
	num_times_line_not_detected = 0;
	line_is_lost = num_times_line_not_detected >= THRESHOLD;
	*pos = avg_line_position;
	return line_is_lost;
}

void steer_robot(uint8_t speed, int8_t steer)
{
	int16_t left_duty_cycle;
	int16_t right_duty_cycle;
	left_duty_cycle = speed;
	right_duty_cycle = speed;
	if (speed != 0)
	{
		left_duty_cycle -= steer;
		right_duty_cycle += steer;
		if (left_duty_cycle < min_duty_cycle)
		left_duty_cycle = min_duty_cycle;
		if (left_duty_cycle > max_duty_cycle)
		left_duty_cycle = max_duty_cycle;
		if (right_duty_cycle < min_duty_cycle)
		right_duty_cycle = min_duty_cycle;
		if (right_duty_cycle > max_duty_cycle)
		right_duty_cycle = max_duty_cycle;
	}
	set_right_motor_duty_cycle(right_duty_cycle);
	set_left_motor_duty_cycle(left_duty_cycle);
}

void update_line_sensor(_Bool calibrate)
{
	static uint8_t channel;
	static uint16_t white_threshold[5];
	
	if(adc_conversion_is_complete())
	{
		uint16_t value = get_adc_result();
		
		if(calibrate && value > white_threshold[channel])
			white_threshold[channel] = value;
			
		if(value < white_threshold[channel])
			sensor_value &= ~(1<<channel);
		else
			sensor_value |= (1<<channel);
			
		channel = (channel == 4) ? 0 : channel+1;
		start_adc_conversion(channel);
	}
}