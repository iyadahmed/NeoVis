CC=gcc
CFLAGS=-Wall -Wextra -Wpedantic
LDFLAGS=-static -pthread -lturbojpeg

OBJECTS=src/main.c

.PHONY: image-processing
image-processing:
	mkdir -p build
	$(CC) $(CFLAGS) $(OBJECTS) -o build/image-processing $(LDFLAGS)