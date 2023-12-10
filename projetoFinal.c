#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *nomeTabela;
    char **nomesColunas;
    char ***listaValores;
    int nCol;
    int numeroLinhas;
    int *tiposColunas;
} Tabela;

// Exemplo de chamada para inserir um valor na coluna k da linha l:
// inserirValorColuna(&todasTabelas[i], l, k);
// onde i é o índice da tabela, l é o índice da linha e k é o índice da coluna
// funcao para salvar uma tabela em formato txt no computador, escolha o nome do arquivo para que possa ser recuperada depois
void salvarTabela(Tabela *todasTabelas, int todasTabelas_size) {
    char nomeTabela[100];
    printf("Digite o nome da tabela que deseja salvar: ");
    scanf(" %[^\n]", nomeTabela);

    // Procurar a tabela pelo nome
    int tabelaIndex = -1;
    for (int i = 0; i < todasTabelas_size; i++) {
        if (strcmp(todasTabelas[i].nomeTabela, nomeTabela) == 0) {
            tabelaIndex = i;
            break;
        }
    }

    if (tabelaIndex == -1) {
        printf("Tabela não encontrada.\n");
        return;
    }

    char nomeArquivo[100];
    printf("Digite o nome do arquivo .txt que será criado: ");
    scanf(" %[^\n]", nomeArquivo);

    FILE *arquivo = fopen(nomeArquivo, "w");
    if (arquivo == NULL) {
        printf("Erro ao criar o arquivo.\n");
        return;
    }

    // Escrever os nomes das colunas no arquivo
    for (int i = 0; i < todasTabelas[tabelaIndex].nCol; i++) {
        fprintf(arquivo, "%s \t", todasTabelas[tabelaIndex].nomesColunas[i]);
    }
    fprintf(arquivo, "\n");

    // Escrever os valores das colunas no arquivo
    for (int i = 0; i < todasTabelas[tabelaIndex].numeroLinhas; i++) {
        for (int j = 0; j < todasTabelas[tabelaIndex].nCol; j++) {
            // verificamos o tipo de cada coluna para printar o valor
            switch (todasTabelas[tabelaIndex].tiposColunas[j]) {
                case 1: // int
                    fprintf(arquivo, "%d \t", *(int *)todasTabelas[tabelaIndex].listaValores[i][j]);
                    break;
                case 2: // float
                    fprintf(arquivo, "%f \t", *(float *)todasTabelas[tabelaIndex].listaValores[i][j]);
                    break;
                case 3: // char
                    fprintf(arquivo, "%c \t", *(char *)todasTabelas[tabelaIndex].listaValores[i][j]);
                    break;
                case 4: // string
                    fprintf(arquivo, "%s \t", (char *)todasTabelas[tabelaIndex].listaValores[i][j]);
                    break;
                default:
                    // Handle unknown data type
                    break;
            }
        }
        fprintf(arquivo, "\n");
    }

    fclose(arquivo);
    printf("Tabela salva com sucesso no arquivo %s.\n", nomeArquivo);
}

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

    int *tiposColunas = (int *)malloc(nCol * sizeof(int));


    for (int i = 0; i < nCol; i++) {
        nomesColunas[i] = (char *)malloc(100 * sizeof(char));
        if (i == 0) {
            printf("Digite o nome da Primary key(int): ");
            scanf(" %[^\n]", nomesColunas[0]);
            tiposColunas[0] = 1;
            continue;
        }
        printf("Digite o nome da coluna %i: ",i);
        scanf(" %[^\n]", nomesColunas[i]);
        printf("Digite o tipo da coluna (1 - int, 2 - float, 3 - char, 4 - string): ");
        scanf("%d", &tiposColunas[i]);
    }

    //char ***valoresColunas = (char ***)malloc(sizeof(char **) * 100);
    int numeroLinhas;
    printf("Digite o numero de entradas(linhas): ");
    scanf(" %d", &numeroLinhas);

    void ***valoresColunas = (void ***)malloc(sizeof(void **) * numeroLinhas);

    for (int i = 0; i < numeroLinhas; i++) {
        valoresColunas[i] = (void **)malloc(nCol * sizeof(void *));
        for (int j = 0; j < nCol; j++) {
            // Allocate memory based on the data type
            switch (tiposColunas[j]) {
                case 1: // int
                    valoresColunas[i][j] = (int *)malloc(sizeof(int));
                    printf("Digite o valor da coluna [%s]: ", nomesColunas[j]);
                    scanf("%d", (int *)valoresColunas[i][j]);
                    break;
                case 2: // float
                    valoresColunas[i][j] = (float *)malloc(sizeof(float));
                    printf("Digite o valor da coluna [%s]: ", nomesColunas[j]);
                    scanf("%f", (float *)valoresColunas[i][j]);
                    break;
                case 3: // char
                    valoresColunas[i][j] = (char *)malloc(sizeof(char));
                    printf("Digite o valor da coluna [%s]: ", nomesColunas[j]);
                    scanf(" %c", (char *)valoresColunas[i][j]);
                    break;
                case 4: // string
                    valoresColunas[i][j] = (char *)malloc(100 * sizeof(char));
                    printf("Digite o valor da coluna [%s]: ", nomesColunas[j]);
                    scanf(" %[^\n]", (char *)valoresColunas[i][j]);
                    break;
                default:
                    // Handle unknown data type
                    break;
            }
        }
    }

    Tabela *nova = (Tabela *)malloc(sizeof(Tabela));
    nova->nomeTabela = strdup(nome);
    nova->nCol = nCol;
    nova->numeroLinhas = numeroLinhas;
    nova->nomesColunas = nomesColunas;
    nova->listaValores = (void **)valoresColunas;
    nova->tiposColunas = tiposColunas;

    *todasTabelas = (Tabela *)realloc(*todasTabelas, sizeof(Tabela) * (*todasTabelas_size + 1));
    (*todasTabelas)[*todasTabelas_size] = *nova;
    (*todasTabelas_size)++;

    printf("Tabela criada com sucesso.\n");
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
                printf("%s \t| ", todasTabelas[i].nomesColunas[j]);
            }

            printf("\n");
            printf("----------------------------------------------------\n");

            for (int j = 0; j < todasTabelas[i].numeroLinhas; j++) {
                for (int k = 0; k < todasTabelas[i].nCol; k++) {
                    // verificamos o tipo de cada coluna para printar o valor

                    // printar os valores de forma alinhada vendo o maior numero de caracteres em uma coluna
                    //int maxCharCount = maiorNumeroCaracteres(todasTabelas, todasTabelas_size, k);
                    //int dif = maxCharCount - strlen(todasTabelas[i].listaValores[j][k]);
                    
                    switch (todasTabelas[i].tiposColunas[k]) {
                        case 1: // int
                            printf("%d \t| ", *(int *)todasTabelas[i].listaValores[j][k]);
                            break;
                        case 2: // float
                            printf("%f \t| ", *(float *)todasTabelas[i].listaValores[j][k]);
                            break;
                        case 3: // char
                            printf("%c \t| ", *(char *)todasTabelas[i].listaValores[j][k]);
                            break;
                        case 4: // string
                            printf("%s \t| ", (char *)todasTabelas[i].listaValores[j][k]);
                            break;
                        default:
                        // Handle unknown data type
                            break;
                    }         
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
            // Encontrou a tabela, agora solicita os valores
            int id;
            printf("Digite o valor da primeira coluna (ID): ");
            scanf("%d", &id);

            // Encontrar a linha correspondente ao ID fornecido
            int linha = -1;
            for (int j = 0; j < todasTabelas[i].numeroLinhas; j++) {
                if (*((int *)todasTabelas[i].listaValores[j][0]) == id) {
                    linha = j;
                    break;
                }
            }

            if (linha == -1) {
                printf("ID não encontrado na tabela.\n");
                return;
            }

            char nomeColuna[100];
            printf("Digite o nome da coluna que deseja editar: ");
            scanf(" %[^\n]", nomeColuna);

            // Encontrar a coluna correspondente ao nome fornecido
            int coluna = -1;
            for (int j = 0; j < todasTabelas[i].nCol; j++) {
                if (strcmp(todasTabelas[i].nomesColunas[j], nomeColuna) == 0) {
                    coluna = j;
                    break;
                }
            }

            if (coluna == -1) {
                printf("Coluna não encontrada na tabela.\n");
                return;
            }

            // Solicitar o novo valor
            switch (coluna) {
                case 0: // Coluna ID (pode ser de qualquer tipo)
                    printf("Digite o novo valor para a coluna %s: ", nomeColuna);
                    scanf(" %[^\n]", (char *)todasTabelas[i].listaValores[linha][coluna]);
                    break;
                default:
                    // Editar valores de acordo com o tipo da coluna
                    switch (todasTabelas[i].tiposColunas[coluna]) {
                        case 1: // int
                            printf("Digite o novo valor para a coluna %s: ", nomeColuna);
                            scanf("%d", (int *)todasTabelas[i].listaValores[linha][coluna]);
                            break;
                        case 2: // float
                            printf("Digite o novo valor para a coluna %s: ", nomeColuna);
                            scanf("%f", (float *)todasTabelas[i].listaValores[linha][coluna]);
                            break;
                        case 3: // char
                            printf("Digite o novo valor para a coluna %s: ", nomeColuna);
                            scanf(" %c", (char *)todasTabelas[i].listaValores[linha][coluna]);
                            break;
                        case 4: // string
                            printf("Digite o novo valor para a coluna %s: ", nomeColuna);
                            scanf(" %[^\n]", (char *)todasTabelas[i].listaValores[linha][coluna]);
                            break;
                        default:
                            // Tratar outros tipos de coluna aqui, se necessário
                            break;
                    }
                    break;
            }

            printf("Valor editado com sucesso.\n");
            return;
        }
    }

    // Se chegou aqui, a tabela não foi encontrada
    printf("Tabela não encontrada.\n");
}

