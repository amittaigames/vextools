/**

	VEX_MEM.H

	Custom memory allocation

**/

#ifndef VEX_MEM_H
#define VEX_MEM_H

#ifndef VEX_MEMORY_SIZE
	#define VEX_MEMORY_SIZE 16384
#endif

#include "vex_io.h"

// Allocation instance
typedef struct _vexAlloc {
	int size;
	int ptr;
	void* data;
} vexAlloc;

// Create allocation instance
vexAlloc* vex_alloc_init();

// Allocate memory
void* vex_malloc(vexAlloc* alloc, int size);

// Free memory
void vex_free(vexAlloc* alloc, void* ptr);

// Delete allocation instance
void vex_alloc_delete(vexAlloc* alloc);

//
//
// IMPLEMENTATION
//
//

vexAlloc* vex_alloc_init() {
	vexAlloc* alloc = (vexAlloc*)malloc(sizeof(vexAlloc));
	alloc->size = VEX_MEMORY_SIZE * sizeof(int);
	alloc->ptr = 0;
	alloc->data = (void*)malloc(VEX_MEMORY_SIZE * sizeof(int));

	return alloc;
}

void* vex_malloc(vexAlloc* alloc, int size) {
	int newSize = size + sizeof(int);
	if (alloc->ptr + newSize > alloc->size) {
		vex_println_err("Allocator (%d) ran out of room!", &alloc);
		return NULL;
	}

	*((int*)alloc->data + alloc->ptr) = size;
	int* vptr = *(&alloc->data) + alloc->ptr + sizeof(int);
	alloc->ptr += newSize;

	return vptr;
}

void vex_free(vexAlloc* alloc, void* ptr) {
	int size = *((int*)ptr - 1);
	for (int i = 0; i < size; i++) {
		*((char*)ptr + i) = '\0';
	}
	*((char*)ptr - 1) = '\0';
}

void vex_alloc_delete(vexAlloc* alloc) {
	free(alloc->data);
	free(alloc);
}

#endif // VEX_MEM_H