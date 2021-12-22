// Noah Fishman
// Cris Droguett

#ifndef RIGHT_MOTOR_TIMER_H_
#define RIGHT_MOTOR_TIMER_H_

void set_right_motor_duty_cycle(uint8_t duty_cycle);
void configure_right_motor();
void brake_right_motor();
void coast_right_motor();
void turn_on_right_motor_forwards();
void turn_on_right_motor_reverse();

#endif /* RIGHT_MOTOR_TIMER_H_ */