#include "liste-chainee.h"
#include <stdlib.h>
#include <stdio.h>

#define TODO NULL;

// retourne vrai si l est vide et faux sinon
bool estVide(Liste l) {
	return l == NULL;
}

// créer une liste d'un seul élément contenant la valeur v
Liste creer(Element v){
	Liste myList=malloc(sizeof(Cellule));
	myList->val=v;
	myList->suiv=NULL;
	return myList;
}

// ajoute l'élément v en tete de la liste l
Liste ajoutTete(Element v, Liste l) {
	Liste myCel=creer(v);
	myCel->suiv=l;	
	return myCel;
	
}


void afficheElement(Element e) {
	printf("%i ",e);
}

// affiche tous les éléments de la liste l
// Attention, cette fonction doit être indépendante du type des éléments de la liste
// utiliser une fonction annexe affiche_element
// Attention la liste peut être vide !
// version itérative
void afficheListe_i(Liste l) {
	printf("\n");
	Liste i=l;
	if (!estVide(i)){
		afficheElement(i->val);
		while (i->suiv!=NULL){
			i=i->suiv;
			afficheElement(i->val);
		}
	}
}

// version recursive
void afficheListe_r(Liste l) {
	if (!estVide(l)){
		afficheElement(l->val);
		if (l->suiv!=NULL){
			afficheListe_r(l->suiv);
		}
	}
	
}

void detruireElement(Element e) {}

// Détruit tous les éléments de la liste l
// version itérative
void detruire_i(Liste l) {
	Liste i=l;
	if (!estVide(i)){
		while (i->suiv!=NULL){
			Cellule* c=i;
			i=i->suiv;
			c->suiv=NULL;
			free(c);
		}
		l->suiv=NULL;
		free(l);
	}

	/*
	Liste i;
		while (!estVide(i)){
			i=l;
			l=l->suiv;
			detruireElement(i->val);
			free(i);
		}
		l=NULL;
	*/
	
}

// version récursive
void detruire_r(Liste l) {
	if (!estVide(l)){
		if (l->suiv!=NULL){
			Liste i=l->suiv;
			detruire_r(i);
			l->suiv=NULL;
			free(l);
		}else{
			l->suiv=NULL;
			free(l);
		}
	}

/*
	if(!estVide(l)){
		detruire_r(l->suiv);
		detruireElement(l->val);
		free(l);
	}
*/
}

// retourne la liste dans laquelle l'élément v a été ajouté en fin
// version itérative
Liste ajoutFin_i(Element v, Liste l) {
	Liste myCel=creer(v);
	Liste i=l;
	if (!estVide(i)){
		while (i->suiv!=NULL){
			i=i->suiv;
		}
		i->suiv=myCel;
	}else{
		l=myCel;
	}
	return l;
}

// version recursive
Liste ajoutFin_r(Element v, Liste l) {
	if (!estVide(l)){
		if (l->suiv==NULL){
			Liste myCel=creer(v);
			l->suiv=myCel;
		}else{
			ajoutFin_r(v,l->suiv);
		}		
	}else{
		Liste myCel=creer(v);
		l=myCel;
	}
	return l;
}


// compare deux elements
bool equalsElement(Element e1, Element e2){
	return e1 == e2;
}

// Retourne un pointeur sur l'élément de la liste l contenant la valeur v ou NULL
// version itérative
Liste cherche_i(Element v,Liste l) {
	Liste i=l;
	if (!estVide(i)){
		
		while (i->suiv!=NULL){
			if (i->val==v)
				return i;
			i=i->suiv;
		}
		if (i->val==v)
			return i;
	}
	return NULL;

	/*
	while(!estVide(l) && !equalsElement(v,l->v)){
		l=l->suiv;
	}
	return l;
	*/
}

// version récursive
Liste cherche_r(Element v,Liste l) {
	if (!estVide(l)){
		if (l->val==v){
			return l;
		}else{
			cherche_r(v,l->suiv);
		}
	}else{
		return NULL;
	}


	/*
	
	*/
}

// Retourne la liste modifiée dans la laquelle le premier élément ayant la valeur v a été supprimé
// ne fait rien si aucun élément possède cette valeur
// version itérative
Liste retirePremier_i(Element v, Liste l) {

	if (!estVide(l)){
		Liste i=l;
		//first element
		if (l->val==v){
				l=l->suiv;
				return l;
		}
		Liste R=cherche_i(v,l);
		Liste x=l;	
		while (!estVide(i->suiv)){
			if (i->val==v){
				x->suiv=R->suiv;
				return l;
			}
			x=i;
			i=i->suiv;
		}
		if (i->val==v)
			x->suiv=R->suiv;
		free(R);
	}
	return l;

}


// version recursive
Liste retirePremier_r(Element v, Liste l) {
	if (!estVide(l)){
		if (l->val==v){
			l=l->suiv;
			return l;
		}
		if ((l->suiv)->val==v){
			Liste R=cherche_i(v,l);
			l->suiv=R->suiv;
			free(R);
		}else{
			retirePremier_r(v,l->suiv);
		}
		return l;
	}
	return NULL;

}


void afficheEnvers_r(Liste l) {
	TODO;
}



