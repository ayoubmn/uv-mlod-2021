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

    while (fgets(buffer, 512, f)){
        musicL=readMusics(buffer,musicL);
    }

    //reafficher la liste
    afficheEnvers_r(musicL);

    //tri
    /*
    musicL=trierParDate(musicL);
    afficheListe_i(musicL);
    */

    //free
	detruire_r(musicL);

    //total heap usage: 8,106 allocs, 8,105 frees, 389,301 bytes allocated

}
