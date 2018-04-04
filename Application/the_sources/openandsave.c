#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
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

void save(image img, char *nom_original)
{
  FILE *f;
  char nom[64];
  int i = 0;
  while (nom_original[i] != '.')
  {
    nom[i] = nom_original[i];
    i++;
  }
  nom[i] = '.';
  if (img.magicnumber == P2)
  {
    nom[i + 1] = 'p';
    nom[i + 2] = 'g';
    nom[i + 3] = 'm';
  }
  if (img.magicnumber == P1)
  {
    nom[i + 1] = 'p';
    nom[i + 2] = 'b';
    nom[i + 3] = 'm';
  }

  f = fopen(nom, "w");
  img.magicnumber == P2 ? fprintf(f, "P2") : fprintf(f, "P1");
  fprintf(f, "\n");
  fprintf(f, "%u", img.largeur);
  fprintf(f, "\t");
  fprintf(f, "%u", img.hauteur);
  fprintf(f, "\n");
  fprintf(f, "%u", img.maxpixel);
  fprintf(f, "\n");
  for (int i = 0; i < img.hauteur; i++)
  {
    for (int j = 0; j < img.largeur; j++)
    {
      fprintf(f, "%lu", img.pixels[(i * img.largeur) + j]);
      fprintf(f, "\t");
    }
    fprintf(f, "\n");
  }
  fclose(f);
}

