#include <stdio.h>

 

int main(){
    int MATRIZSIZE=0;
    scanf("%d",&MATRIZSIZE);
    int matriz[MATRIZSIZE-1][MATRIZSIZE-1];

    for(int i=0;i<MATRIZSIZE;i++){
        for(int j=0;j<MATRIZSIZE;j++){
            matriz[i][j]=3;

            if(i==j){
            matriz[i][j]=1;
            }else if(i+j==MATRIZSIZE-1){
            matriz[i][j]=2;
            } 
            
        }   
    }

    for(int i=0;i<MATRIZSIZE;i++){
        for(int j=0;j<MATRIZSIZE;j++){
        printf("%d",matriz[i][j]);
        }
    printf("\n");
    }
    return 0;
}