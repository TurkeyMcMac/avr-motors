#include "drive.h"

void A_go_forward(void)
{
	PORTB |= AIN1;
	PORTB &= ~AIN2;
}
void B_go_forward(void)
{
	PORTB |= BIN1;
	PORTB &= ~BIN2;
}

void A_go_backward(void)
{
	PORTB &= ~AIN1;
	PORTB |= AIN2;
}
void B_go_backward(void)
{
	PORTB &= ~BIN1;
	PORTB |= BIN2;
}

void A_brake(void)
{
	PORTB &= ~AIN1;
	PORTB &= ~AIN2;
}
void B_brake(void)
{
	PORTB &= ~BIN1;
	PORTB &= ~BIN2;
}

__attribute__((constructor))
static void set_motors(void)
{
	// Set outputs
	DDRD |= PWMA | PWMB;
	DDRB |= AIN1 | AIN2 | BIN1 | BIN2;

	// Set PWM timer
	TCCR0A |= _BV(COM0A1) | _BV(COM0B1) | _BV(WGM01) | _BV(WGM00);
	TCCR0B |= _BV(CS01) | _BV(CS00);
	TCNT0 = 0;
}
