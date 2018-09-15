#include "drive.h"
#include "running.h"
#include <util/delay.h>

void main(void)
{
	uint8_t speed = 0;

	setup();

	while (1) {
		if (should_run()) {
			A_set_speed(speed);
			B_set_speed(speed);
			A_go_forward();
			B_go_forward();
			speed += 1;
		} else {
			A_brake();
			B_brake();
		}
		_delay_ms(100);
	}
}

