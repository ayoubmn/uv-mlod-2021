#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

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

int main(void) {
    //matrices en ligne * colonne
    int64_t matrice1[5][5]={{1,2,3,4,5},{1,2,3,4,5},{1,2,3,4,5},{1,2,3,4,5},{1,2,3,4,5}};
    int64_t matrice2[5][5]={{6,7,8,9,10},{6,7,8,9,10},{6,7,8,9,10},{6,7,8,9,10},{6,7,8,9,10}};
    int64_t matriceResultat[5][5];
    mult_matrice(matriceResultat,matrice1,matrice2);
    //affiche_matrice(matriceResultat);
    return EXIT_SUCCESS;
}
