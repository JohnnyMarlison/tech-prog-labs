#include "stdio.h"
#include <math.h>

int main(){
    float a,b,c;
    scanf("%f%f%f",&a,&b,&c);

    float arifmet;
    arifmet = (a + b + c) / 3;

    printf("ARIFM: \n");
    printf("%f \n",arifmet);

    float geom;
    geom = cbrt(a * b * c);

    printf("GEOM: \n");
    printf("%f\n",geom);
    return 0;
}
