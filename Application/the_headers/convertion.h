#ifndef CONVERTION_H
#define CONVERTION_H

#include "projet.h"

rgb pixel_to_rgb(uint64_t);
image P3_to_P2(image);
image binarisation(image, float);

#endif