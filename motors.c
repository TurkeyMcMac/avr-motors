#include "pins.h"
#include <util/delay.h>

__attribute__((constructor))
void main(void)
{
	setup();

	OCR0A = 100;
	OCR0B = 50;

	while (1) {
		PORTB |= AIN1;
		PORTB &= ~AIN2;
		PORTB |= BIN1;
		PORTB &= ~BIN2;
		_delay_ms(3000);

		PORTB &= ~AIN1;
		PORTB |= AIN2;
		PORTB &= ~BIN1;
		PORTB |= BIN2;
		_delay_ms(3000);

		PORTB &= ~(AIN1 | AIN2 | BIN1 | BIN2);
		_delay_ms(3000);
	}
}

