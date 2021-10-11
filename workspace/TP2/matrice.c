#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

int ROWS=5;
int COLS=5;
int MIDL=5;

void affiche_matrice(int64_t matriceResultat[5][5]){
    for(int i=0;i < 5;i++){
        for(int j = 0; j < 5; j++){
            printf(" %5li",matriceResultat[i][j]);
            if (j==4)
            {
                printf("\n");
            }
            
            
        }
        
    }
}

void mult_matrice(int64_t matriceResultat[5][5],int64_t matrice1[5][5],int64_t matrice2[5][5]){
    for(int i=0;i < 5;i++){
        for(int j = 0; j < 5; j++){
            matriceResultat[i][j] = 0;
            for (int k = 0; k < 5; k++){
                matriceResultat[i][j]+=matrice1[i][k] * matrice2[k][j];
            }
            
        }
        
    }
    affiche_matrice(matriceResultat);

}

void mult_matrice_gen(int64_t matriceResultat[ROWS][COLS],int64_t matrice1[ROWS][MIDL],int64_t matrice2[MIDL][COLS]){
    for(int i=0;i < ROWS;i++){
        for(int j = 0; j < COLS; j++){
            matriceResultat[i][j] = 0;
            for (int k = 0; k < MIDL; k++){
                matriceResultat[i][j]+=matrice1[i][k] * matrice2[k][j];
            }
            printf(" %5li",*(*(matriceResultat+i)+j));
               if (j==COLS-1)
            {
                printf("\n");
            }
        }
        
    }

}

/*
void mult_matrice_generale(int64_t ** matriceResultat,int64_t ** matrice1,int64_t  ** matrice2,int l1,int c1,int c2){
    for(int i=0;i < l1 ;i++){
        for(int j = 0; j < c2 ; j++){

            *(*(matriceResultat+i)+j) = 0;
            for (int k = 0; k < c1; k++){
             *(*(matriceResultat+i)+j) +=    *(*(matriceResultat+i)+k) *  *(*(matriceResultat+k)+j);
            }
            
            printf(" %5li",*(*(matriceResultat+i)+j));
               if (j==c2-1)
            {
                printf("\n");
            }

        }
        
    }
    //affiche_matrice(matriceResultat);

}
*/

int main(void) {
    //matrices en ligne * colonne
    
    int64_t matrice1[5][5]={{1,2,3,4,5},{1,2,3,4,5},{1,2,3,4,5},{1,2,3,4,5},{1,2,3,4,5}};
    int64_t matrice2[5][5]={{6,7,8,9,10},{6,7,8,9,10},{6,7,8,9,10},{6,7,8,9,10},{6,7,8,9,10}};
    int64_t matriceResultat[5][5];
    mult_matrice(matriceResultat,matrice1,matrice2);
    mult_matrice_gen(matriceResultat,matrice1,matrice2);
    

    return EXIT_SUCCESS;
}
