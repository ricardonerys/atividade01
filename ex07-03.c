#include <stdio.h>

int vetor[5]={8,5,4,2,9};
int qtd=5;

int main() {
    printf("[");
    for(int i=0;i<qtd;i++){
printf("%d,",vetor[i]);
    }
    printf("]\n");
     return 0;
}