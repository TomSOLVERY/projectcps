#ifndef PROJET_H
#define PROJET_H
#include <stdint.h>
typedef enum {P1 = 1,P2=2,P3=3} typeImage;

typedef struct simage {
  typeImage magicnumber;
  uint32_t largeur;
  uint32_t hauteur;
  int maxpixel;
  uint64_t *pixels;
}image;

typedef struct srgb {
  uint64_t red;
  uint64_t green;
  uint64_t blue;
} rgb;
#endif