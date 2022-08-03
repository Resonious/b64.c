
/**
 * `b64.h' - b64
 *
 * copyright (c) 2014 joseph werle
 */

#ifndef B64_H
#define B64_H 1

extern unsigned char __heap_base;
#define NULL 0

 // How much memory to allocate per buffer
#define B64_BUFFER_SIZE		(1024 * 64) // 64K

 // Start buffered memory
unsigned char* b64_buf_malloc();

// Update memory size. Returns the same pointer if we
// have enough space in the buffer. Otherwise, we add
// additional buffers.
unsigned char* b64_buf_realloc(unsigned char* ptr, unsigned int size);

/**
 * Base64 index table.
 */

static const char b64_table[] = {
  'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H',
  'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P',
  'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X',
  'Y', 'Z', 'a', 'b', 'c', 'd', 'e', 'f',
  'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n',
  'o', 'p', 'q', 'r', 's', 't', 'u', 'v',
  'w', 'x', 'y', 'z', '0', '1', '2', '3',
  '4', '5', '6', '7', '8', '9', '-', '_'
};

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Encode `unsigned char *' source with `size_t' size.
 * Returns a `char *' base64 encoded string.
 */

unsigned int
b64_encode (const unsigned char *, unsigned int);

/**
 * Decode `char *' source with `unsigned int' size.
 * Returns a `unsigned char *' base64 decoded string.
 */
unsigned int
b64_decode (const char *, unsigned int);


int isalnum(int c);
void * memset ( void * ptr, int value, unsigned long num );
void * memcpy ( void * destination, const void * source, unsigned long num );

#ifdef __cplusplus
}
#endif

#endif
