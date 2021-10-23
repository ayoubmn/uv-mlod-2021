#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "linkedListOfMusic.h"
#include "linkedList.h"



// ============
// main
// ============
int main(void){
    char musicsFile[] = "music.csv";
    FILE* f;
    f=fopen(musicsFile,"r");
    char buffer[1024];
    Liste musicL;
    musicL=NULL;
    char* champs=fgets(buffer, 1024, f);
    printf("%s",champs);

    while (fgets(buffer, 1024, f))
    {
        char* line = strdup(buffer);
        musicL=readMusics(line,musicL);
        //free(line);
    }
    //afficheListe_i(musicL);
    afficheEnvers_r(musicL);
    //free(musicL);




}
