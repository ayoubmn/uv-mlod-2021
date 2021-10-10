#include <stdlib.h>
#include <stdio.h>

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

    scanf("%d %d %d",&((*d).jour),&((*d).mois),&((*d).annee));
}

void afficheDate(Date * d){
    printf("La date est le %d/%d/%d \n",(*d).jour,(*d).mois,(*d).annee);
}

Date creerDateParCopie(){
    Date t;
    printf("veillez inserer un jour, un mois , une annee \n");

    scanf("%d %d %d",&(t.jour),&(t.mois),&(t.annee));
    return t;
}

Date* newDate(){
    Date *d=NULL;
    d= malloc(sizeof(*d));
    printf("veillez inserer un jour, un mois , une annee \n");
    scanf("%d %d %d",&((*d).jour),&((*d).mois),&((*d).annee));
    return d;

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