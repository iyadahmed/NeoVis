CC= gcc
CFLAGS= -O2 -std=c99 -Wconversion -Wall -Wextra -pedantic
LDFLAGS= -static -pthread -lturbojpeg

neovis:
	@mkdir -p build
	@$(CC) $(CFLAGS) src/*.c -o build/neovis $< $(LDFLAGS)

.PHONY: clean
clean:
	@rm -r build