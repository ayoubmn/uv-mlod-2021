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
                scanf("%d",&(tab[i]));
        }

}

void readMatrixArray(int nombreM,Matrix* matrixArray){
     for (int i=0;i<nombreM;i++){
        int*l=&(matrixArray[i].nbrLigne);
        int*c=&(matrixArray[i].nbrColonne);
        
        scanf("%i %i",l,c);
        int* tab=calloc((*l)*(*c),sizeof(int));
        readMatrix(*l,*c,matrixArray,tab);

        (&matrixArray[i])->tab=tab;
    
    }

}

void printMatrix(int l,int c,Matrix* matrixArray,int nbr){
    int R=0;
    for (int i = 0; i < l*c; i++){
            printf("%d ",(&matrixArray[nbr])->tab[i]);
            R+=1;
            if(R==c){
                printf("\n");
                R=0;

            }
    }
}

void printMatrixArray(int nombreM,Matrix* matrixArray){
     for (int i=0;i<nombreM;i++){
        int l= (*(matrixArray+i)).nbrLigne;
        int c= (*(matrixArray+i)).nbrColonne;
        printMatrix(l,c,matrixArray,i);
    }

}

int main(int argc, char *argv[])
{
    int nbr;
    scanf("%d",&nbr);
    Matrix*  matrixArray =calloc(nbr,sizeof(Matrix));
    readMatrixArray(nbr,matrixArray);


    printMatrixArray(nbr,matrixArray);
	return EXIT_SUCCESS;
}

