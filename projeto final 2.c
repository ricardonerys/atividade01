#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM_MAX_PLYLST 150
#define TAM_NOME 50
#define TAM_LOGIN 15
#define TAM_SENHA 15
#define TAM_PLAYLIST 100
#define TAM_TITULO 50
#define TAM_MUSICAS 100

struct Musica {
    int codigo;
    char titulo[TAM_TITULO];
    char artista[TAM_NOME];
};

struct Playlist {
    int codigo;
    int codUsuario;
    char titulo[TAM_TITULO];
    int qtdMusicas;
    int musicas[TAM_MUSICAS];
};

struct Usuario {
    int codigo;
    char nome[TAM_NOME];
    char login[TAM_LOGIN];
    char senha[TAM_SENHA];
    int qtdPlaylists;
    struct Playlist playlists[TAM_PLAYLIST];
    int qtdPlaylistsFav;
    int playlistsFav[TAM_PLAYLIST];
};

//--------------------------------------------------------------------------prototipos:

void menuUsuario(struct Usuario usuarios[], struct Musica musicas[], int *contadorUsuarios, int *contadorMusicas);
void menuAdministrador(struct Usuario usuarios[], struct Musica musicas[], struct Playlist playlists[], int *contadorUsuarios, int *contadorMusicas, int *contadorPlaylists);
int loginUsuario(struct Usuario usuarios[], int contadorUsuarios);
void listarUsuarios(struct Usuario usuarios[], int contadorUsuarios); 
void cadastrarUsuario(struct Usuario usuarios[], int *contadorUsuarios);
void alterarNomeUsuario(struct Usuario usuarios[], int contadorUsuarios, int codigo);
void alterarLoginUsuario(struct Usuario usuarios[], int contadorUsuarios, int codigo);
void alterarSenhaUsuarioUsuario(struct Usuario usuarios[], int contadorUsuarios, int codigo);
void listarMusicas(struct Musica musicas[], int contadorMusicas);
void listarDadosUsuario(struct Usuario usuarios[], int contadorUsuarios, int codigo);
void excluirMusica(struct Musica musicas[], int *contadorMusicas);
void cadastrarMusica(struct Musica musicas[], int *contadorMusicas);
void alterarMusica(struct Musica musicas[], int contadorMusicas);
void consultarMusica(struct Musica musicas[], int contadorMusicas);
void alterarSenhaUsuario(struct Usuario usuarios[], int contadorUsuarios); 
void consultarUsuario(struct Usuario usuarios[], int contadorUsuarios);
void listarUsuariosusuario(struct Usuario usuarios[], int contadorUsuarios);
void consultarUsuariousuario(struct Usuario usuarios[], int contadorUsuarios);
void listarPlaylists(struct Playlist playlists[], int contadorPlaylists);
void consultarPlaylist(struct Playlist playlists[], int contadorPlaylists);

int validarSenhaAdmin(char *senha);
int gerarCodigo(int *contador);
void lerString(char *destino, int tamanho);
void limparBufferEntrada();
void gerarDadosAutomaticamente(struct Usuario usuarios[], int *contadorUsuarios, struct Musica musicas[], int *contadorMusicas, struct Playlist playlists[], int *contadorPlaylists);
void gerarPlaylists(struct Playlist playlists[], int *contadorPlaylists, struct Usuario usuarios[], int contadorUsuarios, struct Musica musicas[], int contadorMusicas, int qtd);
void gerarMusicas(struct Musica musicas[], int *contadorMusicas, int qtd);
void gerarUsuarios(struct Usuario usuarios[], int *contadorUsuarios, int qtd);

//--------------------------------------------------------------------------funçoes:
int main() {
    int contadorUsuarios = 0;
    int contadorMusicas = 0;
    int contadorPlaylists = 0;
    struct Usuario usuarios[TAM_MAX_PLYLST];
    struct Musica musicas[TAM_MAX_PLYLST];
    struct Playlist playlists[TAM_MAX_PLYLST];

    int opcao;
    do {
        printf("\nMenu Principal\n");
        printf("1. Administrador\n");
        printf("2. Usuário\n");
        printf("9. gerar dados\n");
        printf("0. encerrar programa\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        switch (opcao) {
            case 1: menuAdministrador(usuarios, musicas, playlists, &contadorUsuarios, &contadorMusicas, &contadorPlaylists); break;
            case 2: menuUsuario(usuarios, musicas, &contadorUsuarios, &contadorMusicas); break;
            case 9: gerarDadosAutomaticamente(usuarios, &contadorUsuarios, musicas, &contadorMusicas, playlists, &contadorPlaylists);break;
            case 0: break;
            default: printf("Opção inválida\n");
        }
    } while (opcao != 0);
    return 0;
}

