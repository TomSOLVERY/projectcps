#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "projet.h"
#include "openandsave.h"
#include "convertion.h"

#define ALPHA 0.1

int main(int argc,char **argv){
  image imgP3, imgP2, imgP1;
  char temp[] = "temp";
  if (argc == 1 || (fopen(argv[1], "r") == NULL))
  {
    printf("\n =======");
    printf("\nPas de fichier fourni ou mauvais nom de fichier. On travaille sur l'entree standart\nDéfinissez votre image à la main, une fois terminée, Faites 2 fois Ctrl+D\n");
    stdin_to_P3(temp);
    imgP3 = P3Lecture(temp);
    imgP2 = P3_to_P2(imgP3);
    imgP1 = binarisation(imgP3,ALPHA);
    save(imgP2, temp, 1);
    save(imgP1,temp,1);
  }
  else
  {
  imgP3 = P3Lecture(argv[1]);
  image imgP2 = P3_to_P2(imgP3);
  image imgP1 = binarisation(imgP3,ALPHA);
  save(imgP2, argv[1], 0);
  save(imgP1,argv[1],0);
  }
}

