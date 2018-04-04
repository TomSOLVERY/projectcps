#ifndef OPENANDSAVE_H
#define OPENANDSAVE_H
#include "projet.h"

uint64_t rgb_to_pixel(rgb);
void stdin_to_P3 (char *);
void save(image, char *, int);
image P3Lecture (char *);

#endif