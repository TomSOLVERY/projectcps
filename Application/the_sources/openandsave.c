#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "openandsave.h"
#include "projet.h"

#define BUF_SIZE 1024

uint64_t rgb_to_pixel(rgb colours)
{
  uint64_t pixel = 0;
  pixel |= colours.red;
  pixel = (pixel << 16);
  pixel |= colours.green;
  pixel = (pixel << 16);
  pixel |= colours.blue;
  return pixel;
}

void stdin_to_P3(char *temp)
{
  if (feof(stdin))
    printf("stdin reached eof\n");

  void *content = malloc(BUF_SIZE);

  FILE *fp = fopen(temp, "w");

  if (fp == 0)
    printf("...something went wrong opening file...\n");

  int read;
  while ((read = fread(content, 1, BUF_SIZE, stdin)))
  {
    fwrite(content, read, 1, fp);
  }
  if (ferror(stdin))
    printf("There was an error reading from stdin");

  printf("\nDone writing\n");

  fclose(fp);
}

image P3Lecture(char *nom_image)
{
  FILE *f;
  int entier;
  char c;
  image img;
  rgb colours;

  f = fopen(nom_image, "r");

  fscanf(f, "%c", &c);
  fscanf(f, "%d", &entier);

  if (entier != 3)
  {
    printf("Erreur, l'image n'est pas de type PPM P3");
    exit(-1);
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
  while (fscanf(f, "%d", &entier) != EOF)
  {
    colours.red = entier;
    fscanf(f, "%d", &entier);
    colours.green = entier;
    fscanf(f, "%d", &entier);
    colours.blue = entier;
    img.pixels[i] = rgb_to_pixel(colours);
    i++;
  }
  fclose(f);
  return img;
}

void save(image img, char *nom_original, int stdin_bool)
{
  FILE *f;

  int i = 0;
  if (!stdin_bool)
  {
    char nom[128];
    while (nom_original[i] != 0)
    {
      nom[i] = nom_original[i];
      i++;
    }
    if(nom[i-1] != 'm' || nom[i-2] != 'p' || nom[i-3] != 'p' || nom[i-4] != '.'){
      fprintf(stderr,"Erreur extension du fichier incorrect\n");
      exit(-1);
    }
    if (img.magicnumber == P2) 
    {
      nom[i - 3] = 'p';
      nom[i - 2] = 'g';
      nom[i - 1] = 'm';
      nom[i] = 0;
    }
    else if (img.magicnumber == P1)
    {
      nom[i - 3] = 'p';
      nom[i - 2] = 'b';
      nom[i - 1] = 'm';
      nom[i] = 0;
    }
    f = fopen(nom, "w");
  } 
  else
  {
    if (img.magicnumber == P2)
    {
      char nom [] = "image.pgm";
      f = fopen(nom, "w");
    }
    else if (img.magicnumber == P1)
    {
      char nom [] = "image.pbm";
      f = fopen(nom, "w");
    }
  }
    img.magicnumber == P2 ? fprintf(f, "P2") : fprintf(f, "P1");
    fprintf(f, "\n");
    fprintf(f, "%u", img.largeur);
    fprintf(f, "\t");
    fprintf(f, "%u", img.hauteur);
    fprintf(f, "\n");
    fprintf(f, "%u", img.maxpixel);
    fprintf(f, "\n");
    for (i = 0; i < img.hauteur; i++)
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
