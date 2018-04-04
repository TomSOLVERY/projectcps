#include <stdio.h>
#include <stdint.h>
#include "openandsave.h"
#include "projet.h"

uint64_t rgb_to_pixel (rgb colours){  
  uint64_t pixel = 0;
  pixel |= colours.red;
  pixel = (pixel << 16); 
  pixel |= colours.green;
  pixel = (pixel << 16);
  pixel |= colours.blue;
  return pixel;
}

image P3Lecture (char *nom_image){
  FILE *f;
  int entier;
  char c;
  image img;
  rgb colours;
    
  f = fopen(nom_image, "r");
    
  fscanf(f, "%c", &c);
  fscanf(f, "%d", &entier);

  if (entier != 3){ 
    printf("Erreur, l'image n'est pas de type PPM P3");
    exit (-1);
  }
  img.magicnumber = P3;
  fscanf(f, "%d", &entier);
  img.largeur = entier;
  fscanf(f, "%d", &entier);
  img.hauteur = entier;
  fscanf(f, "%d", &entier);
  img.maxpixel = entier;

  img.pixels = malloc(img.largeur * img.hauteur * sizeof(uint64_t));

  int i = 0;
  while (fscanf (f, "%d", &entier) != EOF) {
    colours.red = entier;
    fscanf (f, "%d", &entier);
    colours.green = entier;
    fscanf (f, "%d", &entier);
    colours.blue = entier;
    img.pixels[i] = rgb_to_pixel (colours);
    i++;
  }
  fclose (f);
  return img;
}