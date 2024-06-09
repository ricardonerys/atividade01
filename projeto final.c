#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM_MAX_PLYLST 200
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

// Variáveis globais
int contadorUsuarios = 0;
int contadorMusicas = 0;
int contadorPlaylists = 0;
struct Usuario usuarios[TAM_MAX_PLYLST];
struct Musica musicas[TAM_MAX_PLYLST];
struct Playlist playlists[TAM_MAX_PLYLST];
//-----------------------------------------------------------------------------------------------------------------------------------------------
// Funções utilitárias
int gerarCodigo(int *contador) {
    return ++(*contador);
}

int validarSenhaAdmin(char *senha) {
    return strcmp(senha, "m@st3r2024") == 0;
}

// Funções do Administrador
void listarUsuarios() {
    for (int i = 0; i < contadorUsuarios; i++) {
        printf("Código: %d, Nome: %s, Login: %s\n", usuarios[i].codigo, usuarios[i].nome, usuarios[i].login);
    }
}

void consultarUsuario() {
    char termo[TAM_NOME];
    printf("Digite o login ou parte do nome: ");
    scanf("%s", termo);
    for (int i = 0; i < contadorUsuarios; i++) {
        if (strstr(usuarios[i].login, termo) || strstr(usuarios[i].nome, termo)) {
            printf("Código: %d, Nome: %s, Login: %s\n", usuarios[i].codigo, usuarios[i].nome, usuarios[i].login);
        }
    }
}

