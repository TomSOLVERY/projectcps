#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "convertionP2.h"
#include "projet.h"

rgb pixel_to_rgb (uint64_t pixel){
  rgb colours;
  colours.blue = (pixel & (uint64_t)0xffff);
  colours.green = (pixel & (uint64_t)0xffff0000);
  colours.green = (colours.green >> 16);
  colours.red = (pixel & (uint64_t)0xffff00000000);
  colours.red = (colours.red >> 32);
  return colours; 
}

void P3_to_P2 (image imgP3, char *nom_P3){
  image imgP2;
  imgP2.magicnumber = P2;
  imgP2.hauteur = imgP3.hauteur;
  imgP2.largeur = imgP3.largeur;
  imgP2.maxpixel = imgP3.maxpixel;
  imgP2.pixels = malloc(imgP2.largeur * imgP2.hauteur * sizeof(uint64_t));
  rgb temp;
  for (int i = 0; i < imgP2.largeur * imgP2.hauteur; i++){
    temp = pixel_to_rgb(imgP3.pixels[i]);
    imgP2.pixels[i] = (0.299 * temp.red) + (0.587 * temp.green) + (0.114 * temp.blue);
  }
  
  FILE *f;
  char nom_P2 [64];
  int i = 0;
  while (nom_P3[i] != '.'){
    nom_P2[i] = nom_P3[i];
    i++;
  }
  nom_P2[i] = '.';
  nom_P2[i+1] = 'p';
  nom_P2[i+2] = 'b';
  nom_P2[i+3] = 'm';

  f = fopen(nom_P2, "w");
  fprintf(f, "P2");
  fprintf(f, "\n");
  fprintf(f, "%llu", imgP2.largeur);
  fprintf(f, "\t");
  fprintf(f, "%llu", imgP2.hauteur);
  fprintf(f, "\n");
  fprintf(f, "%llu", imgP2.maxpixel);
  fprintf(f, "\n");
  for (int i = 0; i < imgP2.hauteur; i++){
    for (int j = 0; j < imgP2.largeur; j++){
      fprintf(f, "%llu", imgP2.pixels[(i*imgP2.largeur)+j]);
      fprintf(f, "\t");
    }
    fprintf (f, "\n");
  }
  fclose(f);
}