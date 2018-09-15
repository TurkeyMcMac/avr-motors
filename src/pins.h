#ifndef MOTORS_PINS_H_
#define MOTORS_PINS_H_

#include <avr/io.h>
#include <avr/interrupt.h>

#define AIN1 _BV(5)
#define AIN2 _BV(4)
#define BIN1 _BV(0)
#define BIN2 _BV(1)
#define PWMB _BV(5)
#define PWMA _BV(6)
#define RUN _BV(PD3)
#define PIN_RUN PIND
#define ALL_OUT_B (AIN1 | AIN2 | BIN1 | BIN2)
#define ALL_OUT_D (PWMA | PWMB)

#endif /* Header guard */
