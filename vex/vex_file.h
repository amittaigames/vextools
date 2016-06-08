/**

	VEX_FILE.H

	Custom file helper functions

**/

#ifndef VEX_FILE_H
#define VEX_FILE_H

#include <stdio.h>
#include <stdlib.h>

#include "vex_str.h"

// Read entire file into buffer
char* vex_file_read_all(char* fName);

// Check for file extension in name
int vex_file_has_extension(char* fName, char* ext);

//
//
// IMPLEMENTATION
//
//

char* vex_file_read_all(char* fName) {
	FILE* file = fopen(fName, "r");
	if (!file)
		return NULL;

	fseek(file, 0, SEEK_END);
	int size = ftell(file);
	fseek(file, 0, SEEK_SET);

	char* buf = (char*)malloc(sizeof(char) * size);
	if (!buf)
		return NULL;

	fread(buf, 1, size, file);
	fclose(file);

	return buf;
}

int vex_file_has_extension(char* fName, char* ext) {
	char** parts = vex_string_split(fName, '.');
	int size = vex_string_array_size(parts);

	if (vex_string_equals(ext, parts[size - 1])) {
		return 1;
	} else {
		return 0;
	}
}

#endif // VEX_FILE_H