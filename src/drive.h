#ifndef MOTORS_DRIVE_H_
#define MOTORS_DRIVE_H_

#include <avr/io.h>

#define AIN1 PB5
#define AIN2 PB4
#define BIN1 PB0
#define BIN2 PB1
#define PWMB PD5
#define PWMA PD6

static inline void A_set_speed(uint8_t val)
{
	OCR0A = val;
}
static inline void B_set_speed(uint8_t val)
{
	OCR0B = val;
}

void A_go_forward(void);
void B_go_forward(void);

void A_go_backward(void);
void B_go_backward(void);

void A_brake(void);
void B_brake(void);

#endif /* Header guard */
