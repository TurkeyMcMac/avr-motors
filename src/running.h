#ifndef MOTORS_RUNNING_H_
#define MOTORS_RUNNING_H_

#include <avr/io.h>
#include <stdbool.h>

#define RUN _BV(PD3)
#define PIN_RUN PIND

bool should_run(void);

#endif /* Header guard */
