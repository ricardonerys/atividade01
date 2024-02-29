#include <stdio.h>
#include <math.h>

int main(){

    int qtd;
    int notas[10];
    double media=0.0;
    double des=0.0;
    int somat=0;

    printf("insira a quantidade de notas:");
    scanf("%d",&qtd);

    while(qtd<0 || qtd>10){
        printf("valor invalido, insira novo valor:");
        scanf("%d",&qtd); 
    }

    for(int i=0;i<qtd;i++){
        printf("insira o valor da %d° nota:",i+1);
        scanf("%d",&notas[i]);
        somat+=notas[i];
         
    }

    media= somat/qtd;

    for(int i=0;i<qtd;i++){
        des= des+((notas[i]-media)*(notas[i]-media));
        printf("%lf\n",des);
    } 
    des=des/qtd;
    des=sqrt(des);

    printf("o somatorio eh %d\n",somat);
    printf("a media eh %lf\n",media);
    printf("o desvio padrao eh %lf\n",des);
    return 0;
}