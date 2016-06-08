/**

	VEX_STR.H

	Custom string helper functions

**/

#ifndef VEX_STR_H
#define VEX_STR_H

#include <stdlib.h>

// Copy string
void vex_string_copy(char* src, char* dest);

// Duplicate string
char* vex_string_duplicate(char* str);

// Gets size of string
int vex_string_length(char* str);

// Returns 1 if the string contains delimiter
int vex_string_contains(char* str, char delim);

// Counts how many times string contains delimiter
int vex_string_contains_n(char* str, char delim);

// Splits string by delimiter
char** vex_string_split(char* str, char delim);

// Gets size of string array
int vex_string_array_size(char** arr);

// Replaces characters in a string
char* vex_string_replace(char* str, char original, char replace);

// Check if two strings equal
int vex_string_equals(char* a, char* b);

// Append one string to another
char* vex_string_append(char* str, char* app);

// Prepend one string to another
char* vex_string_prepend(char* str, char* app);

// Convert int to string
char* vex_string_from_int(int num);

//
//
// IMPLEMENTATION
//
//

void vex_string_copy(char* src, char* dest) {
	int length = vex_string_length(src);
	for (int i = 0; i < length; i++) {
		dest[i] = src[i];
	}
}

char* vex_string_duplicate(char* str) {
	int length = vex_string_length(str);
	char* mstr = (char*)malloc(length + 1);
	if (mstr == NULL) {
		return NULL;
	}
	vex_string_copy(str, mstr);
	mstr[length] = '\0';
	return mstr;
}

int vex_string_length(char* str) {
	char c = 'a';
	int size = 0;
	while (c != '\0') {
		c = str[size];
		size++;
	}
	return size - 1;
}

int vex_string_contains(char* str, char delim) {
	char x = '\0';
	int i = 0;
	int contains = 1;
	while (x != delim) {
		if (i > vex_string_length(str)) {
			contains = 0;
			break;
		}
		x = str[i];
		i++;
	}
	return contains;
}

int vex_string_contains_n(char* str, char delim) {
	if (!vex_string_contains(str, delim))
		return 0;

	int count = 0;
	int i = 0;
	while (i != vex_string_length(str)) {
		if (str[i] == delim)
			count++;
		i++;
	}

	return count;
}

char** vex_string_split(char* str, char delim) {
	int length = vex_string_length(str);
	int size = vex_string_contains_n(str, delim) + 1;
	char** split = (char**)malloc((size + 1) * sizeof(char*));

	int it = 0;
	int currentSize = 0;
	for (int i = 0; i < size; i++) {
		for (int j = it; j <= length; j++) {
			if (str[it] == delim || str[it] == '\0') {
				split[i] = (char*)malloc(sizeof(char) * currentSize);
				for (int k = 0; k < currentSize; k++) {
					split[i][k] = str[(it - currentSize) + k];
				}
				it++;
				currentSize = 0;
				break;
			} else {
				it++;
				currentSize++;
			}
		}
	}

	split[size] = NULL;

	return split;
}

int vex_string_array_size(char** arr) {
	char* str = arr[0];
	int i = 0;
	int size = 0;
	while (str != NULL) {
		str = arr[i];
		i++;
		size++;
	}
	return size-1;
}

char* vex_string_replace(char* str, char original, char replace) {
	char* mstr = vex_string_duplicate(str);
	for (int i = 0; i < vex_string_length(str); i++) {
		if (mstr[i] == original) {
			mstr[i] = replace;
		}
	}
	return mstr;
}

int vex_string_equals(char* a, char* b) {
	int alen = vex_string_length(a);
	int blen = vex_string_length(b);

	if (alen != blen) {
		return 0;
	}

	int equals = 1;
	for (int i = 0; i < alen; i++) {
		if (a[i] != b[i]) {
			equals = 0;
			break;
		}
	}

	return equals;
}

char* vex_string_append(char* str, char* app) {
	int strLength = vex_string_length(str);
	int appLength = vex_string_length(app);
	int size = strLength + appLength;

	char* x = (char*)malloc(sizeof(char) * size);

	vex_string_copy(str, x);
	int a = 0;
	for (int i = strLength; i < size; i++) {
		x[i] = app[a];
		a++;
	}

	return x;
}

char* vex_string_prepend(char* str, char* app) {
	int strLength = vex_string_length(str);
	int appLength = vex_string_length(app);
	int size = strLength + appLength;

	char* x = (char*)malloc(sizeof(char) * size);

	vex_string_copy(app, x);
	int a = 0;
	for (int i = appLength; i < size; i++) {
		x[i] = str[a];
		a++;
	}

	return x;
}

char* vex_string_from_int(int num) {
	char* str = (char*)malloc(16);
	sprintf(str, "%d", num);
	return str;
}

#endif // VEX_STR_H