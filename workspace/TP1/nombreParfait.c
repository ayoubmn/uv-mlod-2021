#include <stdio.h>

void nombreParfait(int N){
    for(int i=1;i<=N;i++){
        int somme=0;
        for(int j=1;j<=i/2;j++){

            if(i%j==0)
                somme+=j;
        }
        if(somme==i)
            printf("%d \n",i);
    }
}


int main(void) {
    printf("veuillez choisir un nombre \n");
    int n;
    scanf("%d", &n);
    nombreParfait(n);
    return 0;
}
