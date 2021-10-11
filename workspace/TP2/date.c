#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

enum mois {jan = 1, fev, mars, avr, mai, juin,
juil, aout, sept, oct, nov, dec};

typedef enum mois Mois;

struct date{
    int jour;
    Mois mois; 
    int annee;
};

typedef struct date Date;


void initialiseDate(Date * d){
    printf("veillez inserer un jour, un mois , une annee \n");

    scanf("%d %d %d",&((*d).jour),(int *)&((*d).mois),&((*d).annee));
}

void afficheDate(Date * d){
    printf("La date est le %d/%d/%d \n",(*d).jour,(*d).mois,(*d).annee);
}

Date creerDateParCopie(){
    Date t;
    printf("veillez inserer un jour, un mois , une annee \n");

    scanf("%d %d %d",&(t.jour),(int *)&(t.mois),&(t.annee));
    return t;
}

Date* newDate(){
    Date *d=NULL;
    d= malloc(sizeof(*d));
    printf("veillez inserer un jour, un mois , une annee \n");
    scanf("%d %d %d",&((*d).jour),(int *)&((*d).mois),&((*d).annee));
    return d;

}

 
unsigned int nbreJours(Mois mois, unsigned int annee){

     switch (mois){
        case 1 :
            return 31;
        case 3 :
            return 31;
        case  5 :
            return 31;
        case 7  :
            return 31;
        case 8 :
            return 31;
        case 10 :
            return 31;

        case 2 :
            return 29;

        case 4 :
            return 30;
        case 6 :
            return 30;
        case  9  :
            return 30;
        case 11 :
            return 30;
        default:
            break;
     }
 }


bool dateValide(Date uneDate){
    if(uneDate.jour<nbreJours(uneDate.mois,uneDate.annee)){
        if (uneDate.mois<13){
            return 1;
        }
    }
    return 0;
}

unsigned int jourDansAnnee(Date uneDate){
    int nbrJours=uneDate.jour;
    int nbrMois=uneDate.mois;
    nbrMois-=1;
    while (nbrMois>0){
        nbrJours+=nbreJours(nbrMois,uneDate.annee);
        nbrMois-=1;
    }
    return nbrJours;
}

int main(void){
/*
    Date d;
    initialiseDate(&d); 
    d = creerDateParCopie();
*/

    Date *date;
    date = newDate();
    afficheDate(date);
    //...
    free(date);



    return 0;
}