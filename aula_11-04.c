#include <stdio.h>
#define TAMVET 40
char string1[TAMVET];
char string2[TAMVET];

int contaletras(char vetorstr[]);
void insertionSort(char v[], int qtd);
// com strings, a funcão deve ser criada assim: int contaletras(char *vetorstr);

int main(){
    int quant1=0;
    int quant2=0;
    printf("digite a string 1:");
    gets(string1);
    printf("digite a string 2:");
    gets(string2);
    quant1 = contaletras(string1);
    quant2 = contaletras(string2);
    printf("%s \n",string1);
    insertionSort( string1,quant1);
    
    printf("%s \n",string1);

    
    printf("%d letras\n",quant1);
    return 0;

}
  
int contaletras(char vetorstr[]){
    int i=0; 
    int ctd=0;
    while(vetorstr[i] != '\0'){
        if(vetorstr[i]!=' '){
            ctd++;
        }
        i=i+1;
    
    }
    return ctd;
}

void insertionSort(char v[], int qtd) {
  int atual, j;
  for (int i = 1; i < qtd; ++i) {
    atual = v[i];
    j = i - 1;
    while (j >= 0 && atual < v[j]) {
      v[j + 1] = v[j];
      j = j - 1;
    }
    v[j + 1] = atual;
  }
}