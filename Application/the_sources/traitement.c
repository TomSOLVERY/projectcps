#include<stdio.h>
#include<stdint.h>
#include <math.h>
#include "traitement.h"
#include "projet.h"


rgb calculpixels(uint64_t pixels){
        rgb color;
        color.blue = (pixels << 48);
        color.green = (pixels << 32);
        color.green = (color.green >> 16);
        color.red = (pixels << 16);
        color.red = (color.red >> 32);
        return color;
}

image binarisation(image img,float alpha){
    if((img.magicnumber != P3)||(alpha > 1.0 || alpha < 0.0)){
        return NULL;
    }
    float val;
    rgb c;
    img.magicnumber = P1;
    for(int i = 0;i < (img.largeur * img.hauteur);i++){
        c = calculpixels(img.pixels[i]);
        val = (float)(c.red*c.green*c.blue / pow(img.maxpixel,3));
        img.pixels[i] = (val >= alpha ? 1 : 0);
    }
    return img;
}


