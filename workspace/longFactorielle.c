#include <stdio.h>

typedef unsigned long long TypeLong;
TypeLong factorielle(TypeLong);

int main(void){
    printf("veuillez choisir un nombre \n");
    TypeLong n;
    scanf("%lld", &n);
    printf("%lld \n",factorielle(n));
    return 0;
}


TypeLong factorielle(TypeLong n){
    TypeLong result=1;
    while (n>1){
            result=result*n;
            n-=1;
    }
    return result;

}