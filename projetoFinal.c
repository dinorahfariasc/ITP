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
    scanf("%s", nome);

    int nCol;
    printf("Quantidade de colunas: ");
    scanf("%d", &nCol);

    char **nomesColunas = (char **)malloc(nCol * sizeof(char *));
    for (int i = 0; i < nCol; i++) {
        nomesColunas[i] = (char *)malloc(100 * sizeof(char));
        printf("Digite o nome da coluna: ");
        scanf("%s", nomesColunas[i]);
    }

    char ***valoresColunas = (char ***)malloc(sizeof(char **) * 100);
    int numeroLinhas;
    printf("Digite o numero de linhas: ");
    scanf("%d", &numeroLinhas);

    for (int i = 0; i < numeroLinhas; i++) {
        valoresColunas[i] = (char **)malloc(nCol * sizeof(char *));
        for (int j = 0; j < nCol; j++) {
            valoresColunas[i][j] = (char *)malloc(100 * sizeof(char));
            printf("Digite o valor da coluna [%s]: ", nomesColunas[j]);
            scanf("%s", valoresColunas[i][j]);
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
    scanf("%s", nomeDaTabela);

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
    scanf("%s", nomeDaTabela);

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
    scanf("%s", nomeDaTabela);

    for (int i = 0; i < todasTabelas_size; i++) {
        if (strcmp(todasTabelas[i].nomeTabela, nomeDaTabela) == 0) {
            mostrarTabela(&todasTabelas[i], 1);
            char coluna[100];
            printf("Digite o nome da coluna: ");
            scanf("%s", coluna);
            char novoValor[100];
            printf("Digite o novo valor: ");
            scanf("%s", novoValor);

            for (int j = 0; j < todasTabelas[i].nCol; j++) {
                if (strcmp(todasTabelas[i].nomesColunas[j], coluna) == 0) {
                    strcpy(todasTabelas[i].listaValores[0][j], novoValor);
                    break;
                }
            }

            break;
        }
    }
}

int main() {
    Tabela *todasTabelas = NULL;
    int todasTabelas_size = 0;
    int op = 0;

    while (op != 8) {
        printf("\nBem vindo ao sistema de gerenciamento de tabelas\n");
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
                for (int i = 0; i < todasTabelas_size; i++) {
                    printf("%s\n", todasTabelas[i].nomeTabela);
                }
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
