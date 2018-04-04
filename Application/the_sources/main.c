#include <stdio.h>
#include <stdint.h>
#include "projet.h"
#include "traitement.h"
#include "openandsave.h"
#include "convertionP2.h"

int main(){
  image imgP3 = P3Lecture(argv[1]);
  P3_to_P2(imgP3, argv[1]);
}

