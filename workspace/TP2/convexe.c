#include <stdio.h>
#include <stdbool.h>

bool estConvexe(bool tab[],int length){
    bool state=NULL;
    int n=0;
    for(int i=0;i<length;i++){
        if(i<length-1){

            if(*(tab+i)==true && n==0){
                state=true;
                n+=1;
                continue;
            }

            if(state==true && *(tab+i-1)==false && *(tab+i)==true){
                state=false;
                break;
            }
        }else{

            if( state=false && *(tab+i)==true && *(tab)==true ){
                return true;
            }
        }
        
        
    }
    return state;

}

int main(void){
    bool tab[6]={true,false,false,true,true,true};
    bool convexe=estConvexe(tab,6);
    printf("%d \n",convexe);
    return 0;

}