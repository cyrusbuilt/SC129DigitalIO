/*
 SC129 Digital I/O Z88DK library. This library is used to interface with Stephen
 Cousins' SC129 Digital I/O Module for RC2014.

 v.10

 Author:
	Cyrus Brunner <cyrusbuilt at gmail dot com>
*/

#ifndef _SC129_H
#define _SC129_H

#include <stdbool.h>
#include <sys/compiler.h>

/**
 * The default bus address of the SC129 module (all jumpers off).
 */
#define SC129_DEFAULT_ADDRESS 0x00

/**
 * Sets the bus address of the module. Default is 0x00.
 * @param address The address to set (0 - 255).
 * @returns true if valid address set; Otherwise, false.
 */
extern bool __LIB__ SC129_setAddress(unsigned int address) __z88dk_fastcall;

/**
 * Writes a value to the output port of the Digital I/O module.
 * @param value The value to write (0 - 255);
 * @returns true if a valid value was written; Otherwise, false.
 */
extern bool __LIB__ SC129_write(unsigned int value) __z88dk_fastcall;

/**
 * Reads a value from the input port of the Digital I/O module.
 * @returns an 8bit value read from the port (0 - 255);
 */
extern unsigned int __LIB__ SC129_read(void) __z88dk_fastcall;

#endif
