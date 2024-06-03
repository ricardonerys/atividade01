#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAMSTR 40

struct produto {
    char nomedoproduto[TAMSTR];
    int qtdestoque;
    double precounit;
    int qtdmin;
    int qtdpad;
};

void menu();
void inserirProduto(struct produto vetorproduto[], int qtd);
void removerProduto(struct produto vetorproduto[], int qtd);
void listarProduto(struct produto vetorproduto[], int qtd);
void ordenarProduto(struct produto vetorproduto[], int qtd);
void atualizarProduto(struct produto vetorproduto[], int qtd);

int main() {
    struct produto vetorproduto[100];
    int opcao;
    while(1) {
        menu();
        scanf("%d", &opcao);
        while(opcao < 1 || opcao > 5) {
            printf("Digite uma opção válida:\n");
            scanf("%d", &opcao);
        }

        if(opcao == 1) {
            inserirProduto(vetorproduto, 100);
        }
        if(opcao == 2) {
            removerProduto(vetorproduto, 100);
        }
        if(opcao == 3) {
            listarProduto(vetorproduto, 100);
        }
        if(opcao == 4) {
            ordenarProduto(vetorproduto, 100);
        }
        if(opcao == 5) {
            atualizarProduto(vetorproduto, 100);
        }
    }

    return 0;
}

void menu() {
    printf("Digite o número correspondente à opção desejada:\n1. Inserir produto\n2. Remover produto\n3. Listar produtos\n4. Ordenar produtos\n5. Atualizar produto\n");
}

void inserirProduto(struct produto vetorproduto[], int qtd) {
    int i = 0;
    while (i < qtd && vetorproduto[i].nomedoproduto[0] != '\0'){
        i++;
    }
    if (i >= qtd) {
        printf("Não há espaço disponível!\n");
        return;
    }

    printf("Espaço disponível!\n");
    printf("Digite o nome do produto:\n");
    getchar(); // Consome o caractere de nova linha deixado no buffer de entrada
    fgets(vetorproduto[i].nomedoproduto, TAMSTR, stdin);
    vetorproduto[i].nomedoproduto[strcspn(vetorproduto[i].nomedoproduto, "\n")] = '\0'; // Remove a quebra de linha
    printf("Digite a quantidade em estoque:\n");
    scanf("%d", &vetorproduto[i].qtdestoque);
    printf("Digite o preço da unidade:\n");
    scanf("%lf", &vetorproduto[i].precounit);
    printf("Digite a quantidade mínima para pedido:\n");
    scanf("%d", &vetorproduto[i].qtdmin);
    printf("Digite a quantidade padrão de pedido:\n");
    scanf("%d", &vetorproduto[i].qtdpad);
}

void removerProduto(struct produto vetorproduto[], int qtd) {
    char nomepararemover[TAMSTR];
    int produtoremovido = -1;
    printf("Digite o nome do produto a ser removido:\n");
    getchar(); // Consome o caractere de nova linha deixado no buffer de entrada
    fgets(nomepararemover, TAMSTR, stdin);
    nomepararemover[strcspn(nomepararemover, "\n")] = '\0'; // Remove a quebra de linha
    for (int i = 0; i < qtd; i++) {
        if (strcmp(vetorproduto[i].nomedoproduto, nomepararemover) == 0) {
            vetorproduto[i].nomedoproduto[0] = '\0';
            vetorproduto[i].qtdestoque = 0;
            vetorproduto[i].precounit = 0.0;
            vetorproduto[i].qtdmin = 0;
            vetorproduto[i].qtdpad = 0;
            printf("Produto removido!\n");
            produtoremovido = 1;
            break;
        }
    }
    if (produtoremovido == -1) {
        printf("Nenhum item com este nome foi encontrado!\n");
    }
}

void listarProduto(struct produto vetorproduto[], int qtd) {
    for (int i = 0; i < qtd; i++) {
        if (vetorproduto[i].nomedoproduto[0] != '\0') {
            printf("Produto %d:\n"
                   "Nome do produto: %s\n"
                   "Quantidade em estoque: %d\n"
                   "Preço unitário: %lf\n"
                   "Qtd mínima: %d\n"
                   "Qtd padrão: %d\n",
                   i, vetorproduto[i].nomedoproduto, vetorproduto[i].qtdestoque,
                   vetorproduto[i].precounit, vetorproduto[i].qtdmin, vetorproduto[i].qtdpad);
        }
        if (vetorproduto[i].qtdestoque < vetorproduto[i].qtdmin) {
            printf("A quantidade de produtos que devem ser comprados: %d\n", vetorproduto[i].qtdpad);
        }
    }
}

void atualizarProduto(struct produto vetorproduto[], int qtd) {
    char nomeparaatualizar[TAMSTR];
    int produtoatualizado = -1;
    printf("Digite o nome do produto a ser atualizado:\n");
    getchar(); // Consome o caractere de nova linha deixado no buffer de entrada
    fgets(nomeparaatualizar, TAMSTR, stdin);
    nomeparaatualizar[strcspn(nomeparaatualizar, "\n")] = '\0'; // Remove a quebra de linha
    for (int i = 0; i < qtd; i++) {
        if (strcmp(vetorproduto[i].nomedoproduto, nomeparaatualizar) == 0) {
            printf("Digite o novo nome do produto:\n");
            fgets(vetorproduto[i].nomedoproduto, TAMSTR, stdin);
            vetorproduto[i].nomedoproduto[strcspn(vetorproduto[i].nomedoproduto, "\n")] = '\0'; // Remove a quebra de linha
            printf("Digite a quantidade em estoque:\n");
            scanf("%d", &vetorproduto[i].qtdestoque);
            printf("Digite o preço da unidade:\n");
            scanf("%lf", &vetorproduto[i].precounit);
            printf("Digite a quantidade mínima para pedido:\n");
            scanf("%d", &vetorproduto[i].qtdmin);
            printf("Digite a quantidade padrão de pedido:\n");
            scanf("%d", &vetorproduto[i].qtdpad);
            
            printf("Produto atualizado!\n");
            produtoatualizado = 1;
        }
    }
}