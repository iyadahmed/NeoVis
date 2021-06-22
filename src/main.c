#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <turbojpeg.h>

#include "image.h"
#include "io.h"
#include "nodes.h"

int main(int argc, char *argv[]) {
  // if (argc < 3) {
  //   puts("Usage: neovis /path/to/input_image /path/to/output_image");
  //   return 1;
  // }
  // Image image;
  // if (read_image(&image, argv[1]) < 0) {
  //   puts("Failed to read image file");
  //   return 1;
  // }

  // if (write_image(&image, argv[2]) < 0) {
  //   puts("Failed to write image file");
  //   return 1;
  // }

  // if (image.buf) {
  //   free(image.buf);
  // }

  // Test nodes
  Node *node = create_node(NODE_ADD);
  *(float *)(node->inputs[0].value) = 42.5f;
  *(float *)(node->inputs[1].value) = 102.f;
  node->exec(node);
  printf("%f\n", *(float *)(node->outputs[0].value));

  FREE_NODE(node);

  return 0;
}