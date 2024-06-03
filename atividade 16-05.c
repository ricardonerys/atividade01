#include <stdio.h>

void escrevenome(dadosdoaluno dados[]);
void escrevenotas(dadosdoaluno dados[]);
float calcularmedia(dadosdoaluno dados[]);

typedef struct{
    char nomealuno[10];
    float nota1;
    float nota2;
    float media;
} dadosdoaluno;

int main(){
    dadosdoaluno dados[10];

    escrevernome(dados);
    escrevenotas(dados);


    return 0;
}

void escrevernome(dadosdoaluno dados[]){
    for(int i=0;i<10;i++){
        printf("digite o nome do aluno %d",i+1);
        gets(dados[i].nomealuno);
    }
}

void escrevenotas(dadosdoaluno dados[]){
    for(int i=0;i<10;i++){
        printf("digite a nota %d",i+1);
        gets(dados[i].nomealuno);
    }
}