#include "pins.h"

__attribute__((constructor))
static void setup(void)
{
	DDRD = ALL_OUT_D;
	DDRD &= ~RUN;
	DDRB = ALL_OUT_B;

	TCNT0 = 0;
	TCCR0A = _BV(COM0A1) | _BV(COM0B1) | _BV(WGM01) | _BV(WGM00);
	TCCR0B = _BV(CS01) | _BV(CS00);
}
