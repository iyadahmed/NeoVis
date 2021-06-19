makefiles: clean
	@cmake .. -G"Unix Makefiles" -S . -B build
	@$(MAKE) --no-print-directory -C build

ninja: clean
	@cmake .. -GNinja -S . -B build
	@ninja -C build

.PHONY: clean
clean:
	@rm -rf build
	@mkdir build