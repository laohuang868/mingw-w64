/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */

#include <intrin.h>

void __inbytestring(unsigned short Port, unsigned char *Buffer, unsigned __LONG32 Count)
{
    __asm__ __volatile__ (
        "cld ; rep ; insb " 
        : "=D" (Buffer), "=c" (Count)
        : "d"(Port), "0"(Buffer), "1" (Count)
        );
}

