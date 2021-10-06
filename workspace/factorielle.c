#include <stdio.h>

typedef short TypeEntier;
TypeEntier factorielle(TypeEntier);

int main(void){
    printf("veuillez choisir un nombre \n");
    TypeEntier n;
    scanf("%hd", &n);
    printf("%hd \n",factorielle(n));
    return 0;
}


TypeEntier factorielle(TypeEntier n){
    TypeEntier result=1;
    while (n>1){
            result=result*n;
            n-=1;
    }
    return result;

}