#include "image.h"

const int PF_SIZE[] = {
    [PF_RGB] = 3,  [PF_BGR] = 3,  [PF_RGBA] = 4, [PF_BGRA] = 4,
    [PF_ARGB] = 4, [PF_ABGR] = 4, [PF_GRAY] = 1, [PF_RGBX] = 4,
    [PF_BGRX] = 4, [PF_XRGB] = 4, [PF_XBGR] = 4, [PF_CMYK] = 4};