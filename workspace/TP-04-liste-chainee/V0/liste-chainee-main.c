// gcc -W -Wall -std=c99 liste-chainee.c liste-chainee-main.c -o liste-chaine-main
// gcc -W -Wall -Wno-unused-parameter -std=c99 liste-chainee.c liste-chainee-main.c -o liste-chaine-main

#include "liste-chainee.h"
#include <stdlib.h>
#include <stdio.h>

int main(void){
	Liste l, p;

	l = NULL;
	afficheListe_i(l);

	printf("\nestVide(l) = %s\n",estVide(l)?"TRUE":"FALSE");

	l = ajoutTete(1,l);
	l = ajoutTete(2,l);
	l = ajoutTete(4,l);
	l = ajoutTete(1,l);
	l = ajoutTete(5,l);
	l = ajoutTete(6,l);
	l = ajoutTete(2,l);
	l = ajoutTete(4,l);
	l = ajoutTete(1,l);

	//afficheListe_i(l);

	ajoutFin_i(99,l);

	//afficheListe_i(l);

	ajoutFin_r(100,l);
	afficheListe_i(l);

	p = cherche_i(200,l);
	printf("\ncherche_i(200) : %s\n",estVide(p)?"pas trouve":"[ERREUR] trouve !!!");

	p = cherche_i(99,l);
	if(estVide(p))
		printf("cherche_i(99) : [ERREUR] pas trouve \n");
	else {
		printf("cherche_i(99) : trouve ");
		afficheElement(p->val);
		printf("\n");
	}

	p = cherche_r(200,l);
	printf("cherche_r(200) : %s\n",estVide(p)?"pas trouve":"[ERREUR] trouve !!!");

	p = cherche_r(99,l);
	if(estVide(p))
		printf("cherche_r(99) : [ERREUR] pas trouve \n");
	else {
		printf("cherche_r(99) : trouve ");
		afficheElement(p->val);
		printf("\n");
	}

	printf("\nretirePremier_i(1)   : ");
	l = retirePremier_i(1,l);
	afficheListe_r(l);

	printf("\nretirePremier_i(1)   : ");
	l = retirePremier_i(1,l);
	afficheListe_r(l);

	printf("\nretirePremier_i(100) : ");
	l = retirePremier_i(100,l);
	afficheListe_r(l);

	printf("\nretirePremier_r(4)   : ");
	l = retirePremier_r(4,l);
	afficheListe_r(l);




	printf("\nretirePremier_r(4)   : ");
	l = retirePremier_r(4,l);
	afficheListe_r(l);


	printf("\nretirePremier_r(99)  : ");
	l = retirePremier_r(99,l);
	afficheListe_r(l);

	detruire_i(l);
	//afficheListe_i(l);

	return EXIT_SUCCESS;
}