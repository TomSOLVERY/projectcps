#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>
#include "convertion.h"
#include "projet.h"

rgb pixel_to_rgb(uint64_t pixel)
{
  rgb colours;
  colours.blue = (pixel & (uint64_t)0xffff);
  colours.green = (pixel & (uint64_t)0xffff0000);
  colours.green = (colours.green >> 16);
  colours.red = (pixel & (uint64_t)0xffff00000000);
  colours.red = (colours.red >> 32);
  return colours;
}



image P3_to_P2(image imgP3, char *nom_P3)
{
  image imgP2;
  imgP2.magicnumber = P2;
  imgP2.hauteur = imgP3.hauteur;
  imgP2.largeur = imgP3.largeur;
  imgP2.maxpixel = imgP3.maxpixel;
  imgP2.pixels = malloc(imgP2.largeur * imgP2.hauteur * sizeof(uint64_t));
  rgb temp;
  for (int i = 0; i < imgP2.largeur * imgP2.hauteur; i++)
  {
    temp = pixel_to_rgb(imgP3.pixels[i]);
    imgP2.pixels[i] = (0.299 * temp.red) + (0.587 * temp.green) + (0.114 * temp.blue);
  }
  return imgP2;
}



image binarisation(image img, float alpha)
{
  if ((img.magicnumber != P3) || (alpha > 1.0 || alpha < 0.0))
  {
    printf("Erreur sur la binarisation. Type Image doit etre P3 et alpha entre 0 et 1");
    exit(-1);
  }
  float val;
  rgb c;
  img.magicnumber = P1;
  for (int i = 0; i < (img.largeur * img.hauteur); i++)
  {
    c = pixel_to_rgb(img.pixels[i]);
    val = (float)(c.red * c.green * c.blue / pow(img.maxpixel, 3));
    img.pixels[i] = (val >= alpha ? 1 : 0);
  }
  return img;
}