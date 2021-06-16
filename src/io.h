#ifndef IO_H
#define IO_H

#include <string.h>

#include "jpgio.h"

#if defined _WIN32 && !defined __MINGW32__
#define strcasecmp stricmp
#define strncasecmp strnicmp
#endif

typedef enum FileFormatID { FF_JPG, FF_PPM, FF_UNKNOWN = -1 } FileFormatID;

typedef struct FileFormat {
  enum FileFormatID id;
  char *signture;
} FileFormat;

const FileFormat SUPPORTED_FORAMTS[] = {
    {.id = FF_JPG, .signture = "\xff\xd8\xff"},
    {.id = FF_PPM, .signture = "\x50\x33\x0a"},
};

const size_t NUM_SUPPORTED_FORMATS =
    sizeof(SUPPORTED_FORAMTS) / sizeof(FileFormat);

FileFormatID format_id_from_signture(char *file_path) {
  size_t i, signture_len, max_signture_len = 0;

  for (i = 0; i < NUM_SUPPORTED_FORMATS; i++) {
    size_t len = strlen(SUPPORTED_FORAMTS[i].signture);
    if (len > max_signture_len) {
      max_signture_len = len;
    }
  }

  FILE *file = fopen(file_path, "rb");
  if (!file) {
    return FF_UNKNOWN;
  }

  char *signture = (char *)malloc(max_signture_len);
  memset(signture, 0, max_signture_len);
  signture_len = fread(signture, 1, max_signture_len, file);
  fclose(file);

  if (signture_len == 0) {
    free(signture);
    return FF_UNKNOWN;
  }

  for (i = 0; i < NUM_SUPPORTED_FORMATS; i++) {
    if (memcmp(signture, SUPPORTED_FORAMTS[i].signture, signture_len) == 0) {
      free(signture);
      return SUPPORTED_FORAMTS[i].id;
    }
  }
  free(signture);
  return FF_UNKNOWN;
}

FileFormatID format_id_from_extension(char *file_path) {
  char *format = strrchr(file_path, '.');
  format++; // skip '.' character
  if (!format) {
    return FF_UNKNOWN;
  }
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
  FileFormatID signture_id = format_id_from_signture(img_path);
  switch (signture_id) {
  case FF_JPG:
    return read_jpg(image, img_path);
  default:
    return -1;
  }
}

int write_image(Image *image, char *img_path) {
  FileFormatID signture_id = format_id_from_extension(img_path);
  switch (signture_id) {
  case FF_JPG:
    return write_jpg(image, img_path, DEFAULT_JPG_QUALITY, DEFAULT_JPG_SUBSAMP,
                     DEFAULT_JPG_PIXELFORMAT, DEFAULT_JPG_FLAGS);
  default:
    return -1;
  }
}

#endif