// Menu do Usuário
void menuUsuario(struct Usuario usuarios[], struct Musica musicas[], int *contadorUsuarios, int *contadorMusicas) {
    printf("executando menu usuario\n");
    int codigoUsuario = -1, opcao;
    while (codigoUsuario == -1) {
        printf("1. Login\n");
        printf("2. Cadastro\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        if (opcao == 1) {
            codigoUsuario = loginUsuario(usuarios, *contadorUsuarios);
        } else if (opcao == 2) {
            cadastrarUsuario(usuarios, contadorUsuarios);
        } else {
            printf("Opção inválida.\n");
        }
    }

    do {
        printf("\nMenu Usuário\n");
        printf("1. Listar dados\n");
        printf("2. Alterar nome\n");
        printf("3. Alterar login\n");
        printf("4. Alterar senha\n");
        printf("5.listar usuarios\n");
        printf("6.consultar usuarios\n");
        printf("7.listar musicas\n");
        printf("8.consultar musicas\n");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        switch (opcao) {
            case 1: listarDadosUsuario(usuarios, *contadorUsuarios, codigoUsuario); break;
            case 2: alterarNomeUsuario(usuarios, *contadorUsuarios, codigoUsuario); break;
            case 3: alterarLoginUsuario(usuarios, *contadorUsuarios, codigoUsuario); break;
            case 4: alterarSenhaUsuarioUsuario(usuarios, *contadorUsuarios, codigoUsuario); break; // Linha 373
            case 5: listarUsuariosusuario(usuarios, *contadorUsuarios); break;
            case 6: consultarUsuariousuario(usuarios, *contadorUsuarios); break;
            case 7: listarMusicas(musicas, *contadorMusicas); break;
            case 8: consultarMusica(musicas, *contadorMusicas); break;
            case 0: break;
            default: printf("Opção inválida\n");
        }
    } while (opcao != 0);
}

void menuAdministrador(struct Usuario usuarios[], struct Musica musicas[], struct Playlist playlists[], int *contadorUsuarios, int *contadorMusicas, int *contadorPlaylists) {
    printf("executando menu adm\n");
    char senha[TAM_SENHA];
    printf("Digite a senha de administrador: ");
    limparBufferEntrada();
    lerString(senha, sizeof(senha));
    
    if (validarSenhaAdmin(senha)) {
        int opcao;
        do {
            printf("\nMenu Administrador\n");
            printf("1. Listar usuários\n");
            printf("2. Consultar usuário\n");
            printf("3. Alterar senha de um usuário\n");
            printf("4. Cadastrar música\n");
            printf("5. Listar músicas\n");
            printf("6. Consultar música\n");
            printf("7. Alterar música\n");
            printf("8. Excluir música\n");
            printf("9. Listar playlists\n");
            printf("10. Consultar playlist\n");
            printf("0. Sair\n");
            printf("Escolha uma opção: ");
            scanf("%d", &opcao);
            switch (opcao) {
                case 1: listarUsuarios(usuarios, *contadorUsuarios); break;
                case 2: consultarUsuario(usuarios, *contadorUsuarios); break;
                case 3: alterarSenhaUsuario(usuarios, *contadorUsuarios); break;
                case 4: cadastrarMusica(musicas, contadorMusicas);break;
                case 5: listarMusicas(musicas, *contadorMusicas); break;
                case 6: consultarMusica(musicas, *contadorMusicas); break;
                case 7: alterarMusica(musicas, *contadorMusicas); break;
                case 8: excluirMusica(musicas, contadorMusicas); break;
                case 9: listarPlaylists(playlists, *contadorPlaylists); break;
                case 10: consultarPlaylist(playlists, *contadorPlaylists); break;
                case 0: break;
                default: printf("Opção inválida\n");
            }
        } while (opcao != 0);
    } else {
        printf("Senha de administrador incorreta.\n");
    }
}

int loginUsuario(struct Usuario usuarios[], int contadorUsuarios) {
    char login[TAM_LOGIN], senha[TAM_SENHA];
    printf("Digite o login: ");
    limparBufferEntrada();
    lerString(login, sizeof(login));
    printf("Digite a senha: ");
    lerString(senha, sizeof(senha));
    for (int i = 0; i < contadorUsuarios; i++) {
        if (strcmp(usuarios[i].login, login) == 0 && strcmp(usuarios[i].senha, senha) == 0) {
            printf("Login bem-sucedido.\n");
            return usuarios[i].codigo;
        }
    }
    printf("Login ou senha incorretos.\n");
    return -1;
}

