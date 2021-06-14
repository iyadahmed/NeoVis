CC=gcc
CFLAGS=-Wall -Wextra -Wpedantic
LDFLAGS=-static -pthread -lturbojpeg

.PHONY: clean
neovis:
	@mkdir -p build
	@$(CC) -c $(CFLAGS) -o build/main.o src/main.c
	@$(CC) -g -o build/neovis build/main.o $(LDFLAGS)

clean: neovis
	@rm -r build