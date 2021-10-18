#include <stdio.h>
#include <stdlib.h>

struct Matrix{
    int nbrLigne;
    int nbrColonne;
    int* tab;
};
typedef struct Matrix Matrix;

void readMatrix(int l,int c,Matrix* MatrixArray,int* tab){
        
        for (int i = 0; i < l*c; i++){
                int* n=malloc(sizeof(int));
                scanf("%d",n);
                (tab)[i]=*n;
 
        }

}

void readMatrixArray(int nombreM,Matrix* matrixArray){
     for (int i=0;i<nombreM;i++){
        int l,c;
        scanf("%i %i",&l,&c);
        int* tab=calloc(l*c,sizeof(int));
        readMatrix(l,c,matrixArray,tab);
 
        (matrixArray[i*sizeof(Matrix)]).tab=tab;
        (matrixArray[i*sizeof(Matrix)]).nbrLigne=l;
        (matrixArray[i*sizeof(Matrix)]).nbrColonne=c;
        
    }
}

void printMatrix(int l,int c,Matrix* matrixArray){
    int R=0;
    for (int i = 0; i < l*c; i++){
            printf("%d ",(matrixArray->tab)[i]);
       
       printf("\n");
    }
}

void printMatrixArray(int nombreM,Matrix* matrixArray){
     for (int i=0;i<nombreM;i++){
        int l=(matrixArray[i*sizeof(Matrix)]).nbrLigne;
        int c=(matrixArray[i*sizeof(Matrix)]).nbrColonne;
        printMatrix(l,c,matrixArray);
    }

}

int main(int argc, char *argv[])
{
    /*
    //Lire a l'identique
    char buffer[80];
    while( fgets(buffer,50,stdin) != NULL ) {
        printf("%s",buffer);
    }
    */


    int nbr;
    scanf("%d",&nbr);
    Matrix*  matrixArray =malloc(nbr*sizeof(Matrix));
    readMatrixArray(nbr,matrixArray);

 

    //printMatrixArray(nbr,matrixArray);
	return EXIT_SUCCESS;
}

