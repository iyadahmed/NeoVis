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
  char *signature;
} FileFormat;

const FileFormat SUPPORTED_FORMATS[];
const size_t NUM_SUPPORTED_FORMATS;

FileFormatID format_id_from_signature(char *file_path);
FileFormatID format_id_from_extension(char *file_path);
int read_image(Image *image, char *img_path);
int write_image(Image *image, char *img_path);

#endif