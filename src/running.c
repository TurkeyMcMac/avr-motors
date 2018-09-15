#include "running.h"
#include "pins.h"
#include <stdint.h>

static uint8_t running_flags = 0;
#	define RUNNING		0b00000001
#	define LAST_PRESSED	0b00000010

bool should_run(void)
{
	if (!(PIN_RUN & RUN)) {
		if ((running_flags & LAST_PRESSED) == 0) {
			running_flags |= LAST_PRESSED;
			running_flags ^= RUNNING;
		}
	} else {
		running_flags &= ~LAST_PRESSED;
	}

	return (running_flags & RUNNING) == 0;
}
