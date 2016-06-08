/**

	VEX_IO.H

	Custom I/O functions. Should be able to replace `stdio.h` eventually.

**/

#ifndef VEX_IO_H
#define VEX_IO_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdarg.h>

#include "vex_str.h"

void vex_println(char* fmt, ...) {
	va_list args;
	char* str = vex_string_duplicate(fmt);

	va_start(args, fmt);

	int i = 0;
	char x = 'a';
	while (x != '\0') {
		x = str[i];
		if (x != '%') {
			fputc(x, stdout);
			i++;
			continue;
		}
		x = str[++i];
		switch (x) {
			case 's': {
				char* s = va_arg(args, char*);
				fputs(s, stdout);
				break;
			}
			case 'd': {
				int d = va_arg(args, int);
				char* s = vex_string_from_int(d);
				fputs(s, stdout);
				break;
			}
		}
		i++;
	}

	fputc('\n', stdout);
	va_end(args);
}

#endif // VEX_IO_H