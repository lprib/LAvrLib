/*
* LAvrLib.c
*
* Created: 5/04/2019 7:24:54 AM
* Author : liam
*/

#define F_CPU 16000000

#include <avr/io.h>
#include <util/delay.h>
#include <string.h>
#include <stdbool.h>
#include "usart.h"
#include "digital_io.h"
#include "pin.h"
#include "display.h"

#include "lbc_runner.h"

int main(void)
{
	usart_init(9600);
	
	unsigned char code[] =
	{
		//Number of functions:
		0x0, 0x1,
		//function offsets table:
		0x0, 0x2,

		//function: main
		//locals allocation size (bytes):
		0x0, 0x0,
		//bytecode:
		0x7, 0x0, 0x45, 0x7, 0x0, 0x4, 0x0, 0x64,
		0x0, 0x0, 0x61
	};
	
	stackval_t stack[100] = {0};
	
	ExecutionContext c = {code, stack, stack};
	
	execute_function(c, 0);
	
	while(1) {
		
	}
}

int main0(void) {
	pin_t button = pb1;
	PIN_SET_INPUT(button);
	
	usart_init(9600);
	usart_write_int_line(69);
	display_init();
	display_send_bits_wait(0, 0b00001111);
	display_send_bits_wait(0, 1);
	display_send_bits_wait(0, 0b10);

	for(int i = 0; i < 0xFFFF; i++) {
		display_send_bits_wait(1, i>>8);
		display_send_bits_wait(1, i&0xFF);
		if(i%64 == 0) {
			usart_write_int_hex_line(i-64);
			while(PIN_READ(button) != 0);
		}
	}
}

int main6(void) {
	usart_init(9600);
	display_init();
	//goto extended instr set
	display_send_bits_wait(0, 0b00110100);
	//graphics on
	display_send_bits_wait(0, 0b00110110);
	
	for(int i = 0; i < 0xFFFF; i++) {
		//vert/horiz addr
		for(int v = 0; v < 64; v++) {
			display_send_bits_wait(0, 0b10000000 | v);
			//display_send_bits_wait(0, 0b10000000);
			for(int h = 0; h < 16; h++) {
				display_send_bits_wait(1, i>>8);
				display_send_bits_wait(1, i & 0xFF);
			}
		}
		usart_write_int_line(i);
	}
}

int main3(void) {
	pin_t input = pb1;
	pin_t out = pb2;
	
	PIN_SET_INPUT(input);
	PIN_SET_OUTPUT(out);
	
	while (1)
	{
		if(PIN_READ(input)) {
			PIN_WRITE_LOW(out);
			} else {
			PIN_WRITE_HIGH(out);
		}
	}
}

int main2(void) {
	usart_init(9600);
	display_init();
	display_console_init(false, false);
	display_console_write(0, 0, "\02 Hello \x02");
	
	for(int i = 0; i < 0xFFFF; i++) {
		//display_send_bits_wait(1, i);
		//usart_write_int_hex_line(i);
		//_delay_ms(500);
	}
}