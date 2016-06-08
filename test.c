#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

#include "vex/vex.h"

int main(int argc, char* agrv[]) {
	char* name = "Amittai Games";
	vex_println("My name is %s and I am %d years old", name, 16);
	return 0;
}