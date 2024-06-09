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

// Protótipos das funções
int gerarCodigo(int *contador);
int validarSenhaAdmin(char *senha);
void listarUsuarios(struct Usuario usuarios[], int contadorUsuarios);
void consultarUsuario(struct Usuario usuarios[], int contadorUsuarios);
void alterarSenhaUsuario(struct Usuario usuarios[], int contadorUsuarios);

void cadastrarMusica(struct Musica musicas[], int *contadorMusicas);
void listarMusicas(struct Musica musicas[], int contadorMusicas);
void consultarMusica(struct Musica musicas[], int contadorMusicas);
void alterarMusica(struct Musica musicas[], int contadorMusicas);
void excluirMusica(struct Musica musicas[], int *contadorMusicas);

void listarPlaylists(struct Playlist playlists[], int contadorPlaylists);
void consultarPlaylist(struct Playlist playlists[], int contadorPlaylists);

void menuAdministrador(struct Usuario usuarios[], struct Musica musicas[], struct Playlist playlists[], int *contadorUsuarios, int *contadorMusicas, int *contadorPlaylists);

void listarDadosUsuario(struct Usuario usuarios[], int contadorUsuarios, int codigo);
void alterarNomeUsuario(struct Usuario usuarios[], int contadorUsuarios, int codigo);
void alterarLoginUsuario(struct Usuario usuarios[], int contadorUsuarios, int codigo);
void alterarSenhaUsuarioUsuario(struct Usuario usuarios[], int contadorUsuarios, int codigo);

void listarTodasMusicas(struct Musica musicas[], int contadorMusicas);

void cadastrarUsuario(struct Usuario usuarios[], int *contadorUsuarios);
int loginUsuario(struct Usuario usuarios[], int contadorUsuarios);
void menuUsuario(struct Usuario usuarios[], struct Musica musicas[], int *contadorUsuarios, int contadorMusicas);

// Função principal
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
        printf("0. encerrar programa\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        switch (opcao) {
            case 1: menuAdministrador(usuarios, musicas, playlists, &contadorUsuarios, &contadorMusicas, &contadorPlaylists); break;
            case 2: menuUsuario(usuarios, musicas, &contadorUsuarios, contadorMusicas); break;
            case 0: break;
            default: printf("Opção inválida\n");
        }
    } while (opcao != 0);
    return 0;
}

// Funções utilitárias
int gerarCodigo(int *contador) {
    return ++(*contador);
}

int validarSenhaAdmin(char *senha) {
    return strcmp(senha, "m@st3r2024") == 0;
}

// Funções do Administrador
void listarUsuarios(struct Usuario usuarios[], int contadorUsuarios) {
    for (int i = 0; i < contadorUsuarios; i++) {
        printf("Código: %d, Nome: %s, Login: %s\n", usuarios[i].codigo, usuarios[i].nome, usuarios[i].login);
    }
}

void consultarUsuario(struct Usuario usuarios[], int contadorUsuarios) {
    char termo[TAM_NOME];
    printf("Digite o login ou parte do nome: ");
    scanf("%s", termo);
    for (int i = 0; i < contadorUsuarios; i++) {
        if (strstr(usuarios[i].login, termo) || strstr(usuarios[i].nome, termo)) {
            printf("Código: %d, Nome: %s, Login: %s\n", usuarios[i].codigo, usuarios[i].nome, usuarios[i].login);
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
            scanf("%s", novaSenha);
            strcpy(usuarios[i].senha, novaSenha);
            printf("Senha alterada com sucesso.\n");
            return;
        }
    }
    printf("Usuário não encontrado.\n");
}

void cadastrarMusica(struct Musica musicas[], int *contadorMusicas) {
    struct Musica novaMusica;
    novaMusica.codigo = gerarCodigo(contadorMusicas);
    printf("Digite o título da música: ");
    scanf("%s", novaMusica.titulo);
    printf("Digite o nome do artista: ");
    scanf("%s", novaMusica.artista);
    if (*contadorMusicas < TAM_MAX_PLYLST) {
        musicas[*contadorMusicas - 1] = novaMusica;
        printf("Música cadastrada com sucesso.\n");
    } else {
        printf("Limite de músicas alcançado.\n");
    }
}

void listarMusicas(struct Musica musicas[], int contadorMusicas) {
    for (int i = 0; i < contadorMusicas; i++) {
        printf("Código: %d, Título: %s, Artista: %s\n", musicas[i].codigo, musicas[i].titulo, musicas[i].artista);
    }
}

