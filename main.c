#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <turbojpeg.h>

// read an image to an uncompressed buffer
int read_image(unsigned char *imBuf, char *imPath) {
  FILE *jpegFile = NULL;
  unsigned char *imgBuf = NULL, *jpegBuf = NULL;
  tjhandle tjInstance = NULL;
  char *inFormat = strrchr(imPath, '.');
  if (inFormat == NULL) {
    fprintf(stderr, "Invalid image file extension");
    return -1;
  }
  // TODO: do common operations first
  // e.g file opening/size-determination
  // we need then to ensure valid extension before
  // TODO: split per extension read into functions
  if (!strcasecmp(inFormat, "jpg")) {
    long size;
    int inSubsamp, inColorspace;
    unsigned long jpegSize;
    if ((jpegFile = fopen(imPath, "rb")) == NULL) {
      fprintf(stderr, "Error opening image file");
      return -1;
    }
    if (fseek(jpegFile, 0, SEEK_END) < 0 || ((size = ftell(jpegFile)) < 0) ||
        fseek(jpegFile, 0, SEEK_SET) < 0) {
      fprintf(stderr, "Failed to determine image file size");
      return -1;
    }
    if (size == 0) {
      fprintf(stderr, "Image file contains no data");
      return -1;
    }
    jpegSize = (unsigned long)size;
    if ((jpegBuf = (unsigned char *)tjAlloc(jpegSize)) == NULL) {
      fprintf(stderr, "Error allocating JPEG buffer");
      return -1;
    }
    if (fread(jpegBuf, jpegSize, 1, jpegFile) < 1) {
      fprintf(stderr, "Error reading JPEG file");
      return -1;
    }
    fclose(jpegFile);
    jpegFile = NULL;
    if ((tjInstance = tjInitDecompress()) == NULL) {
      fprintf(stderr, "Error initializing JPEG decompressor");
      return -1;
    }
  }
  return 1;
}

int main(int argc, char *argv[]) { return 0; }