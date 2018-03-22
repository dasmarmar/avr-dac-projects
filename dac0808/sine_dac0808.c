/*******************************************************************************
 * Copyright (C) 2018 by Mario Regus
 *
 * Redistribution, modification, or use of this software is permitted as long as
 * the files maintain this copyright. Users are permitted to modify this
 * software for educational purposes. Commercial use strictly prohibited. Author 
 * not liable for any damages resulting from the misuse of this software.
 *
 ******************************************************************************/
/**
 * @file 	sine_dac0808.c
 *
 * @author 	Mario Regus 
 *
 * @date 	3/21/2018
 *
 * @brief 	Program to generate a sine wave using a DAC0808
 *
 * @description This program uses a DAC0808 connected to PORTC of an ATMEGA32
 * 		to generate a 1kHz sine wave. It uses a look-up table of 256
 * 		pre-calculated samples to continuously send out to the DAC.
 * 		Fine-tuning of delays needed for precise frequency.
 *
 * @platform	AVR ATMEGA32
 *
 * @usage 	Connect a DAC0808 to PORTC of an ATMEGA32 running at 8MHz.
 * 		Set appropriate AVR fuse bits!
 *
 * @compiler 	avr-gcc -mmcu=atmega32 -Os -o sin_dac0808.o sine_dac0808.c
 *
 * @targets	sine_dac0808.o
 *
 * @programmer	avrdude -c usbtiny -p m32 -U flash:w:sine_dac0808.o
 *
 */


#ifndef F_CPU
#define F_CPU 8000000UL		/* External 8MHz Crystal */
#endif

#include <avr/io.h>		/* AVR Register Definitions */
#include <util/delay.h>		/* Predefined delay functions */
#include "sine_samples.h"	/* Sine Look-Up Table */


unsigned char N = 255;

void main(){

	DDRC = 0xff;		/* Set Port C as output */

	unsigned char i;

	while(1){		/* Loop forever */

		for(i = 0; i <= N; i++){

			PORTC =  samples[i];	/* Send sample to Port C */

			_delay_us(4);	/* 4us delay for 1kHz frequency */

		}	/* end for loop */

	} 		/* end while loop */

	return;		/* main return */

}	/* end main() */
		
