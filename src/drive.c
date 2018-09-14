#include "pins.h"

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
