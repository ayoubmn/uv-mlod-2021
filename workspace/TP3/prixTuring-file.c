/**
 Compilation
 gcc --std=c99 -W -Wall -o prixTuring prixTuring.c

 Exécution
 ./prixTuring < turingWinners.txt > out.txt

 Tests
 diff out.txt turingWinners.txt

 Détection de fuites mémoires
 valgrind --leak-check=yes --leak-check=full --show-leak-kinds=all --show-reachable=no ./prixTuring < turingWinners.txt > out.txt
**/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

struct winner{
    int date;
    char* name;
    char* theme;
};

typedef struct winner Winner;


void readWinners(FILE* f, int nbGagnants){
    char buffer[10];
    for (int i=0;i<nbGagnants;i++){
        Winner winner;
        winner.date=fgets(buffer,10,f) ;
        winner.name=fgets(buffer,10,f) ;
        winner.theme=fgets(buffer,10,f) ;
        //*(tab+(i*sizeof(Winner))) = winner;
    }
}

void printWinners(Winner* winner, int nbrWinners){
    for (int i = 0; i < nbrWinners; i++){
        printf("%d \n", (*(winner+i*sizeof(Winner))).date );
        printf("%s \n", (*(winner+i*sizeof(Winner))).name );
        printf("%s \n", (*(winner+i*sizeof(Winner))).theme );
    }
}

void infosAnnee(int annee,Winner* winner, int nbrWinners){
    for (int i = 0; i < nbrWinners; i++){
        if(((*(winner+i*sizeof(Winner))).date) == annee){

            printf("L'annee %d, le(s) gagnant(s) ont été : %s\nNature des travaux : %s \n", (*(winner+i*sizeof(Winner))).date,(*(winner+i*sizeof(Winner))).name,
            (*(winner+i*sizeof(Winner))).theme  );

        }
    }
}

int main(int argc, char *argv[])
{
    //printf("%s",argv[1]);
    char winnersFile[] = "turingWinners.txt";
    char result[] = "out2.txt";
    FILE* f;
    f=fopen(winnersFile,"r");
    FILE* r;
    r=fopen(result,"w+");
    
    fclose(f);


    //exo1
	char buffer[50];
    fgets(buffer,50,f) ;
    printf("%s\n",buffer);
        
    fprintf(r,"%s",buffer);

    

/*

    //exo2
    int nbGagnants = scanLineAsInt();
    Winner* myTab=readWinners(nbGagnants);
    printf("%d \n", (*(myTab+1*sizeof(Winner))).date );



    int nbGagnants = scanLineAsInt();
    Winner* myTab=malloc(nbGagnants*sizeof(Winner));
    readWinners(myTab,nbGagnants);
    //printWinners(myTab,nbGagnants);
    int annee= atoi(argv[1]);
    infosAnnee(annee,myTab,nbGagnants);
    free(myTab);
*/

	return EXIT_SUCCESS;
}