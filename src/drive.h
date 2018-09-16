#ifndef MOTORS_DRIVE_H_
#define MOTORS_DRIVE_H_

#include <avr/io.h>

#define AIN1 PB5
#define AIN2 PB4
#define BIN1 PB0
#define BIN2 PB1
#define PWMB PD5
#define PWMA PD6

static inline void L_set_speed(uint8_t val)
{
	OCR0A = val;
}
static inline void R_set_speed(uint8_t val)
{
	OCR0B = val;
}

void L_go_forward(void);
void R_go_forward(void);

void L_go_backward(void);
void R_go_backward(void);

void L_brake(void);
void R_brake(void);

#endif /* Header guard */
