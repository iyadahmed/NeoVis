#include <string.h>

#include "io.h"
#include "jpgio.h"

const FileFormat SUPPORTED_FORMATS[] = {
    {.id = FF_JPG, .signature = "\xff\xd8\xff"},
    {.id = FF_PPM, .signature = "\x50\x33\x0a"},
};

const size_t NUM_SUPPORTED_FORMATS =
    sizeof(SUPPORTED_FORMATS) / sizeof(FileFormat);

FileFormatID format_id_from_signature(char *file_path) {
  size_t i, signature_len, max_signature_len = 0;

  for (i = 0; i < NUM_SUPPORTED_FORMATS; i++) {
    size_t len = strlen(SUPPORTED_FORMATS[i].signature);
    if (len > max_signature_len) {
      max_signature_len = len;
    }
  }

  FILE *file = fopen(file_path, "rb");
  if (!file) {
    return FF_UNKNOWN;
  }

  char *signature = (char *)malloc(max_signature_len);
  memset(signature, 0, max_signature_len);
  signature_len = fread(signature, 1, max_signature_len, file);
  fclose(file);

  if (signature_len == 0) {
    free(signature);
    return FF_UNKNOWN;
  }

  for (i = 0; i < NUM_SUPPORTED_FORMATS; i++) {
    if (memcmp(signature, SUPPORTED_FORMATS[i].signature, signature_len) == 0) {
      free(signature);
      return SUPPORTED_FORMATS[i].id;
    }
  }
  free(signature);
  return FF_UNKNOWN;
}

FileFormatID format_id_from_extension(char *file_path) {
  char *format = strrchr(file_path, '.');
  if (!format) {
    return FF_UNKNOWN;
  }
  format++; // skip '.' character
  if (!strcasecmp(format, "jpg")) {
    return FF_JPG;
  } else if (!strcasecmp(format, "ppm")) {
    return FF_PPM;
  }

  return FF_UNKNOWN;
}

// Read an image into an uncompressed buffer
// image->buf MUST be freed
// return 0 on sucess, -1 on failure
int read_image(Image *image, char *img_path) {
  FileFormatID signature_id = format_id_from_signature(img_path);
  switch (signature_id) {
  case FF_JPG:
    return read_jpg(image, img_path);
  default:
    return -1;
  }
}

int write_image(Image *image, char *img_path) {
  FileFormatID signature_id = format_id_from_extension(img_path);
  switch (signature_id) {
  case FF_JPG:
    return write_jpg(image, img_path, DEFAULT_JPG_QUALITY, DEFAULT_JPG_SUBSAMP,
                     DEFAULT_JPG_PIXELFORMAT, DEFAULT_JPG_FLAGS);
  default:
    return -1;
  }
}