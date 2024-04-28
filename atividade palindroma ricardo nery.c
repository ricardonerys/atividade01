#include <stdio.h>

#define TAMVET 50
char string[TAMVET];
char string2[TAMVET];
int qtd;


void removeresp(char *vetor,int tam);
void reverter(char *vetor,int tam);

int main(){
    printf("digite a frase:");
    gets(string);
    qtd=strlen(string);
    removeresp(string,qtd);
    qtd=strlen(string);

    for(int i=0;i<qtd;i++){
        string2[i]=string[i];
    }
    reverter(string,qtd);
    if(strcmp(string,string2)==0){
         printf("%s eh palindroma\n",string2);
    }else{
        printf("%s nao eh palindroma\n",string2);
    }
   
    return 0;
}

void removeresp(char *vetor,int tam){

    for(int i=0;i<tam;i++){
        if(vetor[i]==' '){
            for(int k=i;k<tam;k++){
                vetor[k]=vetor[k+1];
            }
        }
    }
}


void reverter(char *vetor,int tam){
    for(int i=0;i<tam/2;i++){
        char catual=vetor[i];
        vetor[i]=vetor[tam-1-i];
        vetor[tam-1-i]=catual;
        
    }
}
