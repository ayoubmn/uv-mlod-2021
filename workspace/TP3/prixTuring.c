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


/* This function scans a line of text (until \n) and returns a char* that contains all characters on the line (up to 255) excluding \n.
It also ensures the \0 termination.
**WARNING**: The result of this function has been allocated (calloc) by the function */
char* scanLine()
{
	int maxLineSize = 255;
	char c, *line = calloc(maxLineSize+1,sizeof(char));

	scanf("%250[^\n]", line);

	if ( (c = getchar()) != '\n') {
		/* we did not get all the line */
		line[250] = '[';
		line[251] = line[252] = line[253] = '.';
		line[254] = ']';
		// line[255] = '\0'; // useless because already initialized by calloc

		// let's skip all chars untli the end of line
		while (( (c = getchar()) != '\n') && c != EOF) ;
	}

	return line;
}

/* This function scans a line of text (until \n), converts it as an integer and returns this integer */
int scanLineAsInt() {
	int buf;
	scanf("%i\n",&buf);
	return buf;
}

void readWinners(Winner* tab, int nbGagnants){
    for (int i=0;i<nbGagnants;i++){
        Winner winner;
        winner.date=scanLineAsInt();
        winner.name=scanLine();
        winner.theme=scanLine();
        *(tab+(i*sizeof(Winner))) = winner;
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

/*
    //exo1
	int nbGagnants = scanLineAsInt();
	printf("%i\n",nbGagnants);
    for (int i=0;i<nbGagnants*3-1;i++){
        printf("%s\n",scanLine());
    }
    printf("%s",scanLine());

    //exo2
    int nbGagnants = scanLineAsInt();
    Winner* myTab=readWinners(nbGagnants);
    printf("%d \n", (*(myTab+1*sizeof(Winner))).date );

*/

    int nbGagnants = scanLineAsInt();
    Winner* myTab=malloc(nbGagnants*sizeof(Winner));
    readWinners(myTab,nbGagnants);
    //printWinners(myTab,nbGagnants);
    int annee= atoi(argv[1]);
    infosAnnee(annee,myTab,nbGagnants);
    free(myTab);


	return EXIT_SUCCESS;
}