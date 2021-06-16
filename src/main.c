#include <errno.h>
#include <magic.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <turbojpeg.h>

#include "io.h"

int main(int argc, char *argv[]) {
  if (argc < 3) {
    printf("Usage: neovis /path/to/input_image /path/to/output_image");
    return 1;
  }
  Image image;
  read_image(&image, argv[1]);
  write_image(&image, argv[2]);

  if (image.buf) {
    free(image.buf);
    return 0;
  }

  return 0;
}