#include <stdio.h>
#include <stdint.h>
#include "projet.h"
#include "traitement.h"
#include "openandsave.h"

int main(){

    uint64_t pixel = 255;
    rgb couleur = calculpixels(pixel);
    printf("rouge = %lui\n",couleur.red);
    printf("vert = %lui\n",couleur.green);
    printf("bleu = %lui\n",couleur.blue);

}

