// eleicoes de bairo (frequencia 2 mais votados)

// #include <stdio.h>

// void compute_votes(int n, int votos[], int *maisVotado1, int *maisVotado2) {
//     int frequencia[101] = {0}; // Suponha que os votos variem de 0 a 100
//     *maisVotado1 = 0;
//     *maisVotado2 = 0;

//     for (int i = 0; i < n; i++) {
//         frequencia[votos[i]]++;
//     }

//     for (int i = 1; i <= 100; i++) {
//         if (frequencia[i] > frequencia[*maisVotado1]) {
//             *maisVotado2 = *maisVotado1;
//             *maisVotado1 = i;
//         } else if (frequencia[i] > frequencia[*maisVotado2] && i != *maisVotado1) {
//             *maisVotado2 = i;
//         }
//     }
// }

// int main() {
//     int qntdVotos;
//     scanf("%d", &qntdVotos);

//     int votos[qntdVotos];

//     for (int i = 0; i < qntdVotos; i++) {
//         int voto;
//         scanf("%d", &voto);
//         votos[i] = voto;
//     }

//     int maisVotado1, maisVotado2;
//     compute_votes(qntdVotos, votos, &maisVotado1, &maisVotado2);

//     printf("%d %d\n", maisVotado1, maisVotado2);

//     return 0;
// }
// =======================================================================






// =====================================================================
// calcular media com ponteiros dinorah de farias chagas
// #include <stdio.h>

// void calcular_media(int *A, int *B) {
//     int media = (*A + *B) % 2;
//     int resto = (*A + *B) / 2;

//     // Verificar quem é o maior
//     if (*A > *B) {
//         *A = media;
//         *B = resto;
//     } else {
//         *A = resto;
//         *B = media;
//     }

//     printf("A = %d\n", *A);
//     printf("B = %d\n", *B);
// }

// int main() {
//     int numA, numB;

//     scanf("%d", &numA);
//     scanf("%d", &numB);

//     calcular_media(&numA, &numB);

//     return 0;
// }
// =========================================================