void cadastrarUsuario(struct Usuario usuarios[], int *contadorUsuarios) {
    if (*contadorUsuarios >= TAM_MAX_PLYLST) {
        printf("Limite de usuários alcançado.\n");
        return;
    }
    struct Usuario novoUsuario;
    novoUsuario.codigo = gerarCodigo(contadorUsuarios);
    printf("Digite o nome: ");
    limparBufferEntrada();
    lerString(novoUsuario.nome, sizeof(novoUsuario.nome));
    printf("Digite o login: ");
    lerString(novoUsuario.login, sizeof(novoUsuario.login));
    printf("Digite a senha: ");
    lerString(novoUsuario.senha, sizeof(novoUsuario.senha));
    novoUsuario.qtdPlaylists = 0;
    novoUsuario.qtdPlaylistsFav = 0;
    usuarios[*contadorUsuarios-1] = novoUsuario;
    (*contadorUsuarios);
    printf("Usuário cadastrado com sucesso.\n");
}

void alterarNomeUsuario(struct Usuario usuarios[], int contadorUsuarios, int codigo) {
    char nome[TAM_NOME], senha[TAM_SENHA];
    for (int i = 0; i < contadorUsuarios; i++) {
        if (usuarios[i].codigo == codigo) {
            printf("Digite a senha: ");
            limparBufferEntrada();
            lerString(senha, sizeof(senha));
            if (strcmp(senha, usuarios[i].senha) == 0) {
                printf("Digite o novo nome: ");
                lerString(nome, sizeof(nome));
                strcpy(usuarios[i].nome, nome);
                printf("Nome alterado com sucesso.\n");
            } else {
                printf("Senha incorreta.\n");
            }
            return;
        }
    }
}

void alterarLoginUsuario(struct Usuario usuarios[], int contadorUsuarios, int codigo) {
    char login[TAM_LOGIN], senha[TAM_SENHA];
    for (int i = 0; i < contadorUsuarios; i++) {
        if (usuarios[i].codigo == codigo) {
            printf("Digite a senha: ");
            limparBufferEntrada();
            lerString(senha, sizeof(senha));
            if (strcmp(senha, usuarios[i].senha) == 0) {
                printf("Digite o novo login: ");
                lerString(login, sizeof(login));
                strcpy(usuarios[i].login, login);
                printf("Login alterado com sucesso.\n");
            } else {
                printf("Senha incorreta.\n");
            }
            return;
        }
    }
}

void alterarSenhaUsuarioUsuario(struct Usuario usuarios[], int contadorUsuarios, int codigo) {
    char senhaAtual[TAM_SENHA], novaSenha[TAM_SENHA], confirmaSenha[TAM_SENHA];
    for (int i = 0; i < contadorUsuarios; i++) {
        if (usuarios[i].codigo == codigo) {
            printf("Digite a senha atual: ");
            limparBufferEntrada();
            lerString(senhaAtual, sizeof(senhaAtual));
            if (strcmp(senhaAtual, usuarios[i].senha) == 0) {
                printf("Digite a nova senha: ");
                lerString(novaSenha, sizeof(novaSenha));
                printf("Confirme a nova senha: ");
                lerString(confirmaSenha, sizeof(confirmaSenha));
                if (strcmp(novaSenha, confirmaSenha) == 0) {
                    strcpy(usuarios[i].senha, novaSenha);
                    printf("Senha alterada com sucesso.\n");
                } else {
                    printf("As senhas não coincidem.\n");
                }
            } else {
                printf("Senha atual incorreta.\n");
            }
            return;
        }
    }
}

void listarDadosUsuario(struct Usuario usuarios[], int contadorUsuarios, int codigo) {
    for (int i = 0; i < contadorUsuarios; i++) {
        if (usuarios[i].codigo == codigo) {
            printf("Código: %d, Nome: %s, Login: %s\n", usuarios[i].codigo, usuarios[i].nome, usuarios[i].login);
            return;
        }
    }
}



void listarMusicas(struct Musica musicas[], int contadorMusicas) {
    for (int i = 0; i < contadorMusicas; i++) {
        printf("Código: %d, Título: %s, Artista: %s\n", musicas[i].codigo, musicas[i].titulo, musicas[i].artista);
    }
}

