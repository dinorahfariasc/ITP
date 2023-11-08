// pacman
// #include <stdio.h>
// #define MAX_SIZE 10

// // vendo se nao é parede ou vazio
// int seguro(int row, int col, int ROW, int COL, char map[MAX_SIZE][MAX_SIZE]) {
//     return (row >= 0 && row < ROW && col >= 0 && col < COL && map[row][col] != '*' && map[row][col] != ' ');
// }

// // Função para contar as bolinhas devoradas recursivamente
// int countBalls(char map[MAX_SIZE][MAX_SIZE], int row, int col, int ROW, int COL) {
//     // Se a célula não for segura, retornar 0
//     if (!seguro(row, col, ROW, COL, map)) {
//         return 0;
//     }

//     // Se a célula contém uma bolinha, marcar como vazio e contar a bolinha
//     if (map[row][col] == '.') {
//         map[row][col] = ' '; 
//         return 1 + countBalls(map, row + 1, col, ROW, COL) + countBalls(map, row - 1, col, ROW, COL) +
//                countBalls(map, row, col + 1, ROW, COL) + countBalls(map, row, col - 1, ROW, COL);
//     }

//     // o boneco continuar a procurar
//     if (map[row][col] == 'C') {
//         return countBalls(map, row + 1, col, ROW, COL) + countBalls(map, row - 1, col, ROW, COL) +
//                countBalls(map, row, col + 1, ROW, COL) + countBalls(map, row, col - 1, ROW, COL);
//     }

//     return 0;
// }

// int main() {
//     int ROW, COL;
//     char map[MAX_SIZE][MAX_SIZE];

//     scanf("%d %d", &ROW, &COL);

//     for (int i = 0; i < ROW; i++) {
//         scanf("%s", map[i]);
//     }

//     int pacman_row = -1, pacman_col = -1;

//     // Encontrar a posição inicial do Pacman no mapa
//     for (int i = 0; i < ROW; i++) {
//         for (int j = 0; j < COL; j++) {
//             if (map[i][j] == 'C') {
//                 pacman_row = i;
//                 pacman_col = j;
//                 break;
//             }
//         }
//         if (pacman_row != -1) {
//             break;
//         }
//     }

//     if (pacman_row == -1 || pacman_col == -1) {
//         printf("Pacman não encontrado no mapa.\n");
//         return 1;
//     }

//     // contar o número de bolinhas devoradas, considerando fantasmas como bloqueios
//     int totalBalls = countBalls(map, pacman_row, pacman_col, ROW, COL);

//     printf("Total de bolinhas devoradas: %d\n", totalBalls);
//     printf("Mapa final:\n");

//     // Imprimir o mapa final
//     for (int i = 0; i < ROW; i++) {
//         for (int j = 0; j < COL; j++) {
//             printf("%c", map[i][j]);
//         }
//         printf("\n");
//     }

//     return 0;
// }

// ==================================================================
// numero decimal para binario
// #include <stdio.h>

// void binario(int n) {
//     if (n > 1) {
//         binario(n / 2);
//     }
//     printf("%d", n % 2);
// }

// int main() {
//     int n;
//     scanf("%d", &n);

//     if (n < 0) {
//     } else if (n == 0) {
//         printf("0");
//     } else {
//         binario(n);
//     }

//     return 0;
// }
//===================================================
// sudoku 
// #include <stdio.h>
// #include <stdbool.h>

// #define N 9

// bool ehSeguro(int grade[N][N], int linha, int coluna, int num) {

//     for (int x = 0; x < N; x++) {
//         if (grade[linha][x] == num || grade[x][coluna] == num) {
//             return false;
//         }
//     }

//     int inicioLinha = linha - linha % 3;
//     int inicioColuna = coluna - coluna % 3;
//     for (int i = 0; i < 3; i++) {
//         for (int j = 0; j < 3; j++) {
//             if (grade[i + inicioLinha][j + inicioColuna] == num) {
//                 return false;
//             }
//         }
//     }

//     return true;
// }

// bool encontrarPosicaoNaoAtribuida(int grade[N][N], int *linha, int *coluna) {
//     for (*linha = 0; *linha < N; (*linha)++) {
//         for (*coluna = 0; *coluna < N; (*coluna)++) {
//             if (grade[*linha][*coluna] == 0) {
//                 return true;
//             }
//         }
//     }
//     return false;
// }

// bool resolverSudoku(int grade[N][N]) {
//     int linha, coluna;

//     if (!encontrarPosicaoNaoAtribuida(grade, &linha, &coluna)) {
//         return true; 
//     }

//     for (int num = 1; num <= 9; num++) {
//         if (ehSeguro(grade, linha, coluna, num)) {
//             grade[linha][coluna] = num;

//             if (resolverSudoku(grade)) {
//                 return true;
//             }

//             grade[linha][coluna] = 0; 
//         }
//     }

//     return false; 
// }

// void imprimirSudoku(int grade[N][N]) {
//     for (int i = 0; i < N; i++) {
//         for (int j = 0; j < N; j++) {
//             printf("%d", grade[i][j]);
//         }
//         printf("\n");
//     }
// }

// int main() {
//     int grade[N][N];

//     for (int i = 0; i < N; i++) {
//         for (int j = 0; j < N; j++) {
//             char celula;
//             scanf(" %c", &celula);
//             if (celula == '*') {
//                 grade[i][j] = 0;
//             } else {
//                 grade[i][j] = celula - '0';
//             }
//         }
//     }

//     if (resolverSudoku(grade)) {
//         imprimirSudoku(grade);
//     } else {
//         printf("Não tem solução!\n");
//     }

//     return 0;
// }
// ========================================================
//palindromo
// #include <stdio.h>
// #include <string.h>
// #include <ctype.h>

// int ehAlfanumerico(char c) {
//     return isalnum(c);
// }

// int palindromoRecursivo(char *texto, int esquerda, int direita) {
//     if (esquerda >= direita) {
//         return 1; 
//     }

//     if (texto[esquerda] != texto[direita]) {
//         return 0;
//     }

//     return palindromoRecursivo(texto, esquerda + 1, direita - 1);
// }

// int palindromo(char *entrada) {
//     int esquerda = 0;
//     int direita = strlen(entrada) - 1;

//     while (esquerda < direita) {
        
//         while (esquerda < direita && !ehAlfanumerico(entrada[esquerda])) {
//             esquerda++;
//         }
//         while (esquerda < direita && !ehAlfanumerico(entrada[direita])) {
//             direita--;
//         }

//         if (tolower(entrada[esquerda]) != tolower(entrada[direita])) {
//             return 0; 
//         }

//         esquerda++;
//         direita--;
//     }

//     return 1; 
// }

// int main() {
//     char texto[1000];

//     fgets(texto, sizeof(texto), stdin);

//     if (palindromo(texto)) {
//         printf("O texto \"%s\" é palíndromo\n", texto);
//     } else {
//         printf("O texto \"%s\" não é palíndromo\n", texto);
//     }

//     return 0;
// }
//===============================================================