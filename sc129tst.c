/*
	sc129test.c

	Test program for the SC129 library. This test program assumes that each
	output is tied to each input (I used jumpers). It then cycles through
	all possible 8bit values and writes the value to the output port, then
	reads the value back from the input port and compares to make sure the
	written value matches the value read. This effectively serves as unit
	tests for the API as well as a diagnostic tool for the SC129.
*/

#include "sc129.h"
#include <stdio.h>
#include <stdlib.h>

void main() {
	printf("\n\nSC129 Test v1.0 by Cyrus Brunner\n\n");
	printf("Make sure each output pin of the SC129 is connected to it's\n");
	printf("corresponding input pin and then press any key to continue...\n");
	fgetc_cons();
	printf("Beginning SC129 test (values 0 - 255)...\n\n");
	sleep(1);
	SC129_setAddress(SC129_DEFAULT_ADDRESS);  // Change this to match the address the jumpers are set for.
	
	int val = 0;
	for (int i = 0; i < 255; i++) {
		SC129_write(i);
		msleep(500);
		val = SC129_read();
		printf("Output = %d, Input = %d - ", i, val);
		if (val != i) {
			printf("ERROR Value mismatch!\n");
		}
		else {
			printf("Value match!\n");
		}
	}

	SC129_write(0x00);  // Make sure the all the output pins (and LEDs) are off.
	printf("\nDONE!");
	exit(0);
}