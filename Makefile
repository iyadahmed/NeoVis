CC= gcc
CFLAGS= -O2 -std=c99 -Wconversion -Wall -Wextra -pedantic
LDFLAGS= -static -pthread -lturbojpeg

default:
	@mkdir -p build
	@cmake .. -G"Unix Makefiles" -S . -B build
	@$(MAKE) -C build

.PHONY: clean
clean:
	@rm -r build