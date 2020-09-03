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
extern bool __LIB__ SC129_setAddress(int address) __smallc;
extern bool __LIB__ SC129_setAddress_callee(int address) __smallc __z88dk_callee;
#define SC129_setAddress(a) SC129_setAddress_callee(a)


/**
 * Writes a value to the output port of the Digital I/O module.
 * @param value The value to write (0 - 255);
 * @returns true if a valid value was written; Otherwise, false.
 */
extern bool __LIB__ SC129_write(int value) __smallc;
extern bool __LIB__ SC129_write_callee(int value) __smallc __z88dk_callee;
#define SC129_write(a) SC129_write_callee(a)

/**
 * Reads a value from the input port of the Digital I/O module.
 * @returns an 8bit value read from the port (0 - 255);
 */
extern int __LIB__ SC129_read() __smallc;
extern int __LIB__ SC129_read_callee() __smallc __z88dk_callee;
#define SC129_read() SC129_read_callee()

#endif