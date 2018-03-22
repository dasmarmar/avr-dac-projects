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
 * @file 	dac0808.c
 *
 * @author 	Mario Regus 
 *
 * @date 	3/21/2018
 *
 * @brief 	Simple program to interface an ATMEGA32 to a DAC0808.
 *
 * @description This program continuously sends values to a DAC0808 connected
 * 		to PORTC of an ATMEGA32. Most of the action occurs in a simple
 * 		for loop, edit here to obtain different results.
 *
 * @platform	AVR ATMEGA32
 *
 * @usage 	Connect a DAC0808 to PORTC of an ATMEGA32 running at 8MHz.
 * 		See accompanying schematic for connection info. To calibrate
 *		offset, write 0 to PORTC and adjust offset potentiometer for
 *		0 volts at output. To calibrate full-scale value, write 0xff
 *		(255) and adjust full-scale potentiometer for full-scale output.
 * 		
 * 		Set appropriate AVR fuse bits!
 *
 * @compiler 	avr-gcc -mmcu=atmega32 -Os -o dac0808.o dac0808.c
 *
 * @targets	dac0808.o
 *
 * @programmer	avrdude -c usbtiny -p m32 -U flash:w:dac0808.o
 *
 */


#ifndef F_CPU
#define F_CPU 8000000UL		/* External 8MHz Crystal */
#endif

#include <avr/io.h>		/* AVR Register Definitions */
#include <util/delay.h>		/* Predefined delay functions */


unsigned char N = 255;

void main(){
	
	DDRC = 0xff;		/* Set Port C as output */

	unsigned char i;

	while(1){		/* Loop forever */
		
		for(i = 0; i <= N; i++){	/* Iterate 0-255 */

			PORTC = 0xff;		/* Send value to DAC */
			_delay_ms(2500);	/* Delay */
		}/* End for loop */

	}/* End while loop */

	return;

}/* End main() */