void mostarTodas(Tabela *todasTabelas, int todasTabelas_size) {
    printf("Todas as tabelas:\n");
    for (int i = 0; i < todasTabelas_size; i++) {
        printf("%d - %s\n", i+1,todasTabelas[i].nomeTabela);
    }
}

void editarNomeTabela(Tabela *todasTabelas, int todasTabelas_size) {
    char nomeDaTabela[100];
    printf("Digite o nome da tabela: ");
    scanf(" %[^\n]", nomeDaTabela);

    for (int i = 0; i < todasTabelas_size; i++) {
        if (strcmp(todasTabelas[i].nomeTabela, nomeDaTabela) == 0) {
            char novoNome[100];
            printf("Digite o novo nome da tabela: ");
            scanf(" %[^\n]", novoNome);
            strcpy(todasTabelas[i].nomeTabela, novoNome);
            break;
        }
    }
}

void deletarLinha(Tabela *todasTabelas, int todasTabelas_size){
    char nomeDaTabela[100];
    printf("Digite o nome da tabela: ");
    scanf(" %[^\n]", nomeDaTabela);

    for (int i = 0; i < todasTabelas_size; i++) {
        if (strcmp(todasTabelas[i].nomeTabela, nomeDaTabela) == 0) {
            // Encontrou a tabela, agora solicita os valores
            int id;
            printf("Digite o valor da primeira coluna (ID): ");
            scanf("%d", &id);

            // Encontrar a linha correspondente ao ID fornecido
            int linha = -1;
            for (int j = 0; j < todasTabelas[i].numeroLinhas; j++) {
                if (*((int *)todasTabelas[i].listaValores[j][0]) == id) {
                    linha = j;
                    break;
                }
            }

            if (linha == -1) {
                printf("ID não encontrado na tabela.\n");
                return;
            }

            for (int j = linha; j < todasTabelas[i].numeroLinhas - 1; j++) {
                todasTabelas[i].listaValores[j] = todasTabelas[i].listaValores[j + 1];
            }
            todasTabelas[i].numeroLinhas--;
            printf("Linha deletada com sucesso.\n");
            break;
        }
    }

}

