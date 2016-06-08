#include <stdio.h>
#include <stdlib.h>

#include "vex/vex.h"

int main(int argc, char* agrv[]) {
	if (vex_file_has_extension("test.c", "c")) {
		printf("File has extension '.c'\n");
	} else {
		printf("File does not have extension '.c'\n");
	}
	return 0;
}