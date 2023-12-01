#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *nomeTabela;
    char **nomesColunas;
    char ***listaValores;
    int nCol;
    int numeroLinhas;
} Tabela;

void criarTabela(Tabela **todasTabelas, int *todasTabelas_size) {
    char nome[100];
    printf("Digite o nome da tabela: ");
    scanf(" %[^\n]", nome);
    
   // se o nome da tabela já existir,pedir pra escrever outro nome
    for (int i = 0; i < *todasTabelas_size; i++) {
        if (strcmp((*todasTabelas)[i].nomeTabela, nome) == 0) {
            printf("Nome da tabela já existe, digite outro nome\n");
            scanf(" %[^\n]", nome);
            i = -1;
        }
    }

    int nCol;
    printf("Quantidade de colunas: ");
    scanf("%d", &nCol);

    // criar uma coluna fixa para o id
    nCol++;


    char **nomesColunas = (char **)malloc(nCol * sizeof(char *));
    nomesColunas[0] = strdup("ID");
    for (int i = 1; i < nCol; i++) {
        nomesColunas[i] = (char *)malloc(100 * sizeof(char));
        printf("Digite o nome da coluna: ");
        scanf(" %[^\n]", nomesColunas[i]);
    }

    char ***valoresColunas = (char ***)malloc(sizeof(char **) * 100);
    int numeroLinhas;
    printf("Digite o numero de entradas(linhas): ");
    scanf(" %d", &numeroLinhas);

    for (int i = 0; i < numeroLinhas; i++) {
        valoresColunas[i] = (char **)malloc(nCol * sizeof(char *));
        for (int j = 0; j < nCol; j++) {
            valoresColunas[i][j] = (char *)malloc(100 * sizeof(char));
            printf("Digite o valor da coluna [%s]: ", nomesColunas[j]);
            scanf(" %[^\n]", valoresColunas[i][j]);
        }
    }

    Tabela *nova = (Tabela *)malloc(sizeof(Tabela));
    nova->nomeTabela = strdup(nome);
    nova->nCol = nCol;
    nova->numeroLinhas = numeroLinhas;
    nova->nomesColunas = nomesColunas;
    nova->listaValores = valoresColunas;

    *todasTabelas = (Tabela *)realloc(*todasTabelas, sizeof(Tabela) * (*todasTabelas_size + 1));
    (*todasTabelas)[*todasTabelas_size] = *nova;
    (*todasTabelas_size)++;
}

void deletarTabela(Tabela *todasTabelas, int *todasTabelas_size) {
    char nomeDaTabela[100];
    printf("Digite o nome da tabela: ");
    scanf(" %[^\n]", nomeDaTabela);

    for (int i = 0; i < *todasTabelas_size; i++) {
        if (strcmp(todasTabelas[i].nomeTabela, nomeDaTabela) == 0) {
            for (int j = i; j < *todasTabelas_size - 1; j++) {
                todasTabelas[j] = todasTabelas[j + 1];
            }
            (*todasTabelas_size)--;
            break;
        }
    }
}

void mostrarTabela(Tabela *todasTabelas, int todasTabelas_size) {
    char nomeDaTabela[100];
    printf("Digite o nome da tabela: ");
    scanf(" %[^\n]", nomeDaTabela);

    for (int i = 0; i < todasTabelas_size; i++) {
        if (strcmp(todasTabelas[i].nomeTabela, nomeDaTabela) == 0) {
            printf("\nTabela: %s\n", todasTabelas[i].nomeTabela);
            printf("====================================================\n");

            for (int j = 0; j < todasTabelas[i].nCol; j++) {
                printf("%s | ", todasTabelas[i].nomesColunas[j]);
            }

            printf("\n");
            printf("----------------------------------------------------\n");

            for (int j = 0; j < todasTabelas[i].numeroLinhas; j++) {
                for (int k = 0; k < todasTabelas[i].nCol; k++) {
                    printf("%s | ", todasTabelas[i].listaValores[j][k]);
                }
                printf("\n");
            }

            break;
        }
    }
}

void editarValorTabela(Tabela *todasTabelas, int todasTabelas_size) {
    char nomeDaTabela[100];
    printf("Digite o nome da tabela: ");
    scanf(" %[^\n]", nomeDaTabela);

    for (int i = 0; i < todasTabelas_size; i++) {
        if (strcmp(todasTabelas[i].nomeTabela, nomeDaTabela) == 0) {
            mostrarTabela(&todasTabelas[i], 1);
            char linha[100];
            printf("Digite o ID da linha: ");
            scanf(" %[^\n]", linha);
            char coluna[100];
            printf("Digite o nome da coluna: ");
            scanf(" %[^\n]", coluna);
            char novoValor[100];
            printf("Digite o novo valor: ");
            scanf(" %[^\n]", novoValor);

            for (int j = 0; j < todasTabelas[i].numeroLinhas; j++) {
                if (strcmp(todasTabelas[i].listaValores[j][0], linha) == 0) {
                    for (int k = 0; k < todasTabelas[i].nCol; k++) {
                        if (strcmp(todasTabelas[i].nomesColunas[k], coluna) == 0) {
                            strcpy(todasTabelas[i].listaValores[j][k], novoValor);
                            break;
                        }
                    }
                    break;
                }
            }

            break;
        }
    }
}

void mostarTodas(Tabela *todasTabelas, int todasTabelas_size) {
    printf("Todas as tabelas:\n");
    for (int i = 0; i < todasTabelas_size; i++) {
        printf("%d - %s\n", i+1,todasTabelas[i].nomeTabela);
    }
}

int main() {
    Tabela *todasTabelas = NULL;
    int todasTabelas_size = 0;
    int op = 0;
    printf("\nBem vindo ao sistema de gerenciamento de tabelas\n");
    while (op != 8) {
        printf("\nMENU \n");
        printf("====================================================\n");
        printf("1 - Criar tabela\n");
        printf("2 - Deletar tabela\n");
        printf("3 - Mostrar tabela\n");
        printf("4 - Mostrar todas as tabelas\n");
        printf("5 - Editar valor da tabela\n");
        printf("6 - Editar coluna da tabela\n");
        printf("7 - Editar nome da tabela\n");
        printf("8 - Sair\n");

        printf("Digite op: ");
        scanf("%d", &op);

        switch (op) {
            case 1:
                criarTabela(&todasTabelas, &todasTabelas_size);
                break;
            case 2:
                deletarTabela(todasTabelas, &todasTabelas_size);
                break;
            case 3:
                mostrarTabela(todasTabelas, todasTabelas_size);
                break;
            case 4:
                mostarTodas(todasTabelas, todasTabelas_size);
                break;
            case 5:
                editarValorTabela(todasTabelas, todasTabelas_size);
                break;
            // Casos
                    // Casos 6 e 7 podem ser adicionados aqui
        }

        // Restante do código

    }

    // // Libera a memória alocada para todas as tabelas
    // for (int i = 0; i < todasTabelas_size; i++) {
    //     for (int j = 0; j < todasTabelas[i].nCol; j++) {
    //         free(todasTabelas[i].nomesColunas[j]);
    //     }

    //     for (int j = 0; j < todasTabelas[i].numeroLinhas; j++) {
    //         for (int k = 0; k < todasTabelas[i].nCol; k++) {
    //             free(todasTabelas[i].listaValores[j][k]);
    //         }
    //         free(todasTabelas[i].listaValores[j]);
    //     }

    //     free(todasTabelas[i].nomesColunas);
    //     free(todasTabelas[i].listaValores);
    //     free(todasTabelas[i].nomeTabela);
    // }

    // free(todasTabelas);

    return 0;
}
