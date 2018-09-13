#include "drive.h"
#include <util/delay.h>

__attribute__((constructor))
void main(void)
{
	setup();

	A_set_speed(100);
	B_set_speed(50);

	while (1) {
		A_go_forward();
		B_go_forward();
		_delay_ms(3000);

		A_go_backward();
		B_go_backward();
		_delay_ms(3000);

		A_brake();
		B_brake();
		_delay_ms(3000);
	}
}

