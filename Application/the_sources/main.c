#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "projet.h"
#include "openandsave.h"
#include "convertion.h"

int main(int argc,char **argv){
  image imgP3 = P3Lecture(argv[1]);
  image imgP2 = P3_to_P2(imgP3, argv[1]);
  save(imgP2,argv[1]);
}

