// pacman
#include <stdio.h>
#define MAX_SIZE 10

// vendo se nao é parede ou vazio
int seguro(int row, int col, int ROW, int COL, char map[MAX_SIZE][MAX_SIZE]) {
    return (row >= 0 && row < ROW && col >= 0 && col < COL && map[row][col] != '*' && map[row][col] != ' ');
}

// Função para contar as bolinhas devoradas recursivamente
int countBalls(char map[MAX_SIZE][MAX_SIZE], int row, int col, int ROW, int COL) {
    // Se a célula não for segura, retornar 0
    if (!seguro(row, col, ROW, COL, map)) {
        return 0;
    }

    // Se a célula contém uma bolinha, marcar como vazio e contar a bolinha
    if (map[row][col] == '.') {
        map[row][col] = ' '; 
        return 1 + countBalls(map, row + 1, col, ROW, COL) + countBalls(map, row - 1, col, ROW, COL) +
               countBalls(map, row, col + 1, ROW, COL) + countBalls(map, row, col - 1, ROW, COL);
    }

    // o boneco continuar a procurar
    if (map[row][col] == 'C') {
        return countBalls(map, row + 1, col, ROW, COL) + countBalls(map, row - 1, col, ROW, COL) +
               countBalls(map, row, col + 1, ROW, COL) + countBalls(map, row, col - 1, ROW, COL);
    }

    return 0;
}

int main() {
    int ROW, COL;
    char map[MAX_SIZE][MAX_SIZE];

    scanf("%d %d", &ROW, &COL);

    for (int i = 0; i < ROW; i++) {
        scanf("%s", map[i]);
    }

    int pacman_row = -1, pacman_col = -1;

    // Encontrar a posição inicial do Pacman no mapa
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            if (map[i][j] == 'C') {
                pacman_row = i;
                pacman_col = j;
                break;
            }
        }
        if (pacman_row != -1) {
            break;
        }
    }

    if (pacman_row == -1 || pacman_col == -1) {
        printf("Pacman não encontrado no mapa.\n");
        return 1;
    }

    // contar o número de bolinhas devoradas, considerando fantasmas como bloqueios
    int totalBalls = countBalls(map, pacman_row, pacman_col, ROW, COL);

    printf("Total de bolinhas devoradas: %d\n", totalBalls);
    printf("Mapa final:\n");

    // Imprimir o mapa final
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            printf("%c", map[i][j]);
        }
        printf("\n");
    }

    return 0;
}
