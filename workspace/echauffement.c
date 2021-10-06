#include <stdio.h>

float calcPrixBillet(float prix_plein_tarif,int age);

int main(void) {
    float r=calcPrixBillet(6.15,5);
    printf("%f",r);
    return 0;
}

float calcPrixBillet(float prix_plein_tarif,int age){
    if (age<2)
        return 0.1*prix_plein_tarif;
    else if (age<12)
        return 0.5*prix_plein_tarif;
    else
        return prix_plein_tarif;

}

