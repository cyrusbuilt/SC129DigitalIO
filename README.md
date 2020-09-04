# SC129DigitalIO
Z88DK-based C library for [Stephen Cousins'](https://www.scc.me.uk/) [SC129 Digital I/O](https://smallcomputercentral.wordpress.com/sc129-digital-i-o-rc2014/) module for [RC2014](https://rc2014.co.uk/)

## Synopsis
This is just a very simple library for interfacing with the SC129 in C/C++ using the [Z88DK](https://www.z88dk.org/). It's mostly just a wrapper around the outp() and inp() functions in stdio.h.

## API
void SC129_setAddress(int address) - Set the module address. The address value should match what the address
selection jumpers are configured for (default is 0x00 - No jumpers).

void SC129_write(int value) - Write a value to the output port of the Digital I/O module. This is an 8bit value (0 - 255).

int SC129_read() - Reads a value from the input port of the Digital I/O module. This will be an 8bit value (0 - 255).

## Test Program
sc129tst.c is a commind line test program for the SC129 that was intended to run on CP/M.  To build, run:

```
make all
```

This will produce an executable called SC129TST.COM. You can then trasfer this to your RC2014 (or compatible Z80/Z180) system and run it. The test program operates on the assumption that you tie each of the output pins to their corresponding input pins (I used jumper shunts). When the program runs, it outputs values 0 - 255 to the output port then reads the value back from the input port and compares the value to see if they match. Once it has processed all 255 values, then the program terminates. You will see both the input and output LEDs on the board flashing as the values are processed.

## Usage
Simply include the SC129.h and SC2129.c files in your project then add then following where needed:

```c
#include "sc129.h"
```

I have personally tested this on CP/M 2.2 (ROMWbW) with the SC129 installed in an [SC126](https://smallcomputercentral.wordpress.com/sc126-z180-motherboard-rc2014/) but this should work on all RC2014 compatible systems with the SC129 installed.