void criarLinha(Tabela *todasTabelas, int todasTabelas_size) {
    char nomeDaTabela[100];
    printf("Digite o nome da tabela: ");
    scanf(" %[^\n]", nomeDaTabela);

    for (int i = 0; i < todasTabelas_size; i++) {
        if (strcmp(todasTabelas[i].nomeTabela, nomeDaTabela) == 0) {
            // Encontrou a tabela, agora solicita os valores
            int id;
            // loop do programa para que o id seja unico TODO

            printf("Digite o valor da Primary key: ");
            scanf("%d", &id);

            // Verificar se a primary key já existe
            for (int j = 0; j < todasTabelas[i].numeroLinhas; j++) {
                if (*((int *)todasTabelas[i].listaValores[j][0]) == id) {
                    printf("Já existe uma linha com a Primary key fornecida.\n");
                    return;
                }
            }

            // A Primary key não existe, então criamos uma nova linha
            todasTabelas[i].numeroLinhas++;

            // Alocar memória para a nova linha
            todasTabelas[i].listaValores = (void ***)realloc(todasTabelas[i].listaValores,
                                                             sizeof(void **) * todasTabelas[i].numeroLinhas);

            int linha = todasTabelas[i].numeroLinhas - 1;
            todasTabelas[i].listaValores[linha] = (void **)malloc(todasTabelas[i].nCol * sizeof(void *));
            
            // preencha o valor do IDcoluna 0 com o valor fornecido
            todasTabelas[i].listaValores[linha][0] = (int *)malloc(sizeof(int));
            *((int *)todasTabelas[i].listaValores[linha][0]) = id;

            // Preencher os valores para cada coluna de acordo com o tipo de dado
            for (int k = 1; k < todasTabelas[i].nCol; k++) {
                switch (todasTabelas[i].tiposColunas[k]) {
                    case 1: // int
                        todasTabelas[i].listaValores[linha][k] = (int *)malloc(sizeof(int));
                        printf("Digite o valor para a coluna [%s]: ", todasTabelas[i].nomesColunas[k]);
                        scanf("%d", (int *)todasTabelas[i].listaValores[linha][k]);
                        break;
                    case 2: // float
                        todasTabelas[i].listaValores[linha][k] = (float *)malloc(sizeof(float));
                        printf("Digite o valor para a coluna [%s]: ", todasTabelas[i].nomesColunas[k]);
                        scanf("%f", (float *)todasTabelas[i].listaValores[linha][k]);
                        break;
                    case 3: // char
                        todasTabelas[i].listaValores[linha][k] = (char *)malloc(sizeof(char));
                        printf("Digite o valor para a coluna [%s]: ", todasTabelas[i].nomesColunas[k]);
                        scanf(" %c", (char *)todasTabelas[i].listaValores[linha][k]);
                        break;
                    case 4: // string
                        todasTabelas[i].listaValores[linha][k] = (char *)malloc(100 * sizeof(char));
                        printf("Digite o valor para a coluna [%s]: ", todasTabelas[i].nomesColunas[k]);
                        scanf(" %[^\n]", (char *)todasTabelas[i].listaValores[linha][k]);
                        break;
                    default:
                        // Handle unknown data type
                        break;
                }
            }

            printf("Linha criada com sucesso.\n");
            return;
        }
    }

    // Se chegou aqui, a tabela não foi encontrada
    printf("Tabela não encontrada.\n");
}

