#ifndef IMAGE_H
#define IMAGE_H

enum ColorSpace { CS_RGB, CS_YCbCr, CS_GRAY, CS_CMYK, CS_YCCK };

enum PixelFormat {
  PF_RGB,
  PF_BGR,
  PF_RGBA,
  PF_BGRA,
  PF_ARGB,
  PF_ABGR,
  /* Ignore Alpha */
  PF_RGBX,
  PF_BGRX,
  PF_XRGB,
  PF_XBGR,
  /* -- */
  PF_CMYK,
  PF_GRAY,
  PF_UNKNOWN = -1
};

// Maps to pixel format to its size in bytes
const int PF_SIZE[];

typedef struct {
  unsigned int width, height, nchannels;
  unsigned char *buf;
  enum ColorSpace colorspace;
  enum PixelFormat pixelforamt;
} Image;

// TODO: convert between different formats and color spaces

#endif
