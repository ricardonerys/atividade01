#include <stdio.h>
#define TAMVET 40
char vetornome[TAMVET];

int contaletras(char vetorstr[]);

// com strings, a funcão deve ser criada assim: int contaletras(char *vetorstr);

int main(){
    int ctd=0;
    printf("digite seu nome:");
    gets(vetornome);
    printf("seu nome eh:%s\n",vetornome);
    

    ctd = contaletras(vetornome);
    printf("%d\n",ctd);
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