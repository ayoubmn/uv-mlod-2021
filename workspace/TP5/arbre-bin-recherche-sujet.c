#include "arbre-bin-recherche.h"
#include <stdlib.h>
#include <stdbool.h>

// retourne TRUE si a est l'arbre vide et FALSE sinon
bool estVide(ArbreBinaire a) {
	return a == NULL;
}

// initialise l'arbre a à l'arbre vide
void initialiser(ArbreBinaire* a) {
	*a=NULL;
}

// créer un arbre contenant un seul noeud ayant la valeur e
ArbreBinaire creer(Element e) {
	ArbreBinaire arbre;
	arbre=malloc(sizeof(Noeud));
	arbre->val=e;
	arbre->filsDroit=NULL;
	arbre->filsGauche=NULL;
	return arbre;
}

// insere e dans a sachant que a est un arbre binaire de recherche
// si a contient déjà un element e, ce dernier n'est pas insérer afin d'éviter les doublons
// version itérative
ArbreBinaire insere_i(ArbreBinaire a, Element e) {
	ArbreBinaire l=a;
	if (estVide(a)){
		return creer(e);
	}
	while (!estVide(a)&& e!=a->val){
		ArbreBinaire p=a;
		if (e<a->val){
			a=a->filsGauche;
			if (estVide(a)){
				p->filsGauche=creer(e);
				break;
			}
		}else{
			a=a->filsDroit;
			if (estVide(a)){
				p->filsDroit=creer(e);
				break;
			}
		}
	}
	return l;

}	
// insere e dans a sachant que a est un arbre binaire de recherche
// si a contient déjà un element e, ce dernier n'est pas insérer afin d'éviter les doublons
// version récursive
ArbreBinaire insere_r(ArbreBinaire a, Element e) {

	if (estVide(a)){
		return creer(e);
	}else{

		if (e < a->val)
			a->filsGauche=insere_r(a->filsGauche,e);
		else if(e > a->val)
			a->filsDroit=insere_r(a->filsDroit,e);	
	}

	return a;
	
}
// retourne le nombre de noeud contenus dans l'arbre a
int nombreDeNoeud(ArbreBinaire a){
	if (estVide(a))
		return 0;

	return 1+nombreDeNoeud(a->filsDroit)+nombreDeNoeud(a->filsGauche);
}


// retourne la profondeur du noeud ayant la valeur e dans a
// retourne -1 si a est vide ou si e n'est pas dans a
int profondeur(ArbreBinaire a, Element e){
	int d=0;
	while (!estVide(a)){
		if (e < a->val)
			a=a->filsGauche;
		else if(e > a->val)
			a=a->filsDroit;
		else
			return d+1;
		d=d+1;
	}
	return -1;
}

// retourne la hauteur de l'arbre a
int hauteur(ArbreBinaire a){
	if (estVide(a))
		return 0;
	int G=hauteur(a->filsGauche);
	int D=hauteur(a->filsDroit);
	int MAX=0;
	(G>D)?(MAX=G):(MAX=D);
	return 1+MAX;
}

// retourne le pere de elem dans l'arbre a ou NULL s'il n'existe pas
ArbreBinaire pere(ArbreBinaire a, Element elem){
	if (estVide(a)){
		return NULL;
	}
	while (!estVide(a)){
		ArbreBinaire p=a;
		if(elem<a->val){
			a=a->filsGauche;
		}else{
			a=a->filsDroit;
		}
		if (elem==a->val)
			return a;
		
	}
	return NULL;
}


void afficheRGD_r(ArbreBinaire a){
	if(!estVide(a)){
		printf("%d	",a->val);
		afficheRGD_r(a->filsGauche);
		afficheRGD_r(a->filsDroit);
	}
}

void afficheGRD_r(ArbreBinaire a){
	if(!estVide(a)){
		afficheRGD_r(a->filsGauche);
		printf("%d	",a->val);
		afficheRGD_r(a->filsDroit);
	}
}

void afficheGDR_r(ArbreBinaire a){
	if(!estVide(a)){
		afficheRGD_r(a->filsGauche);
		afficheRGD_r(a->filsDroit);
		printf("%d	",a->val);

	}
}

// retourne le noeud dont la valeur est minimum dans l'arbre
// Suppose que a est un arbre binaire de recherche sans doublons
ArbreBinaire min(ArbreBinaire a){
	ArbreBinaire min;
	while (!estVide(a)){
		ArbreBinaire p=a;
		a=a->filsGauche;
		if(estVide(a))
			return p;
	}
	return NULL;
}

// retourne le noeud dont la valeur est maximum dans l'arbre
// Suppose que a est un arbre binaire de recherche sans doublons
ArbreBinaire max(ArbreBinaire a){
	ArbreBinaire min;
	while (!estVide(a)){
		ArbreBinaire p=a;
		a=a->filsDroit;
		if(estVide(a))
			return p;
	}
	return NULL;}


// retourne l'arbre dont la valeur de la racine est elem et NULL si elem n'existe dans a 
// version récursive
ArbreBinaire recherche_r(ArbreBinaire a, Element elem){
	if (estVide(a) || (elem=a->val))
		return a;
	else{
		if (elem<a->val)
			return recherche_r(a->filsGauche,elem);
		else
			return recherche_r(a->filsDroit,elem);
	}
}


// suppime x de a
ArbreBinaire supprimer_r(ArbreBinaire a,Element x){
/*	
if (estVide(a) || (x=a->val))
		return a;


	if (x=a->filsDroit->val){
	}
		
	else{
		if (x<a->val)
			return supprimer_r(a->filsGauche,x);
		else
			return supprimer_r(a->filsDroit,x);
	}
*/
}

void detruire_r(ArbreBinaire a){
	if( !estVide(a) ){
		detruire_r(a->filsDroit);
		detruire_r(a->filsGauche);
		//free(a->val);
		free(a);
	}
}

