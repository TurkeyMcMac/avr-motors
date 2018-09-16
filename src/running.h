#ifndef MOTORS_RUNNING_H_
#define MOTORS_RUNNING_H_

#include <avr/io.h>
#include <stdbool.h>

#define RUN PD3
#define PIN_RUN PIND

bool should_run(void);

#endif /* Header guard */
