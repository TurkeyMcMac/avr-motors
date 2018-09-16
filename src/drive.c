#include "drive.h"

void A_go_forward(void)
{
	PORTB |= _BV(AIN1);
	PORTB &= ~_BV(AIN2);
}
void B_go_forward(void)
{
	PORTB |= _BV(BIN1);
	PORTB &= ~_BV(BIN2);
}

void A_go_backward(void)
{
	PORTB &= ~_BV(AIN1);
	PORTB |= _BV(AIN2);
}
void B_go_backward(void)
{
	PORTB &= ~_BV(BIN1);
	PORTB |= _BV(BIN2);
}

void A_brake(void)
{
	PORTB &= ~_BV(AIN1);
	PORTB &= ~_BV(AIN2);
}
void B_brake(void)
{
	PORTB &= ~_BV(BIN1);
	PORTB &= ~_BV(BIN2);
}

__attribute__((constructor))
static void set_motors(void)
{
	// Set outputs
	DDRD |= _BV(PWMA) | _BV(PWMB);
	DDRB |= _BV(AIN1) | _BV(AIN2) | _BV(BIN1) | _BV(BIN2);

	// Set PWM timer
	TCCR0A |= _BV(COM0A1) | _BV(COM0B1) | _BV(WGM01) | _BV(WGM00);
	TCCR0B |= _BV(CS01) | _BV(CS00);
	TCNT0 = 0;
}
