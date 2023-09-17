// vetor chato ou legal
// # include<stdio.h>

// int lendoVet(int tam){

//     int vet[tam];
//     int count = tam;
//     int dif = 0;

//     for(int i =0; i < tam; i++){
//         scanf("%d",&vet[i]);
//     }

//     for(int n = 1 ; n < tam; n++){
//         dif = vet[n] - vet[n-1];

//         //printf("%d %d, %d\n",vet[n],vet[n-1],n);

//         if(abs(dif) % 2 != 0){
//             count -= 1;
//         }
//     }
//     //printf("%d\n", count);

//     count == tam ? printf("Legal") : printf("Chato"); // operador ternario
    
// }

// int main(){
//     int tamanho;
//     scanf("%d",&tamanho);

//     lendoVet(tamanho);
// }
//====================================================================
// diferença simetrica
// # include <stdio.h>

// int main(){
    
//     int tam1;
//     int tam2;
//     int num;
    
//     scanf("%d %d", &tam1, &tam2);

//     int conj1[tam1];
//     int conj2[tam2];

//     int tudo[tam1 + tam2];
    
//     for(int i = 0; i <= tam1;i++){
//         scanf("%d ", &num);
//         conj1[i] = num;
//         tudo[i] = num;
//     }

//     for (int i = 0; i <= tam2; i++){
//         scanf("%d ",&num);
//         conj2[i] = num;
//         tudo[i+tam1] = num;
//     }

//     for(int i = 0 ; i < tam1+tam2; i++){

//         printf("%d ", tudo[i]);
//     }
    
    
    
    
// }
//=================================================
// notas alunos
// # include <stdio.h>


// int main(){

//     int qnt;
//     int num;
//     float media;
//     char hifen;

//     scanf("%d",&qnt);

//     float medias[qnt];
//     float chamada[qnt];

//     // colocar a chamada no 0 e a nota no 1

//     for(int x = 0; x < qnt;x++){

//         scanf("%d %c %f",&num, &hifen, &media);
        
//         medias[x] = media;
//         chamada[x] = num;
//     }

//     // ver quantas notas tem em cada situacao
//     int count = 0;
//     int count2 = 0;
//     int count3 = 0;

//     for (int i = 0; i < qnt; i++)
//     {
//         if(medias[i] >= 7){
//             count +=1;
//         }
//         if (medias[i] < 7 && medias[i] >= 5){
//             count2 += 1;
//         }
//         if (medias[i] < 5){
//             count3 +=1;
//         }
//     }

    
//     printf("Aprovados: ");
//     for(int i =0;i <qnt; i++){
//         int nu =0;

//         if(medias[i] >= 7){
//             nu = chamada[i];

//             printf("%d (%.1f)",nu,medias[i]);
//             count -= 1;  

//             if (count == 0)
//             {
//                 break;
//             }
//             else{
//                 printf(", ");
//             }
//         }
        
//     }

//     printf("\nRecuperacao: ");
//     for(int i =0;i <qnt; i++){
//         int nu2 =0;

//         if(medias[i] < 7 && medias[i] >= 5){
//             nu2 = chamada[i];

//             printf("%d (%.1f)",nu2,medias[i]);
//             count2 -= 1;  

//             if (count2 == 0)
//             {
//                 break;
//             }
//             else{
//                 printf(", ");
//             }
//         }
        
//     }

//     printf("\nReprovados: ");
//     for(int i =0;i <qnt; i++){
//         int nu3 =0;

//         if(medias[i] < 5){
//             nu3 = chamada[i];

//             printf("%d (%.1f)",nu3,medias[i]); 
//             count3 -= 1; 

//             if (count3 == 0)
//             {
//                 break;
//             }
//             else{
//                 printf(", ");
//             }
//         }
        
//     }

// }
//=============================================================

//buble sort
// # include <stdio.h>

// void troca(int *x, int *y) {
//     int temp = *x;
//     *x = *y;
//     *y = temp;
// }

// void bubbleSort(int arr[], int n) {
//     int i, j;
//     for (i = 0; i < n - 1; i++) {
//         for (j = 0; j < n - i - 1; j++) {
//             if (arr[j] > arr[j + 1]) {
//                 troca(&arr[j], &arr[j + 1]);
//             }
//         }

//         // Imprime o vetor após cada passo
        
//         for (int k = 0; k < n; k++) {
//             printf("%d ", arr[k]);
//         }
//         printf("\n");
//     }
// }

// int main() {
//     int n;
   
//     scanf("%d", &n);

//     int arr[n];
    
//     for (int i = 0; i < n; i++) {
//         scanf("%d", &arr[i]);
//         printf("%d ",arr[i]);
//     }
//     printf("\n");

//     bubbleSort(arr, n);

//     return 0;
// }

//===========================================================================

// diferença conjuntos

// # include <stdio.h>

// void conjuntoSimetrico(int n, int m, int conj1[50], int conj2[50], int num){
    
//     for(int i = 0;i < n;i++){
//         int num;
//         scanf("%d ",&num);
//         conj1[num] = 1;
//     }

//     for(int i = 0;i < m;i++){
//         int num;
//         scanf("%d ",&num);
//         conj2[num] = 1;
//     }
// }

// int main(){
//     int n;
//     int m;

//     scanf("%d %d ", &n, &m);

//     int conj1[50] = {0};
//     int conj2[50] = {0};

//     int num;

//     conjuntoSimetrico(n,m,conj1,conj2,num);

//     for (int i = 0; i < 50; i++){
//         if((conj1[i] || conj2[i]) && !(conj1[i] && conj2[i])){
//             printf("%d ",i);
//         }
//     }
//     printf("\n");

// }