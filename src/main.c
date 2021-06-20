#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <turbojpeg.h>

#include "image.h"
#include "io.h"

int main(int argc, char *argv[]) {
  if (argc < 3) {
    puts("Usage: neovis /path/to/input_image /path/to/output_image");
    return 1;
  }
  Image image;
  if (read_image(&image, argv[1]) < 0) {
    puts("Failed to read image file");
    return 1;
  }

  if (write_image(&image, argv[2]) < 0) {
    puts("Failed to write image file");
    return 1;
  }

  if (image.buf) {
    free(image.buf);
  }

  return 0;
}