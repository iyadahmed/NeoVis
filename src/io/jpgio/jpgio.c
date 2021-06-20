#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <turbojpeg.h>

#include "common.h"
#include "image.h"
#include "jpgio.h"

const IntPair TJPF_PIXELFORMAT_PAIRS[] = {
    {TJPF_RGB, PF_RGB},        {TJPF_BGR, PF_BGR},   {TJPF_RGBA, PF_RGBA},
    {TJPF_BGRA, PF_BGRA},      {TJPF_ARGB, PF_ARGB}, {TJPF_ABGR, PF_ABGR},
    {TJPF_RGBX, PF_RGBX},      {TJPF_BGRX, PF_BGRX}, {TJPF_XRGB, PF_XRGB},
    {TJPF_XBGR, PF_XBGR},      {TJPF_CMYK, PF_CMYK}, {TJPF_GRAY, PF_GRAY},
    {TJPF_UNKNOWN, PF_UNKNOWN}};

const size_t NUM_TJPF_PIXELFORMAT_PAIRS =
    sizeof(TJPF_PIXELFORMAT_PAIRS) / sizeof(IntPair);

const IntPair TJCS_COLORSPACE_PAIRS[] = {{TJCS_RGB, CS_RGB},
                                         {TJCS_YCbCr, CS_YCbCr},
                                         {TJCS_GRAY, CS_GRAY},
                                         {TJCS_YCCK, CS_YCCK}};

const size_t NUM_TJCS_COLOSPACE_PAIRS =
    sizeof(TJCS_COLORSPACE_PAIRS) / sizeof(IntPair);

// Uncompress JPG image to a buffer
// image->buf MUST be freed
// returns 0 on sucess, -1 on failure
int read_jpg(Image *image, char *imgPath) {
  int success = 0;
  int flags = 0;
  int width, height;
  unsigned char *img_buf = NULL, *jpeg_buf = NULL;
  int pixel_format = DEFAULT_JPG_PIXELFORMAT;
  FILE *jpeg_file = NULL;
  tjhandle tj_instance = NULL;

  long size;
  int chroma_subsampling, colorspace;
  unsigned long jpeg_size;

  jpeg_file = fopen(imgPath, "rb");
  if (!jpeg_file) {
    BAIL()
  }

  if (fseek(jpeg_file, 0, SEEK_END) < 0 || ((size = ftell(jpeg_file)) < 0) ||
      fseek(jpeg_file, 0, SEEK_SET) < 0) {
    BAIL();
  }
  if (size == 0) {
    BAIL()
  }

  jpeg_size = (unsigned long)size;
  jpeg_buf = (unsigned char *)malloc(jpeg_size);
  if (!jpeg_buf) {
    BAIL()
  }

  if (fread(jpeg_buf, jpeg_size, 1, jpeg_file) < 1) {
    BAIL();
  }
  fclose(jpeg_file);
  jpeg_file = NULL;

  if ((tj_instance = tjInitDecompress()) == NULL) {
    BAIL()
  }

  if (tjDecompressHeader3(tj_instance, jpeg_buf, jpeg_size, &width, &height,
                          &chroma_subsampling, &colorspace) < 0) {
    BAIL();
  }

  img_buf = (unsigned char *)malloc(
      (size_t)(width * height * tjPixelSize[pixel_format]));

  if (!img_buf) {
    BAIL();
  }

  if (tjDecompress2(tj_instance, jpeg_buf, jpeg_size, img_buf, width, 0, height,
                    pixel_format, flags) < 0) {
    BAIL();
  }

  success = 1;

bail:
  if (tj_instance) {
    tjDestroy(tj_instance);
  }
  if (jpeg_buf) {
    free(jpeg_buf);
  }
  if (jpeg_file) {
    fclose(jpeg_file);
  }
  if (success == 1) {
    image->buf = img_buf;
    image->width = (width > 0) ? (unsigned int)width : 0;
    image->height = (height > 0) ? (unsigned int)height : 0;
    image->colorspace = get_int_pair(
        TJCS_COLORSPACE_PAIRS, NUM_TJCS_COLOSPACE_PAIRS, colorspace, CS_RGB);
    image->pixelforamt =
        get_int_pair(TJPF_PIXELFORMAT_PAIRS, NUM_TJPF_PIXELFORMAT_PAIRS,
                     pixel_format, PF_UNKNOWN);
    return 0;
  }
  return -1;
}

int write_jpg(Image *image, char *img_path, int quality,
              enum TJSAMP chroma_subsampling, enum TJPF pixel_format,
              int flags) {
  int success = 0;
  unsigned long jpeg_size = 0;
  unsigned char *jpeg_buf = NULL;
  FILE *jpeg_file = NULL;
  tjhandle tj_instance = NULL;
  if ((tj_instance = tjInitCompress()) == NULL) {
    return -1;
  }
  int jpeg_width = (image->width > INT_MAX) ? INT_MAX : (int)image->width;
  int jpeg_height = (image->height > INT_MAX) ? INT_MAX : (int)image->height;
  if (tjCompress2(tj_instance, image->buf, jpeg_width, 0, jpeg_height,
                  pixel_format, &jpeg_buf, &jpeg_size, chroma_subsampling,
                  quality, flags) < 0) {
    BAIL();
  }

  if ((jpeg_file = fopen(img_path, "wb")) == NULL) {
    BAIL();
  }
  if (fwrite(jpeg_buf, jpeg_size, 1, jpeg_file) < 1) {
    BAIL();
  }

  success = 1;

bail:
  if (tj_instance) {
    tjDestroy(tj_instance);
  }
  if (jpeg_buf) {
    free(jpeg_buf);
  }
  if (jpeg_file) {
    fclose(jpeg_file);
  }

  return success ? 0 : -1;
}