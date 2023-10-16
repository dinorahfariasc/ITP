// estatisticas times futebol

// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>

// // Definindo a estrutura do Time
// struct Time {
//     char nome[50];
//     int golsM;
//     int golsS;
// };

// // Função para comparar times com base nos gols marcados
// int compareTimes(const void *a, const void *b) {
//     struct Time *timeA = (struct Time *)a;
//     struct Time *timeB = (struct Time *)b;
//     return timeB->golsM - timeA->golsM;
// }

// int main() {
//     int qntd;
//     printf("Digite a quantidade de times: ");
//     scanf("%d", &qntd);
//     // Limpar o buffer de entrada
//     while (getchar() != '\n');

//     // Criando um array de estruturas Time
//     struct Time times[qntd];

//     for (int i = 0; i < qntd; i++) {
        
//         // Usando fgets para receber uma linha inteira
//         fgets(times[i].nome, sizeof(times[i].nome), stdin);
//         times[i].nome[strcspn(times[i].nome, "\n")] = '\0'; // Remover o caractere de nova linha
//         scanf("%d", &times[i].golsM);
//         scanf("%d", &times[i].golsS);
//         // Limpar o buffer de entrada
//         while (getchar() != '\n');
//     }

//     // Ordenar a lista de times por gols marcados
//     qsort(times, qntd, sizeof(struct Time), compareTimes);

//     for (int i = 0; i < qntd; i++) {
//         printf("%d - %s\nGols marcados: %d\nGols sofridos: %d\n", i + 1, times[i].nome, times[i].golsM, times[i].golsS);
//     }

//     return 0;
// }
//========================================================================================================
// compra de smartphones 

// #include <stdio.h>
// #include <string.h>

// #define MAX_MODELO 40

// struct Smartphone {
//     char modelo[MAX_MODELO];
//     int memoria;
//     float processador;
//     float camera;
//     float bateria;
// };

// void tabela(struct Smartphone smartphone) {
//     printf("Modelo: %s\n", smartphone.modelo);
//     printf("Memoria: %dGB\n", smartphone.memoria);
//     printf("Processador: %.2fGhz\n", smartphone.processador);
//     printf("Camera: %.2fMPixels\n", smartphone.camera);
//     printf("Bateria: %.2fmA\n", smartphone.bateria);
// }

// int main() {
//     char entrada[2];
//     struct Smartphone catalogo[100];
//     int count = 0;
//     int memoriaTeste;
//     float processadorTeste, cameraTeste, bateriaTeste;

//     while (1) {
//         scanf("%s", entrada);

//         if (strcmp(entrada, "n") == 0) {
//             scanf("%d %f %f %f", &memoriaTeste, &processadorTeste, &cameraTeste, &bateriaTeste);
//             break;
//         } else if (strcmp(entrada, "s") == 0) {
//             char modelo[MAX_MODELO];
//             int memoria;
//             float processador, camera, bateria;

//             scanf(" %39[^\n] %d %f %f %f", modelo, &memoria, &processador, &camera, &bateria);
//             struct Smartphone smartphone;
//             strncpy(smartphone.modelo, modelo, MAX_MODELO);
//             smartphone.memoria = memoria;
//             smartphone.processador = processador;
//             smartphone.camera = camera;
//             smartphone.bateria = bateria;

//             catalogo[count] = smartphone;
//             count++;
//         }
//     }

//     int encontrados = 0;

//     for (int i = 0; i < count; i++) {
//         if (catalogo[i].memoria >= memoriaTeste && catalogo[i].processador >= processadorTeste &&
//             catalogo[i].camera >= cameraTeste && catalogo[i].bateria >= bateriaTeste) {
//             tabela(catalogo[i]);
//             printf("\n");
//             encontrados++;
//         }
//     }

//     if (encontrados > 0) {
//         printf("%d smartphones encontrados.\n", encontrados);
//     } else {
//         printf("0 smartphones encontrados.\n");
//     }

//     return 0;
// }
//========================================================================================================
// Bola pro mato, que o jogo é de campeonato! (tabela pontos corridos)

// #include <stdio.h>
// #include <string.h>

// #define MAX_NOME 200

// struct Time {
//     char nome[MAX_NOME];
//     int vitorias, empates, derrotas, golsM, golsS, pontos, jogos, saldoGols;
// };

// void tabela(struct Time time) {
//     printf("%s| %d| %d| %d| %d| %d| %d| %d| %d", time.nome, time.pontos, time.jogos, time.vitorias, time.empates, time.derrotas, time.golsM, time.golsS, time.saldoGols);
// }

// int compararTimes(const void *a, const void *b) {
//     struct Time *timeA = (struct Time *)a;
//     struct Time *timeB = (struct Time *)b;

//     if (timeA->pontos != timeB->pontos) {
//         return timeB->pontos - timeA->pontos;
//     }

//     if (timeA->vitorias != timeB->vitorias) {
//         return timeB->vitorias - timeA->vitorias;
//     }

//     return timeB->saldoGols - timeA->saldoGols;
// }

// int main() {
//     int qntd;
//     scanf("%d", &qntd);

//     struct Time times[qntd];

//     for (int i = 0; i < qntd; i++) {
//         scanf("%[^;]; %d %d %d %d %d", times[i].nome, &times[i].vitorias, &times[i].empates, &times[i].derrotas, &times[i].golsM, &times[i].golsS);
//         times[i].pontos = (times[i].vitorias * 3) + times[i].empates;
//         times[i].jogos = times[i].vitorias + times[i].empates + times[i].derrotas;
//         times[i].saldoGols = times[i].golsM - times[i].golsS;
//     }

//     qsort(times, qntd, sizeof(struct Time), compararTimes);
    
//     printf("Tabela do campeonato:\n");
//     printf("Nome| Pontos| Jogos| Vitorias| Empates| Derrotas| Gols Pro| Gols Contra| Saldo de Gols");
//     for (int i = 0; i < qntd; i++) {
//         tabela(times[i]);
//     }
    
//     printf("\n");
     
//     printf("\nTimes na zona da libertadores:");
//     for (int i = 0; i < 6; i++) {
//         printf("%s", times[i].nome);
//     }
    
//     printf("\n");

//     printf("\nTimes rebaixados:");
//     for (int i = qntd - 1; i >= qntd - 4 && i >= 0; i--) {
//         printf("%s", times[i].nome);
//     }

//     return 0;
// }
//========================================================================================================


