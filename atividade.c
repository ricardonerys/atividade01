#include <stdio.h>
#define TAM_VET 10

void inserirVetor(int v[],int v2[], int qtd);
void Uniao(int v[], int v2[], int v3[], int qtd);
void insertionSort(int v[], int v2[], int qtd);
void intersecao(int v[], int v2[], int qtd);
void diferenca(int v[], int v2[], int qtd);


int main()
{
    int qtd;
    int v[TAM_VET], v2[TAM_VET],v3[2*TAM_VET];
    printf("digite o tamanho dos vetores:\n");
    scanf("%d", &qtd);
    inserirVetor(v,v2,qtd);
    insertionSort(v,v2,qtd);
    Uniao(v,v2,v3,qtd);
    intersecao(v,v2,qtd);
    diferenca(v,v2,qtd);
    

    return 0;
}


void inserirVetor(int v[],int v2[], int qtd){
    int c = 0;
    for(int i = 0; i < qtd; i++){
        printf("Insira o %d valor\n", (i+1));
        scanf("%d", &v[i]);
        c = 0;
        while(c<i){
            for(int e = 0; e < i; e++){
                if(v[e] == v[i]){
                    printf("Digite um número que não seja repetido:\n");
                    scanf("%d",&v[i]);
                    c += 0;
                }
                else{
                    c+=1;
                }
            }
        }
    }


    for(int i = 0; i < qtd; i++){
        printf("Insira o %d valor pro vetor2\n", (i+1));
        scanf("%d", &v2[i]);
        c = 0;
        while(c<i){
            for(int e = 0; e < i; e++){
                if(v2[e] == v2[i]){
                    printf("Digite um número que não seja repetido:\n");
                    scanf("%d",&v2[i]);
                    c += 0;
                }
                else{
                    c+=1;
                }
            }
        }
    }
}


void insertionSort(int v[], int v2[], int qtd){
    int j, chave;
    for(int i = 1; i<qtd; i++){
        chave = v[i];
        j = i - 1;
        
        while(j >= 0 && v[j] > chave){
            v[j+1] = v[j];
            j -=1;
        }
        v[j+1] = chave;
    }
    for(int i = 1; i<qtd; i++){
        chave = v2[i];
        j = i - 1;
        
        while(j >= 0 && v2[j] > chave){
            v2[j+1] = v2[j];
            j -=1;
        }
        v2[j+1] = chave;
    }
}


void Uniao(int v[], int v2[],int v3[], int qtd){
    for(int i = 0; i < (2*qtd);i++){
        
        v3[i] = v[i];
    }
    int p = 0;
    for(int i = qtd; i< 2* qtd; i++){
        v3[i] = v2[p];
        p+=1;
    }
        
        
void insertionSort(int v3[], int qtd){
         int j, chave;
        for(int i = 1; i<qtd; i++){
            chave = v3[i];
             j = i - 1;
            
            while(j >= 0 && v3[j] > chave){
                v3[j+1] = v3[j];
                j -=1;
        }
        v3[j+1] = chave;
    }
    }
    printf("[");
    for(int i =0; i< 2*qtd;i++){
        if(i>0){
           
            printf(",%d", v3[i]);
    }else{
        printf("%d", v3[i]);
    }
}
    printf("]\n");
}

void intersecao(int v[], int v2[], int qtd){
    printf("[");
    for(int i = 0; i< qtd; i++){
        
        for(int e = 0; e < qtd; e++){
            if(v[i] == v2[e]){
                printf("%d,", v[i]);
            } else{
                continue;
            }
        }
    }
    printf("]\n");
}
void diferenca(int v[], int v2[], int qtd) {
    printf("Diferença do primeiro vetor com o segundo vetor:\n[");
    int encontrou;
    for (int i = 0; i < qtd; i++) {
        encontrou = 0;
        for (int j = 0; j < qtd; j++) {
            if (v[i] == v2[j]) {
                encontrou = 1;
                break;
            }
        }
        if (!encontrou) {
            printf("%d ", v[i]);
        }
    }
    printf("]\n");

    printf("Diferença do segundo vetor com o primeiro vetor:\n[");
    for (int i = 0; i < qtd; i++) {
        encontrou = 0;
        for (int j = 0; j < qtd; j++) {
            if (v2[i] == v[j]) {
                encontrou = 1;
                break;
            }
        }
        if (!encontrou) {
            printf("%d ", v2[i]);
        }
    }
    printf("]\n");
}