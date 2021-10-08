#include <stdio.h>
#include <stdbool.h>

bool estConvexe(bool tab[],int length){
    bool state=NULL;
    int nbrEchange=0;
    for(int i=0;i<length-1;i++){
        if(*(tab+i)!=*(tab+i+1)){
            nbrEchange+=1;
            state=true;
        } 
    }
    if(*(tab+length-1)!=*(tab)){
        nbrEchange+=1;
    } 
    
    if (nbrEchange>2)
        return false;
    else
        return true;

}

int main(void){
    bool tab[6]={true,false,true,false,true,true};
    bool convexe=estConvexe(tab,6);
    printf("%d \n",convexe);
    return 0;

}