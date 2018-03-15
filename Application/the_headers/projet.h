#ifndef PROJET_H
#define PROJET_H
typedef enum {P1 = 1,P2=2,P3=3} typeImage;

typedef struct simage {
        typeImage magicnumber;
        unint32_t largeur;
        unint32_t hauteur;
        int maxpixel;
        int pixels[];
    }image;
#endif