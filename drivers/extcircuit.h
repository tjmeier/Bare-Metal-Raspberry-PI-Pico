#include <stdint.h>

#ifndef LED_H
#define LED_H

void configure_pins( void );
void turn_on_trig();
void toggle_gpio(uint32_t mask);

void set_gpio(uint32_t mask);

void clear_gpio(uint32_t mask);

uint32_t read_gpio();

void set_gpio_output_enable(uint32_t mask);

void clear_gpio_output_enable(uint32_t mask);

#endif