void consultarMusica(struct Musica musicas[], int contadorMusicas) {
    char termo[TAM_TITULO];
    printf("Digite o código, parte do título da música ou nome do artista: ");
    scanf("%s", termo);
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
    printf("Digite o código da música: ");
    scanf("%d", &codigo);
    for (int i = 0; i < contadorMusicas; i++) {
        if (musicas[i].codigo == codigo) {
            printf("Digite o novo título da música: ");
            scanf("%s", novoTitulo);
            printf("Digite o novo nome do artista: ");
            scanf("%s", novoArtista);
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
        if (strstr(playlists[i].titulo, termo) || atoi(termo) == playlists[i].codigo || atoi(termo) == playlists[i].musicas[i]) {
            printf("Código: %d, Título: %s, Criador: %d\n", playlists[i].codigo, playlists[i].titulo, playlists[i].codUsuario);
            for (int j = 0; j < playlists[i].qtdMusicas; j++) {
                printf("\tMúsica %d: %d\n", j + 1, playlists[i].musicas[j]);
            }
        }
    }
}

void menuAdministrador(struct Usuario usuarios[], struct Musica musicas[], struct Playlist playlists[], int *contadorUsuarios, int *contadorMusicas, int *contadorPlaylists) {
    char senhaAdmin[TAM_SENHA];
    printf("Digite a senha de administrador: ");
    scanf("%s", senhaAdmin);
    if (validarSenhaAdmin(senhaAdmin)) {
        int opcao;
        do {
            printf("\nMenu Administrador\n");
            printf("1. Listar usuários\n");
            printf("2. Consultar usuário\n");
            printf("3. Alterar senha de usuário\n");
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
                case 4: cadastrarMusica(musicas, contadorMusicas); break;
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
        printf("Senha de administrador inválida.\n");
    }
}

// Funções do Usuário
void listarDadosUsuario(struct Usuario usuarios[], int contadorUsuarios, int codigo) {
    for (int i = 0; i < contadorUsuarios; i++) {
        if (usuarios[i].codigo == codigo) {
            printf("Código: %d, Nome: %s, Login: %s\n", usuarios[i].codigo, usuarios[i].nome, usuarios[i].login);
            return;
        }
    }
    printf("Usuário não encontrado.\n");
}

void alterarNomeUsuario(struct Usuario usuarios[], int contadorUsuarios, int codigo) {
    char novoNome[TAM_NOME];
    for (int i = 0; i < contadorUsuarios; i++) {
        if (usuarios[i].codigo == codigo) {
            printf("Digite o novo nome: ");
            scanf("%s", novoNome);
            strcpy(usuarios[i].nome, novoNome);
            printf("Nome alterado com sucesso.\n");
            return;
        }
    }
    printf("Usuário não encontrado.\n");
}

void alterarLoginUsuario(struct Usuario usuarios[], int contadorUsuarios, int codigo) {
    char novoLogin[TAM_LOGIN];
    for (int i = 0; i < contadorUsuarios; i++) {
        if (usuarios[i].codigo == codigo) {
            printf("Digite o novo login: ");
            scanf("%s", novoLogin);
            strcpy(usuarios[i].login, novoLogin);
            printf("Login alterado com sucesso.\n");
            return;
        }
    }
    printf("Usuário não encontrado.\n");
}

void alterarSenhaUsuarioUsuario(struct Usuario usuarios[], int contadorUsuarios, int codigo) {
    char novaSenha[TAM_SENHA];
    for (int i = 0; i < contadorUsuarios; i++) {
        if (usuarios[i].codigo == codigo) {
            printf("Digite a nova senha: ");
            scanf("%s", novaSenha);
            strcpy(usuarios[i].senha, novaSenha);
            printf("Senha alterada com sucesso.\n");
            return;
        }
    }
    printf("Usuário não encontrado.\n");
}

void listarTodasMusicas(struct Musica musicas[], int contadorMusicas) {
    listarMusicas(musicas, contadorMusicas);
}

void cadastrarUsuario(struct Usuario usuarios[], int *contadorUsuarios) {
    struct Usuario novoUsuario;
    novoUsuario.codigo = gerarCodigo(contadorUsuarios);
    printf("Digite o nome do usuário: ");
    scanf("%s", novoUsuario.nome);
    printf("Digite o login do usuário: ");
    scanf("%s", novoUsuario.login);
    printf("Digite a senha do usuário: ");
    scanf("%s", novoUsuario.senha);
    novoUsuario.qtdPlaylists = 0;
    novoUsuario.qtdPlaylistsFav = 0;
    if (*contadorUsuarios < TAM_MAX_PLYLST) {
        usuarios[*contadorUsuarios - 1] = novoUsuario;
        printf("Usuário cadastrado com sucesso.\n");
    } else {
        printf("Limite de usuários alcançado.\n");
    }
}

int loginUsuario(struct Usuario usuarios[], int contadorUsuarios) {
    char login[TAM_LOGIN];
    char senha[TAM_SENHA];
    printf("Digite o login: ");
    scanf("%s", login);
    printf("Digite a senha: ");
    scanf("%s", senha);
    for (int i = 0; i < contadorUsuarios; i++) {
        if (strcmp(usuarios[i].login, login) == 0 && strcmp(usuarios[i].senha, senha) == 0) {
            return usuarios[i].codigo;
        }
    }
    return -1;
}

void menuUsuario(struct Usuario usuarios[], struct Musica musicas[], int *contadorUsuarios, int contadorMusicas) {
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
        printf("5. Listar todas as músicas\n");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        switch (opcao) {
            case 1: listarDadosUsuario(usuarios, *contadorUsuarios, codigoUsuario); break;
            case 2: alterarNomeUsuario(usuarios, *contadorUsuarios, codigoUsuario); break;
            case 3: alterarLoginUsuario(usuarios, *contadorUsuarios, codigoUsuario); break;
            case 4: alterarSenhaUsuarioUsuario(usuarios, *contadorUsuarios, codigoUsuario); break; // Linha 373
            case 5: listarTodasMusicas(musicas, contadorMusicas); break;
            case 0: break;
            default: printf("Opção inválida\n");
        }
    } while (opcao != 0);
}

