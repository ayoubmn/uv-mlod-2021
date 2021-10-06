#include <stdio.h>

float calcPrixBillet(float prix_plein_tarif,int age){
    if (age<2)
        return 0.1*prix_plein_tarif;
    else if (age<12)
        return 0.5*prix_plein_tarif;
    else
        return prix_plein_tarif;

}

int main(void) {
    int age =5;
    float plein_tarif=7;
    float r=calcPrixBillet(plein_tarif,age);
    printf("%.2f \n",r);

    return 0;
}
