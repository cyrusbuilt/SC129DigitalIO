#include <stdio.h>
#include <stdlib.h>
#include "sc129.h"

static unsigned int _address = SC129_DEFAULT_ADDRESS;

bool __LIB__ SC129_setAddress_fastcall(unsigned int address) __smallc __z88dk_fastcall {
	if (address < 256) {
		_address = address;
		return true;
	}

	return false;
}

bool __LIB__ SC129_write_fastcall(unsigned int value) __smallc __z88dk_fastcall {
	if (value < 256) {
		outp(_address, value);
		return true;
	}

	return false;
}

unsigned int __LIB__ SC129_read_fastcall (void) __smallc __z88dk_fastcall {
	return inp(_address);
}
