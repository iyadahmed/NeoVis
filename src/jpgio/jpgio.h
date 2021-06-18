#ifndef JPGIO_H
#define JPGIO_H

#include <stddef.h>
#include <turbojpeg.h>

#include "common.h"
#include "image.h"

#define DEFAULT_JPG_QUALITY 95
#define DEFAULT_JPG_SUBSAMP TJSAMP_444
#define DEFAULT_JPG_PIXELFORMAT TJPF_RGBX
#define DEFAULT_JPG_FLAGS 0

extern const IntPair TJPF_PIXELFORMAT_PAIRS[];
extern const size_t NUM_TJPF_PIXELFORMAT_PAIRS;
extern const size_t NUM_TJCS_COLOSPACE_PAIRS;

int read_jpg(Image *image, char *imgPath);
int write_jpg(Image *image, char *img_path, int quality,
              enum TJSAMP chroma_subsampling, enum TJPF pixel_format,
              int flags);

#endif /* JPGIO_H */