#include "b64.h"

// The number of buffers we need
unsigned int bufc = 0;

unsigned char* b64_buf_malloc()
{
	bufc = 1;
	return &__heap_base;
}

unsigned char* b64_buf_realloc(unsigned char* ptr, unsigned int size)
{
	while (size > bufc * B64_BUFFER_SIZE) bufc++;
	return ptr;
}

// Reference: https://cplusplus.com/reference/cctype/
int isalnum(int c) {
	return (c >= 0x30 && c <= 0x39) ||
	       (c >= 0x41 && c <= 0x5A) ||
		   (c >= 0x61 && c <= 0x7A);
}

void * memset ( void * ptr, int value, unsigned long num ) {
	unsigned char *mem = (unsigned char *)ptr;
	unsigned int i;

	for (i = 0; i < num; ++i) mem[i] = (unsigned char)value;

	return ptr;
}

void * memcpy ( void * destination, const void * source, unsigned long num ) {
	const unsigned char *mem_src = (const unsigned char *)source;
	unsigned char *mem_dest = (unsigned char *)destination;
	unsigned int i;

	for (i = 0; i < num; ++i) mem_dest[i] = mem_src[i];

	return destination;
}
