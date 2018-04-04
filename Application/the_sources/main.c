#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "projet.h"
#include "openandsave.h"
#include "convertion.h"
#define ALPHA 0.2

int main(int argc,char **argv){
  image imgP3 = P3Lecture(argv[1]);
  image imgP2 = P3_to_P2(imgP3);
  image imgP1 = binarisation(imgP3,ALPHA);
  save(imgP2,argv[1]);
  save(imgP1,argv[1]);
}

