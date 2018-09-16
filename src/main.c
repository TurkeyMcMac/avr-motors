#include "drive.h"
#include "running.h"
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
static uint8_t states[] = {
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
		current_state = states[current_idx];
		switch (STATE_MOVEMENT(current_state)) {
		case FORWARD:
			A_go_forward();
			B_go_forward();
			break;
		case BACKWARD:
			A_go_forward();
			B_go_forward();
			break;
		case TURN_LEFT:
			A_go_forward();
			B_go_backward();
			break;
		case TURN_RIGHT:
			A_go_backward();
			B_go_forward();
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
	A_set_speed(90);
	B_set_speed(90);

	while (1) {
		if (should_run()) {
			next_state();
		} else {
			A_brake();
			B_brake();
		}
		_delay_ms(100);
	}
}

