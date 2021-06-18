CC= gcc
CFLAGS= -O2 -std=c99 -Wconversion -Wall -Wextra -pedantic
LDFLAGS= -static -pthread -lturbojpeg

makefiles: clean
	@cmake .. -G"Unix Makefiles" -S . -B build
	@$(MAKE) -C build

ninja: clean
	@cmake .. -GNinja -S . -B build
	@ninja -C build

.PHONY: clean
clean:
	@rm -rf build
	@mkdir build