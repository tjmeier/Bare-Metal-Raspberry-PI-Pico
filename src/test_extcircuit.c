#include <extcircuit.h>
#include <stdint.h>

#define CYCLES_FOR_40HZ 520256
#define CYCLES_PER_US 21

#define BTNR (1<<21)
#define BTNL (1<<22)
#define BTND (1<<26)
#define BTNC (1<<27)
#define BTNU (1<<28)
#define BTN  (BTNR | BTNL | BTND | BTNC | BTNU)

#define SW0 (1<<17)
#define SW1 (1<<18)
#define SW2 (1<<19)
#define SW3 (1<<20)
#define SW  (SW0 | SW1 | SW2 | SW3)

#define LED_PICO (1<<25)
#define LED_GRN (1<<13)
#define LED_YLW (1<<14)
#define LED_RED (1<<15)
#define LED_BLU (1<<16)

int main ( void )
{
	configure_pins();
	clear_gpio_output_enable(SW);
	uint32_t pins_read;
	while(1){
		pins_read = read_gpio();

		if (pins_read & BTN ) {
			set_gpio(LED_PICO);
		}
		else {
			clear_gpio(LED_PICO);
		}

		if (pins_read & SW0) {
			set_gpio(LED_GRN);
		}
		else{
			clear_gpio(LED_GRN);
		}

		if (pins_read & SW1) {
			set_gpio(LED_YLW);
		}
		else{
			clear_gpio(LED_YLW);
		}

		if (pins_read & SW2) {
			set_gpio(LED_RED);
		}
		else{
			clear_gpio(LED_RED);
		}

		if (pins_read & SW3) {
			set_gpio(LED_BLU);
		}
		else{
			clear_gpio(LED_BLU);
		}
	}
}

