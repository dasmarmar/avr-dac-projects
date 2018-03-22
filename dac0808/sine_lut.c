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
 * @file 	sine_lut.c
 *
 * @author 	Mario Regus
 *
 * @date 	3/21/2018
 *
 * @brief 	Program to generate discrete samples of a sine wave.
 *
 * @description This program generates N number of samples of a sine wave and
 * 		places them in a file "sine_lut.dat". The samples are 8-bit
 * 		unsigned for compatibility with 8-bit microcontrollers, and are
 * 		written to the file "sine_lut.dat" in a format which can easily
 * 		be implemented as a c language array in a header file.
 *
 * @usage	For better resolution change the sample size N and the value D.
 * 		D is the time step defined as Period / N, where Period is
 * 		defined as 1 / Frequency.
 *
 * 		Samples are scaled and contain an offset for compatibility with
 * 		with 8-bit DACs for example the DAC0808 or similar.
 * 		Edit appropriately for your system.
 *
 * @compiler	gcc -o sine_lut.o sine_lut.c -lm
 *
 * @execution	./sine_lut.o
 *
 * @targets	sine_lut.o sine_lut.dat
 *
 */


#include <stdio.h>	/* Standard C library header */
#include <math.h>	/* Standard C library header */

float pi = 3.14159;	/* The constant pi */

float P = .001;		/* Period of desired sine wave = 1 / Frequency */

int N = 256;		/* Number of Samples */

float D = .000003906;  	/* Sample time step D = P / N */

float x, value;

float full_scale = 5.00000;	/* Full scale amplitude */

unsigned char sample;		/* 8 Bit sine sample */

void main(){

	FILE *fp;		/* File pointers */

	fp = fopen("sine_lut.dat", "w");	/* Open file "sine_lut.dat" */

	for(int i = 0; i < N; i++){

		x = sin(2 * pi * D * i / P);		/* Compute the sine */ 

		value = (full_scale / 2) * (1 + x); 	/* Scale and offset */

		sample = (N / full_scale) * value;	/* Type cast to 8-bit */

		fprintf(fp, "%d%s", sample, ", ");	/* Send to file */

		}/* End for loop */

	fclose(fp);	/* Close file "sine_lut.dat" */
	
	return;

}/* End main() */


