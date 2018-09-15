#ifndef MOTORS_PINS_H_
#define MOTORS_PINS_H_

#include <avr/io.h>
#include <avr/interrupt.h>

#define AIN1 _BV(5)
#define AIN2 _BV(4)
#define BIN1 _BV(0)
#define BIN2 _BV(1)
#define PWMB _BV(5)
#define PWMA _BV(6)
#define RUN _BV(PD3)
#define PIN_RUN PIND
#define ALL_OUT_B (AIN1 | AIN2 | BIN1 | BIN2)
#define ALL_OUT_D (PWMA | PWMB)

static inline void setup(void)
{
	DDRD = ALL_OUT_D;
	DDRD &= ~RUN;
	DDRB = ALL_OUT_B;

	TCNT0 = 0;
	TCCR0A = _BV(COM0A1) | _BV(COM0B1) | _BV(WGM01) | _BV(WGM00);
	TCCR0B = _BV(CS01) | _BV(CS00);
}

#endif /* Header guard */
