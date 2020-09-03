#include <stdio.h>
#include "sc129.h"

int _address = SC129_DEFAULT_ADDRESS;

bool SC129_setAddress(int address) {
	if (address >= 0 && address <= 255) {
		_address = address;
		return true;
	}

	return false;
}

bool SC129_write(int value) {
	if (value >= 0 && value <= 255) {
		outp(_address, value);
		return true;
	}

	return false;
}

int SC129_read() {
	return inp(_address);
}