//funcao para ver o maior numero de caracteres em uma coluna e printar os valores de forma alinhada, ainda nao funciona
int maiorNumeroCaracteres(Tabela *todasTabelas, int todasTabelas_size, int coluna) {
    int maior = 0;
    for (int i = 0; i < todasTabelas_size; i++) {
        if (strlen(todasTabelas[i].nomesColunas[coluna]) > maior) {
            maior = strlen(todasTabelas[i].nomesColunas[coluna]);
        }
    }
    return maior;
}

int main() {
    Tabela *todasTabelas = NULL;
    int todasTabelas_size = 0;
    int op = 10;
    printf("\nBem vindo ao sistema de gerenciamento de tabelas\n");
    while (op != 0) {

		printf("\n");
		printf("+=+=+=+=+=+=+=+ SGBD - ITP +=+=+=+=+=+=+=+=\n");
		printf("| 1 - Criar uma tabela                    |\n");
		printf("| 2 - Mostrar todas as tabela             |\n");
		printf("| 3 - Criar Linha                         |\n");
		printf("| 4 - Mostar tabela                       |\n");
		printf("| 5 - Salvar tabela em txt                |\n");
		printf("| 6 - Editar coluna da tabela             |\n");
		printf("| 7 - Apagar linha                        |\n");
        printf("| 8 - Apagar tabela                       |\n");
		printf("| 0 - Sair                                |\n");
		printf("+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+\n");
		printf("\n");
        
        printf("Digite a opcao desejada: ");
        scanf("%d", &op);

        switch (op) {
            case 1:
                criarTabela(&todasTabelas, &todasTabelas_size);
                break;
            case 2:
                mostarTodas(todasTabelas, todasTabelas_size);
                break;
            case 3:
                criarLinha(todasTabelas, todasTabelas_size);
                break;
            case 4:
                mostrarTabela(todasTabelas, todasTabelas_size);
                break;
            case 5:
                salvarTabela(todasTabelas, todasTabelas_size);
                break;
            case 6:
                editarValorTabela(todasTabelas, todasTabelas_size);
                break;
            case 7:
                deletarLinha(todasTabelas, &todasTabelas_size);
                break;
            case 8:
                deletarTabela(todasTabelas, todasTabelas_size);
                break;
        } 


    }
    return 0;
}
