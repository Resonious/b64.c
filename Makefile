CC=clang
CFLAGS = --target=wasm32 -nostdlib -flto -std=c99 -Wall -O3 -Wl,--no-entry -Wl,--export-all -Wl,--lto-O3
TEST_CFLAGS = -Ideps
CUSTOM_MALLOC_FLAGS = -Db64_malloc=custom_malloc -Db64_realloc=custom_realloc

ifeq ($(USE_CUSTOM_MALLOC), true)
CFLAGS += $(CUSTOM_MALLOC_FLAGS)
endif

default: b64.wasm

b64.wasm: encode.c decode.c buffer.c
	$(CC) $(CFLAGS) $^ -o b64.wasm

test: CFLAGS+=$(TEST_CFLAGS)
test: test.o encode.o decode.o deps/ok/ok.o

clean:
	rm -f *.o *.wasm *.mjs test deps/ok/ok.o

.PHONY: default clean
