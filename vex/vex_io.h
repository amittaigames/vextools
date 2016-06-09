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

// Print to console
void vex_print(char* fmt, ...);

// Print to console with new line
void vex_println(char* fmt, ...);

// Print error to the console
void vex_print_err(char* fmt, ...);

// Print error to console with new line
void vex_println_err(char* fmt, ...);

//
//
// IMPLEMENTATION
//
//

void vex_print(char* fmt, ...) {
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
			case 'c': {
				char c = va_arg(args, int);
				fputc(c, stdout);
				break;
			}
			case 'f': {
				float f = va_arg(args, double);
				char* s = vex_string_from_float(f);
				fputs(s, stdout);
				break;
			}
			case 'x': {
				int num = va_arg(args, int);
				char* s = vex_string_hex_from_int(num);
				fputs(s, stdout);
				break;
			}
		}
		i++;
	}

	va_end(args);
}

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
			case 'c': {
				char c = va_arg(args, int);
				fputc(c, stdout);
				break;
			}
			case 'f': {
				float f = va_arg(args, double);
				char* s = vex_string_from_float(f);
				fputs(s, stdout);
				break;
			}
			case 'x': {
				int num = va_arg(args, int);
				char* s = vex_string_hex_from_int(num);
				fputs(s, stdout);
				break;
			}
		}
		i++;
	}

	va_end(args);
	fputc('\n', stdout);
}

void vex_print_err(char* fmt, ...) {
	va_list args;
	char* str = vex_string_duplicate(fmt);

	va_start(args, fmt);

	fputs("[ERROR] ", stderr);

	int i = 0;
	char x = 'a';
	while (x != '\0') {
		x = str[i];
		if (x != '%') {
			fputc(x, stderr);
			i++;
			continue;
		}
		x = str[++i];
		switch (x) {
			case 's': {
				char* s = va_arg(args, char*);
				fputs(s, stderr);
				break;
			}
			case 'd': {
				int d = va_arg(args, int);
				char* s = vex_string_from_int(d);
				fputs(s, stderr);
				break;
			}
			case 'c': {
				char c = va_arg(args, int);
				fputc(c, stderr);
				break;
			}
			case 'f': {
				float f = va_arg(args, double);
				char* s = vex_string_from_float(f);
				fputs(s, stderr);
				break;
			}
			case 'x': {
				int num = va_arg(args, int);
				char* s = vex_string_hex_from_int(num);
				fputs(s, stderr);
				break;
			}
		}
		i++;
	}

	va_end(args);
}

void vex_println_err(char* fmt, ...) {
	va_list args;
	char* str = vex_string_duplicate(fmt);

	va_start(args, fmt);

	fputs("[ERROR] ", stderr);

	int i = 0;
	char x = 'a';
	while (x != '\0') {
		x = str[i];
		if (x != '%') {
			fputc(x, stderr);
			i++;
			continue;
		}
		x = str[++i];
		switch (x) {
			case 's': {
				char* s = va_arg(args, char*);
				fputs(s, stderr);
				break;
			}
			case 'd': {
				int d = va_arg(args, int);
				char* s = vex_string_from_int(d);
				fputs(s, stderr);
				break;
			}
			case 'c': {
				char c = va_arg(args, int);
				fputc(c, stderr);
				break;
			}
			case 'f': {
				float f = va_arg(args, double);
				char* s = vex_string_from_float(f);
				fputs(s, stderr);
				break;
			}
			case 'x': {
				int num = va_arg(args, int);
				char* s = vex_string_hex_from_int(num);
				fputs(s, stderr);
				break;
			}
		}
		i++;
	}

	va_end(args);
	fputc('\n', stderr);
}

#endif // VEX_IO_H