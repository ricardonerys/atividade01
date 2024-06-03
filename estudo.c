#include <stdio.h>
#include <stdlib.h>

void menu();

int main(){
    int opcao=0;
    menu();
    scanf("%d",&opcao)
    return 0;
}

void menu(){
printf("digite a opcao desejada:\n"
        "1.remover produto\n"
        "1.listar produto\n"
        "1.ordenar produto\n"
        "1.atualizar produto\n");

}