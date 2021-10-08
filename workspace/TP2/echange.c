#include <stdio.h>


void echangeContenu(int *a,int*b){
    int c = *a;
    *a=*b;
    *b=c;
}

int main(void){
    int a=10,b=20;
    /*printf("veullez choisir la 1er variable\n");
    scanf('%d',&a);
    printf("veullez choisir la 2eme variable\n");
    scanf('%d',&b);*/
    echangeContenu(&a,&b);
    printf("la valeur de a est : %d , et la valeur de b est: %d \n",a,b);

    return 0;
}