#include "linkedListOfMusic.h"
#include "linkedList.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ============
// Definitions of external functions
// ============
void afficheElement(Element e) {
    Music* music=(Music *)e;
    printf("%s,%s,%s,%s,%s,%s,%s",music->name,music->Artist,music->Album,music->Genre,music->Disc_Number,music->Track_Number,music->Year);
}

void detruireElement(Element e) {
    free(e);
}

// compare deux elements
bool equalsElement(Element e1, Element e2){
    Music* music1=(Music *)e1;
    Music* music2=(Music *)e2;
	return strcmp(music1->name,music2->name)==0;
}

// ============
// Functions implementation
// ============

Liste readMusics(char* line,Liste l){
    Music *music=malloc(sizeof(Music));
    music->name=strsep(&line, ",");
    music->Artist=strsep(&line, ",");
    music->Album=strsep(&line, ",");
    music->Genre=strsep(&line, ",");
    music->Disc_Number=strsep(&line, ",");
    music->Track_Number=strsep(&line, ",");
    music->Year=strsep(&line, ",");
    return ajoutTete(music,l);
    //printf("%s\n",((Music*)l->val)->name);
}

Liste trierParDate(Liste l){
    Liste* temp;

    Liste z=l;
    while(z != NULL){
        Liste p=z; 
        while (p->suiv !=NULL){
            if(atoi(((Music*)p->val)->Year) > atoi(((Music*)p->suiv->val)->Year)){
                temp = (p->val);
                (p->val) = (p->suiv->val);
                (p->suiv->val) = temp;
            }
            p = p->suiv;
        }
        z = z->suiv;
    }
    return l;
}