void cadastrarMusica(struct Musica musicas[], int *contadorMusicas) {
    struct Musica novaMusica;
    novaMusica.codigo = gerarCodigo(contadorMusicas);
    printf("Digite o título da música: ");
    limparBufferEntrada();
    lerString(novaMusica.titulo, sizeof(novaMusica.titulo));
    printf("Digite o nome do artista: ");
    lerString(novaMusica.artista, sizeof(novaMusica.artista));
    if (*contadorMusicas < TAM_MAX_PLYLST) {
        musicas[*contadorMusicas - 1] = novaMusica;
        printf("Música cadastrada com sucesso.\n");
    } else {
        printf("Limite de músicas alcançado.\n");
    }
}


void consultarMusica(struct Musica musicas[], int contadorMusicas) {
    char termo[TAM_TITULO];
    printf("Digite o código, parte do título da música ou nome do artista: ");
    limparBufferEntrada();
    lerString(termo, sizeof(termo));
    for (int i = 0; i < contadorMusicas; i++) {
        if (strstr(musicas[i].titulo, termo) || strstr(musicas[i].artista, termo) || atoi(termo) == musicas[i].codigo) {
            printf("Código: %d, Título: %s, Artista: %s\n", musicas[i].codigo, musicas[i].titulo, musicas[i].artista);
        }
    }
}

void alterarMusica(struct Musica musicas[], int contadorMusicas) {
    int codigo;
    char novoTitulo[TAM_TITULO];
    char novoArtista[TAM_NOME];
    printf("Digite o código da música(apenas valores inteiros): ");
    scanf("%d", &codigo);
    for (int i = 0; i < contadorMusicas; i++) {
        if (musicas[i].codigo == codigo) {
            printf("Digite o novo título da música: ");
            limparBufferEntrada();
            lerString(novoTitulo, sizeof(novoTitulo));
            printf("Digite o novo nome do artista: ");
            lerString(novoArtista, sizeof(novoArtista));
            strcpy(musicas[i].titulo, novoTitulo);
            strcpy(musicas[i].artista, novoArtista);
            printf("Música alterada com sucesso.\n");
            return;
        }
    }
    printf("Música não encontrada.\n");
}

void excluirMusica(struct Musica musicas[], int *contadorMusicas) {
    int codigo;
    printf("Digite o código da música: ");
    scanf("%d", &codigo);
    for (int i = 0; i < *contadorMusicas; i++) {
        if (musicas[i].codigo == codigo) {
            for (int j = i; j < *contadorMusicas - 1; j++) {
                musicas[j] = musicas[j + 1];
            }
            (*contadorMusicas)--;
            printf("Música excluída com sucesso.\n");
            return;
        }
    }
    printf("Música não encontrada.\n");
}

void listarUsuarios(struct Usuario usuarios[], int contadorUsuarios) {
    for (int i = 0; i < contadorUsuarios; i++) {
        printf("Código: %d, Nome: %s, Login: %s\n", usuarios[i].codigo, usuarios[i].nome, usuarios[i].login);
    }
}

void listarUsuariosusuario(struct Usuario usuarios[], int contadorUsuarios){
    for (int i = 0; i < contadorUsuarios; i++) {
        printf("Nome: %s\n", usuarios[i].nome);
    }
}

void consultarUsuario(struct Usuario usuarios[], int contadorUsuarios) {
    char termo[TAM_NOME];
    printf("Digite o login ou parte do nome: ");
    limparBufferEntrada();
    lerString(termo, sizeof(termo));
    for (int i = 0; i < contadorUsuarios; i++) {
        if (strstr(usuarios[i].login, termo) || strstr(usuarios[i].nome, termo)) {
            printf("Código: %d, Nome: %s, Login: %s\n", usuarios[i].codigo, usuarios[i].nome, usuarios[i].login);
        }
    }
}

void consultarUsuariousuario(struct Usuario usuarios[], int contadorUsuarios) {
    char termo[TAM_NOME];
    printf("Digite o login ou parte do nome: ");
    limparBufferEntrada();
    lerString(termo, sizeof(termo));
    for (int i = 0; i < contadorUsuarios; i++) {
        if (strstr(usuarios[i].login, termo) || strstr(usuarios[i].nome, termo)) {
            printf("Nome: %s\n",usuarios[i].nome);
        }
    }
}


void alterarSenhaUsuario(struct Usuario usuarios[], int contadorUsuarios) {
    int codigo;
    char novaSenha[TAM_SENHA];
    printf("Digite o código do usuário: ");
    scanf("%d", &codigo);
    for (int i = 0; i < contadorUsuarios; i++) {
        if (usuarios[i].codigo == codigo) {
            printf("Digite a nova senha: ");
            limparBufferEntrada();
            lerString(novaSenha, sizeof(novaSenha));
            strcpy(usuarios[i].senha, novaSenha);
            printf("Senha alterada com sucesso.\n");
            return;
        }
    }
    printf("Usuário não encontrado.\n");
}






