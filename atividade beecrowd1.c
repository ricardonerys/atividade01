#include <stdio.h>

#define MATRIZSIZE 12

int main(){
    int linha_selecionada=0;
    char Ch;
    double soma=0;
    double matriz[MATRIZSIZE][MATRIZSIZE];
    scanf("%d",&linha_selecionada);
    scanf(" %c",&Ch);

    for(int i=0;i<MATRIZSIZE;i++){
for(int j=0;j<MATRIZSIZE;j++){
    scanf("%lf",&matriz[i][j]);
}}
    
    for(int i=0;i<MATRIZSIZE;i++){
    soma = soma + matriz[linha_selecionada][i];    
    }
    if(Ch=='S'){
        printf("SOMA %.1f",soma);
    }
    if(Ch=='M'){
        printf("%.1f",soma/MATRIZSIZE);
    }


    return 0;
}