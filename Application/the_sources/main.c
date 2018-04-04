#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "projet.h"
#include "openandsave.h"
#include "convertion.h"

int main(int argc,char **argv){
  image imgP3;
  char temp[] = "temp";
  if (argc == 1 || (fopen(argv[1], "r") == NULL))
  {
    printf("\n =======");
    printf("\nPas de fichier fourni ou mauvais nom de fichier. On travaille sur l'entree standart\n");
    stdin_to_P3(temp);
    imgP3 = P3Lecture(temp);
    image imgP2 = P3_to_P2(imgP3, temp);
    save(imgP2, temp, 1);
    remove(temp);
  }
  else
  {
  image imgP3 = P3Lecture(argv[1]);
  image imgP2 = P3_to_P2(imgP3, argv[1]);
  save(imgP2, argv[1], 0);
  }
}