void alterarSenhaUsuario() {
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

void cadastrarMusica() {
    struct Musica novaMusica;
    novaMusica.codigo = gerarCodigo(&contadorMusicas);
    printf("Digite o título da música: ");
    scanf("%s", novaMusica.titulo);
    printf("Digite o nome do artista: ");
    scanf("%s", novaMusica.artista);
    musicas[contadorMusicas - 1] = novaMusica;
    printf("Música cadastrada com sucesso.\n");
}

void listarMusicas() {
    for (int i = 0; i < contadorMusicas; i++) {
        printf("Código: %d, Título: %s, Artista: %s\n", musicas[i].codigo, musicas[i].titulo, musicas[i].artista);
    }
}

void consultarMusica() {
    char termo[TAM_TITULO];
    printf("Digite o código, parte do título da música ou nome do artista: ");
    scanf("%s", termo);
    for (int i = 0; i < contadorMusicas; i++) {
        if (strstr(musicas[i].titulo, termo) || strstr(musicas[i].artista, termo) || atoi(termo) == musicas[i].codigo) {
            printf("Código: %d, Título: %s, Artista: %s\n", musicas[i].codigo, musicas[i].titulo, musicas[i].artista);
        }
    }
}

void alterarMusica() {
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

void excluirMusica() {
    int codigo;
    printf("Digite o código da música: ");
    scanf("%d", &codigo);
    for (int i = 0; i < contadorMusicas; i++) {
        if (musicas[i].codigo == codigo) {
            for (int j = i; j < contadorMusicas - 1; j++) {
                musicas[j] = musicas[j + 1];
            }
            contadorMusicas--;
            printf("Música excluída com sucesso.\n");
            return;
        }
    }
    printf("Música não encontrada.\n");
}

void listarPlaylists() {
    for (int i = 0; i < contadorPlaylists; i++) {
        printf("Código: %d, Título: %s, Criador: %d\n", playlists[i].codigo, playlists[i].titulo, playlists[i].codUsuario);
        for (int j = 0; j < playlists[i].qtdMusicas; j++) {
            printf("\tMúsica %d: %d\n", j + 1, playlists[i].musicas[j]);
        }
    }
}

void consultarPlaylist() {
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

// Menu do Administrador
void menuAdministrador() {
    char senha[TAM_SENHA];
    printf("Digite a senha de administrador: ");
    scanf("%s", senha);
    if (validarSenhaAdmin(senha)) {
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
                case 1: listarUsuarios(); break;
                case 2: consultarUsuario(); break;
                case 3: alterarSenhaUsuario(); break;
                case 4: cadastrarMusica(); break;
                case 5: listarMusicas(); break;
                case 6: consultarMusica(); break;
                case 7: alterarMusica(); break;
                case 8: excluirMusica(); break;
                case 9: listarPlaylists(); break;
                case 10: consultarPlaylist(); break;
                case 0: break;
                default: printf("Opção inválida\n");
            }
        } while (opcao != 0);
    } else {
        printf("Senha incorreta!\n");
    }
}

// Funções do Usuário
void listarDadosUsuario(int codigo) {
    for (int i = 0; i < contadorUsuarios; i++) {
        if (usuarios[i].codigo == codigo) {
            printf("Código: %d, Nome: %s, Login: %s\n", usuarios[i].codigo, usuarios[i].nome, usuarios[i].login);
            return;
        }
    }
}

void alterarNomeUsuario(int codigo) {
    char nome[TAM_NOME], senha[TAM_SENHA];
    for (int i = 0; i < contadorUsuarios; i++) {
        if (usuarios[i].codigo == codigo) {
            printf("Digite a senha: ");
            scanf("%s", senha);
            if (strcmp(senha, usuarios[i].senha) == 0) {
                printf("Digite o novo nome: ");
                scanf("%s", nome);
                strcpy(usuarios[i].nome, nome);
                printf("Nome alterado com sucesso.\n");
            } else {
                printf("Senha incorreta.\n");
            }
            return;
        }
    }
}

void alterarLoginUsuario(int codigo) {
    char login[TAM_LOGIN], senha[TAM_SENHA];
    for (int i = 0; i < contadorUsuarios; i++) {
        if (usuarios[i].codigo == codigo) {
            printf("Digite a senha: ");
            scanf("%s", senha);
            if (strcmp(senha, usuarios[i].senha) == 0) {
                printf("Digite o novo login: ");
                scanf("%s", login);
                strcpy(usuarios[i].login, login);
                printf("Login alterado com sucesso.\n");
            } else {
                printf("Senha incorreta.\n");
            }
            return;
        }
    }
}

void alterarSenhaUsuarioUsuario(int codigo) {
    char senhaAtual[TAM_SENHA], novaSenha[TAM_SENHA], confirmaSenha[TAM_SENHA];
    for (int i = 0; i < contadorUsuarios; i++) {
        if (usuarios[i].codigo == codigo) {
            printf("Digite a senha atual: ");
            scanf("%s", senhaAtual);
            if (strcmp(senhaAtual, usuarios[i].senha) == 0) {
                printf("Digite a nova senha: ");
                scanf("%s", novaSenha);
                printf("Confirme a nova senha: ");
                scanf("%s", confirmaSenha);
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

void listarTodasMusicas() {
    for (int i = 0; i < contadorMusicas; i++) {
        printf("Código: %d, Título: %s, Artista: %s\n", musicas[i].codigo, musicas[i].titulo, musicas[i].artista);
    }
}

// Funções de Cadastro e Login de Usuário
void cadastrarUsuario() {
    struct Usuario novoUsuario;
    novoUsuario.codigo = gerarCodigo(&contadorUsuarios);
    printf("Digite o nome: ");
    scanf("%s", novoUsuario.nome);
    printf("Digite o login: ");
    scanf("%s", novoUsuario.login);
    printf("Digite a senha: ");
    scanf("%s", novoUsuario.senha);
    novoUsuario.qtdPlaylists = 0;
    novoUsuario.qtdPlaylistsFav = 0;
    usuarios[contadorUsuarios - 1] = novoUsuario;
    printf("Usuário cadastrado com sucesso.\n");
}

int loginUsuario() {
    char login[TAM_LOGIN], senha[TAM_SENHA];
    printf("Digite o login: ");
    scanf("%s", login);
    printf("Digite a senha: ");
    scanf("%s", senha);
    for (int i = 0; i < contadorUsuarios; i++) {
        if (strcmp(usuarios[i].login, login) == 0 && strcmp(usuarios[i].senha, senha) == 0) {
            printf("Login bem-sucedido.\n");
            return usuarios[i].codigo;
        }
    }
    printf("Login ou senha incorretos.\n");
    return -1;
}

// Menu do Usuário
void menuUsuario() {
    int codigoUsuario = -1, opcao;
    while (codigoUsuario == -1) {
        printf("1. Login\n");
        printf("2. Cadastro\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        if (opcao == 1) {
            codigoUsuario = loginUsuario();
        } else if (opcao == 2) {
            cadastrarUsuario();
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
            case 1: listarDadosUsuario(codigoUsuario); break;
            case 2: alterarNomeUsuario(codigoUsuario); break;
            case 3: alterarLoginUsuario(codigoUsuario); break;
            case 4: alterarSenhaUsuarioUsuario(codigoUsuario); break;
            case 5: listarTodasMusicas(); break;
            case 0: break;
            default: printf("Opção inválida\n");
        }
    } while (opcao != 0);
}

// Menu Principal
void menuPrincipal() {
    int opcao;
    do {
        printf("\nMenu Principal\n");
        printf("1. Administrador\n");
        printf("2. Usuário\n");
        printf("0. encerrar programa\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        switch (opcao) {
            case 1: menuAdministrador();
                break;
            case 2: menuUsuario(); 
                break;
            case 0:
                break;
            default: printf("Opção inválida\n");
        }
    } while (opcao != 0);
}
//-----------------------------------------------------------------------------------------------------------------
int main() {
    menuPrincipal();
    return 0;
}
