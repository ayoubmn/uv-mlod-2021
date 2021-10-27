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
    Music* music=(Music *)e;
    free(music->name);
    free(e);
}

// compare deux elements
bool equalsElement(Element e1, Element e2){
    Music* music1=(Music *)e1;
    Music* music2=(Music *)e2;
    bool name=strcmp(music1->name,music2->name)==0;
    bool Artiste=strcmp(music1->Artist,music2->Artist)==0;
    bool Album=strcmp(music1->Album,music2->Album)==0;
    bool Genre=strcmp(music1->Genre,music2->Genre)==0;
    bool Disc_Number=strcmp(music1->Disc_Number,music2->Disc_Number)==0;
    bool Track_Number=strcmp(music1->Track_Number,music2->Track_Number)==0;
    bool Year=strcmp(music1->Year,music2->Year)==0;
    
    if (name&&Artiste&&Album&&Genre&&Disc_Number&&Track_Number&&Year)
        return true;
    
	return false;
}

// ============
// Functions implementation
// ============

Liste readMusics(char* buffer,Liste l){
    char* line = strdup(buffer);
    Music *music=malloc(sizeof(Music));
    music->name=strsep(&line, ",");
    music->Artist=strsep(&line, ",");
    music->Album=strsep(&line, ",");
    music->Genre=strsep(&line, ",");
    music->Disc_Number=strsep(&line, ",");
    music->Track_Number=strsep(&line, ",");
    music->Year=strsep(&line, ",");
    //printf("%s\n",music->name);
    free(line);
    return ajoutTete(music,l);
}

Liste trierParDate(Liste l){
    Liste* temp;

    Liste z=l;
    while(!estVide(z)){
        Liste p=l; 
        while (!estVide(p->suiv)){
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