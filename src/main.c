#include <errno.h>
#include <magic.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <turbojpeg.h>

#define NA 0
#define JPG 1

typedef struct FORMAT {
  unsigned int id;
  char *signture;
} FORMAT;

FORMAT SUPPORTED_FORAMTS[] = {
    {.id = JPG, .signture = "\xff\xd8\xff"},
};

unsigned int find_file_signture_id(char *filePath) {
  size_t i, signture_len, max_signture_len = 0;
  unsigned int NUM_SUPPORTED_FORMATS =
      sizeof(SUPPORTED_FORAMTS) / sizeof(FORMAT);

  for (i = 0; i < NUM_SUPPORTED_FORMATS; i++) {
    size_t len = strlen(SUPPORTED_FORAMTS[i].signture);
    if (len > max_signture_len) {
      max_signture_len = len;
    }
  }

  // TODO: open file only once for both signature check and image reading
  FILE *file = fopen(filePath, "rb");
  if (!file) {
    return NA;
  }

  char *signture = (char *)malloc(max_signture_len);
  memset(signture, 0, max_signture_len);
  signture_len = fread(signture, 1, max_signture_len, file);
  fclose(file);

  for (i = 0; i < NUM_SUPPORTED_FORMATS; i++) {
    if (memcmp(signture, SUPPORTED_FORAMTS[i].signture, signture_len) == 0) {
      return SUPPORTED_FORAMTS[i].id;
    }
  }
  return NA;
}

// Read an image into an uncompressed buffer
// MUST be freed
unsigned char *read_image(char *imPath) {
  unsigned char *imBuf = NULL;

  unsigned int signture_id = find_file_signture_id(imPath);
  switch (signture_id) {
  case JPG:
    imBuf = read_jpg(imPath);
    break;

  default:
    fprintf(stderr, "Unsupported file format.\n");
    return NULL;
  }
  return imBuf;
}

unsigned char *read_jpg(char *imPath) {
  tjscalingfactor scalingFactor = {1, 1};
  int outSubsamp = -1, outQual = -1;
  tjtransform xform;
  int flags = 0;
  int width, height;
  char *inFormat, *outFormat;
  FILE *jpegFile = NULL;
  unsigned char *imgBuf = NULL, *jpegBuf = NULL;
  int retval = 0, i, pixelFormat = TJPF_UNKNOWN;
  tjhandle tjInstance = NULL;

  // TODO: complete jpeg
  return NULL;
}

int main(int argc, char *argv[]) {
  if (argc < 2) {
    printf("Usage: neovis /path/to/image");
    return 1;
  }
  printf("%d\n", find_file_signture_id(argv[1]));
  return 0;
}