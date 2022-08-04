#include <stdio.h>
#include <stdlib.h>
#include "sc129.h"

static unsigned int _address = SC129_DEFAULT_ADDRESS;

bool __LIB__ SC129_setAddress(unsigned int address) __z88dk_fastcall {
	if (address < 256) {
		_address = address;
		return true;
	}

	return false;
}

bool __LIB__ SC129_write(unsigned int value) __z88dk_fastcall {
	if (value < 256) {
		outp(_address, value);
		return true;
	}

	return false;
}

unsigned int __LIB__ SC129_read(void) __z88dk_fastcall {
	return inp(_address);
}
