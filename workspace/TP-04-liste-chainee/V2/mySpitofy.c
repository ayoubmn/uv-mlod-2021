#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "linkedListOfMusic.h"
#include "linkedList.h"



// ============
// main
// ============

void readFromFile(){
    
}

int main(void){
    char musicsFile[] = "music.csv";
    FILE* f;
    f=fopen(musicsFile,"r");
    char buffer[512];
    Liste musicL;
    musicL=NULL;
    printf("%s",fgets(buffer, 512, f));
    //free(champs);

    while (fgets(buffer, 512, f)){
        musicL=readMusics(buffer,musicL);
    }

    //afficheListe_i(musicL);
    //afficheEnvers_r(musicL);

    //tri

    /*
    musicL=trierParDate(musicL);
    afficheEnvers_r(musicL);
    */

    //free
	detruire_r(musicL);

}
