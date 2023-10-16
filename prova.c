// # include<stdio.h>
// // ver maior numero de uma linha ou coluna de uma matriz
// int main(){
    
//     int linhas;
//     int colunas;
//     char tipo;
//     int local;
    
//     scanf("%d %d", &linhas,&colunas);
    
//     int matriz[linhas][colunas];
    
//     int numero;

//   // receber matriz
//     for(int i =0 ;i < linhas; i++){
//         for(int j = 0; j < colunas; j++){
//             scanf("%d",&numero);
//             matriz[i][j] = numero;
//         }
//     }

//     // mostar matriz
//     printf("\n");
//     for(int i =0 ;i < linhas; i++){
//         for(int j = 0; j < colunas; j++){
//             printf("%d ",matriz[i][j]);
//         }
//         printf("\n");
//     }
    
//     scanf(" %c",&tipo);
//     scanf(" %d",&local);

//     int maior = 0;
    

//     if(tipo == 'l'){
//         for(int i = 0; i < colunas; i++){
//             if(matriz[local][i] > maior){
//                 maior = matriz[local][i];
//             }
//         }
//         printf("%d",maior);
//     }
//     else if(tipo == 'c'){
//         for(int i = 0; i < linhas; i++){
//             if(matriz[i][local] > maior){
//                 maior = matriz[i][local];
//             }
//         }
//         printf("%d",maior);
//     }

    

    
    
// }


// // for(int i =0 ;i < linhas; i++){
// //         for(int j = 0; j < colunas; j++){
// //             scanf("%d",&numero);
// //             matriz[i][j] = numero;
// //         }
// //     }

//=======================================================

// printar ateriscos por colunas

// #include <stdio.h>

// int main(){

//     int colunas;
//     int numero;

//     scanf("%d",&colunas);

//     int numeros[colunas];
    
//     for(int i = 0;i < colunas; i++){
//         scanf(" %d",&numero);
//         numeros[i] = numero;
//     }

//     for(int i = 0;i < colunas; i++){
//         int vez = numeros[i];
//         for(int j = 0;j <vez; j++){
//             printf("*");
//         }
//         printf("\n");
//     }
// }
//=======================================================

#include <stdio.h>
#include <stdbool.h>

bool numeroperfeito(int num) {

    int somadiv = 1;

    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            somadiv += i;
            if (i != num / i) {
                somadiv += num / i;
            }
        }
    }

    return somadiv == num;
}

int main() {
    int N;
    scanf("%d", &N);
    
    for (int i = 0; i < N; i++) {
        int X;
        scanf("%d", &X);
        
        if (isPerfect(X)) {
            printf("%d eh perfeito\n", X);
        } else {
            printf("%d eh perfeito\n", X);
        }
    }
    
    return 0;
}
