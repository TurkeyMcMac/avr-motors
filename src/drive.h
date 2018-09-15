#ifndef MOTORS_DRIVE_H_
#define MOTORS_DRIVE_H_

#include <avr/io.h>

#define AIN1 _BV(PB5)
#define AIN2 _BV(PB4)
#define BIN1 _BV(PB0)
#define BIN2 _BV(PB1)
#define PWMB _BV(PD5)
#define PWMA _BV(PD6)
#define RUN _BV(PD3)
#define PIN_RUN PIND

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