// Funções utilitárias
void limparBufferEntrada() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void lerString(char *destino, int tamanho) {
    fgets(destino, tamanho, stdin);
    // Remover o caractere de nova linha, se presente
    destino[strcspn(destino, "\n")] = '\0';
}

int gerarCodigo(int *contador) {
    return ++(*contador);
}

int validarSenhaAdmin(char *senha) {
    return strcmp(senha, "m@st3r2024") == 0;
}
void gerarUsuarios(struct Usuario usuarios[], int *contadorUsuarios, int qtd) {
    for (int i = 0; i < qtd; i++) {
        struct Usuario novoUsuario;
        novoUsuario.codigo = *contadorUsuarios + 1;
        sprintf(novoUsuario.nome, "Usuario%d", novoUsuario.codigo);
        sprintf(novoUsuario.login, "login%d", novoUsuario.codigo);
        novoUsuario.qtdPlaylists = 0;
        novoUsuario.qtdPlaylistsFav = 0;

        usuarios[*contadorUsuarios] = novoUsuario;
        (*contadorUsuarios)++;
    }
    printf("%d usuários gerados com sucesso.\n", qtd);
}


void gerarMusicas(struct Musica musicas[], int *contadorMusicas, int qtd) {
    for (int i = 0; i < qtd; i++) {
        struct Musica novaMusica;
        novaMusica.codigo = *contadorMusicas + 1;
        sprintf(novaMusica.titulo, "Musica%d", novaMusica.codigo);
        sprintf(novaMusica.artista, "Artista%d", novaMusica.codigo);

        musicas[*contadorMusicas] = novaMusica;
        (*contadorMusicas)++;
    }
    printf("%d músicas geradas com sucesso.\n", qtd);
}
void gerarPlaylists(struct Playlist playlists[], int *contadorPlaylists, struct Usuario usuarios[], int contadorUsuarios, struct Musica musicas[], int contadorMusicas, int qtd) {
    for (int i = 0; i < qtd; i++) {
        struct Playlist novaPlaylist;
        novaPlaylist.codigo = *contadorPlaylists + 1;
        sprintf(novaPlaylist.titulo, "Playlist%d", novaPlaylist.codigo);
        novaPlaylist.codUsuario = usuarios[rand() % contadorUsuarios].codigo;
        novaPlaylist.qtdMusicas = rand() % TAM_MUSICAS;

        for (int j = 0; j < novaPlaylist.qtdMusicas; j++) {
            novaPlaylist.musicas[j] = musicas[rand() % contadorMusicas].codigo;
        }

        playlists[*contadorPlaylists] = novaPlaylist;
        (*contadorPlaylists)++;
    }
    printf("%d playlists geradas com sucesso.\n", qtd);
}
void gerarDadosAutomaticamente(struct Usuario usuarios[], int *contadorUsuarios, struct Musica musicas[], int *contadorMusicas, struct Playlist playlists[], int *contadorPlaylists) {
    gerarUsuarios(usuarios, contadorUsuarios, 5); 
    gerarMusicas(musicas, contadorMusicas, 20); 
    gerarPlaylists(playlists, contadorPlaylists, usuarios, *contadorUsuarios, musicas, *contadorMusicas, 10); 
}

void listarPlaylists(struct Playlist playlists[], int contadorPlaylists) {
    for (int i = 0; i < contadorPlaylists; i++) {
        printf("Código: %d, Título: %s, Criador: %d\n", playlists[i].codigo, playlists[i].titulo, playlists[i].codUsuario);
        for (int j = 0; j < playlists[i].qtdMusicas; j++) {
            printf("\tMúsica %d: %d\n", j + 1, playlists[i].musicas[j]);
        }
    }
}

void consultarPlaylist(struct Playlist playlists[], int contadorPlaylists) {
    char termo[TAM_TITULO];
    printf("Digite o código da playlist, parte do título da playlist ou código da música: ");
    scanf("%s", termo);
    for (int i = 0; i < contadorPlaylists; i++) {
        if (strstr(playlists[i].titulo, termo) || atoi(termo) == playlists[i].codigo) {
            printf("Código: %d, Título: %s, Criador: %d\n", playlists[i].codigo, playlists[i].titulo, playlists[i].codUsuario);
            for (int j = 0; j < playlists[i].qtdMusicas; j++) {
                printf("\tMúsica %d: %d\n", j + 1, playlists[i].musicas[j]);
            }
        }
    }
}