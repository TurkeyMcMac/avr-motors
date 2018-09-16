#include "drive.h"
#include "running.h"
#include <avr/pgmspace.h>
#include <util/delay.h>

enum movement {
	FORWARD,
	BACKWARD,
	TURN_LEFT,
	TURN_RIGHT,
};
#define STATE(movement, duration) (((movement) << 6) | ((duration) & 0b111111))
#define STATE_MOVEMENT(state) ((state) >> 6)
#define STATE_DURATION(state) ((state) & 0b111111)
static PROGMEM const uint8_t states[] = {
	STATE(FORWARD, 21),
	STATE(TURN_LEFT, 16),
	STATE(FORWARD, 21),
	STATE(TURN_RIGHT, 16),
	STATE(FORWARD, 21),
	STATE(TURN_RIGHT, 16),
	STATE(FORWARD, 21),
	STATE(TURN_LEFT, 16),
};
static uint8_t current_idx;
static uint8_t current_state;

static void next_state(void)
{
	uint8_t duration = STATE_DURATION(current_state);

	if (duration == 0) {
		current_state = pgm_read_byte(states + current_idx);
		switch (STATE_MOVEMENT(current_state)) {
		case FORWARD:
			L_go_forward();
			R_go_forward();
			break;
		case BACKWARD:
			L_go_forward();
			R_go_forward();
			break;
		case TURN_LEFT:
			L_go_backward();
			R_go_forward();
			break;
		case TURN_RIGHT:
			L_go_forward();
			R_go_backward();
			break;
		default:
			break;
		}
		++current_idx;
		current_idx %= sizeof(states);
	} else {
		--duration;
		current_state = STATE(STATE_MOVEMENT(current_state), duration);
	}
}

void main(void)
{
	L_set_speed(90);
	R_set_speed(90);

	while (1) {
		if (should_run()) {
			next_state();
		} else {
			L_brake();
			R_brake();
		}
		_delay_ms(100);
	}
}

