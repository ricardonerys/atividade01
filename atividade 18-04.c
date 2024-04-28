#include <stdio.h>

int tamanhovetor = 80;

void codificar(char vetor[]);

int main(){
    char frase[tamanhovetor];
    gets(frase);

    for(int i=0;i<tamanhovetor;i++){
        if(frase[i] =='a'||frase[i] =='e'||frase[i] =='i'||frase[i] =='o'||frase[i] =='u'||frase[i] =='A'||frase[i] =='E'||frase[i] =='I'||frase[i] =='O'||frase[i] =='U'){
        frase[i] = '*';    
        }
    }



    printf("a frase eh %s",frase);

    return 0;
}
