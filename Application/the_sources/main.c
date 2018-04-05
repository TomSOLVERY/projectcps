#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "projet.h"
#include "openandsave.h"
#include "convertion.h"

#define ALPHA 0.1

int main(int argc, char **argv)
{
  image imgP3, img_converti;
  char temp[] = "image.ppm";
  if (argv[1][0] == '-' && (argv[1][1] == 'g' || argv[1][1] == 'b') && argv[1][2] == 0)
  {
    if (argc == 2 || (fopen(argv[2], "r") == NULL))
    {
      printf("\n =======");
      printf("\nPas de fichier fourni ou mauvais nom de fichier. On travaille sur l'entree standart\nDéfinissez votre image à la main, une fois terminée, Faites 2 fois Ctrl+D\n");
      stdin_to_P3(temp);
      imgP3 = P3Lecture(temp);
      if (argv[1][1] == 'g')
        img_converti = P3_to_P2(imgP3);
      else if (argv[1][1] == 'b')
        img_converti = binarisation(imgP3, ALPHA);

      save(img_converti, temp, 1);
    }
    else
    {
      imgP3 = P3Lecture(argv[2]);
      if (argv[1][1] == 'g')
        img_converti = P3_to_P2(imgP3);
      else if (argv[1][1] == 'b')
        img_converti = binarisation(imgP3, ALPHA);

      save(img_converti, argv[2], 0);
    }
  }
  else
  {
    printf("%s n'est pas un commande valide. Veuillez entrer \n -b si vous voulez une binarisation \n -g si vous voulez un passage aux niveaux de gris\n", argv[1]);
    exit(-1);
  }
}
