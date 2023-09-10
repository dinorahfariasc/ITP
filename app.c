//Cálculo de média aritmética e ponderada
// # include <stdio.h>

// float calculaMedia(char tipo, float n1,float n2,float n3){
//     if (tipo == 'A'){
//         return ((n1+n2+n3)/3);
//     }
//     else if (tipo == 'P'){
//         return ((n1*4+n2*5+n3*6)/15);
//     }
// }


// int main(){
//     float n1,n2,n3;
//     char tipo;

//     scanf("%c %f %f %f",&tipo,&n1,&n2,&n3);
//     printf("Media %.2f",calculaMedia(tipo,n1,n2,n3));
    
// }
//=======================================================
// Campeonato de skate
// #include <stdio.h>

// int melhorRodada(int skt[9]){
//     int a, maior, menor;
//     int notaskt[3];
//     int n1 = notaskt[0];
//     int n2 = notaskt[1];
//     int n3 = notaskt[2];

//     for (int i = 3; i<=9; i = i + 3){

//         a = skt[i-3];
//         maior = skt[i-3];
//         menor = skt[i-3];

//         for(int x = i - 3 ; x < i; x++){
//             if(maior > skt[x] && skt[x] > menor){
//                 a = skt[x];
//             }
//             else if (skt[x] > maior){
//                 a = maior;
//                 maior = skt[x];
//             }
//             else if (skt[x] < menor){
//                 a = menor;
//                 menor = skt[x];
//             }
//             else if(skt[x] == maior || skt[x] == menor){
//                 a = skt[x];
//             } 
//             //printf("***maior: %d menor: %d nota: %d\n",maior,menor,a);
//         }
//         if (i == 3){
//             notaskt[0] = a;
//         }
//         if (i == 6){
//             notaskt[1] = a;
//         }
//         if (i ==9){
//             notaskt[2] = a;
//         }     
//     }

//     n1 = notaskt[0];
//     n2 = notaskt[1];
//     n3 = notaskt[2];

//     if ((n1 >= n2 && n1 <= n3) || (n1 <= n2 && n1 >= n3)) {
//         return n1;
//     } else if ((n2 >= n1 && n2 <= n3) || (n2 <= n1 && n2 >= n3)) {
//         return n2;
//     } else {
//         return n3;
//     }
// }

// int main(){

//     int notas[18];
//     int skt1[9];
//     int skt2[9];

//     for (int i = 0; i < 18; i++){
//         scanf("%d",&notas[i]);
//     }

//     for (int i = 0; i < 9; i++){
//         skt1[i] = notas[i];
//         skt2[i] = notas[i+9]; 
//     }

//     // chamar funcao melhorRodada
//     //printf("melhor rodada skt1: %d\n",melhorRodada(skt1));
//     //printf("melhor rodada skt2: %d\n",melhorRodada(skt2));

//     if (melhorRodada(skt1) > melhorRodada(skt2)){
//         printf("A");
//     }
//     else if (melhorRodada(skt1) < melhorRodada(skt2)){
//         printf("B");
//     }
//     else{
//         printf("empate");
//     }

// }
//=======================================================
// numeros colegas 
// #include <stdio.h>
// #include <stdlib.h>

// int divisores(int n){
//     int soma = 0;
//     for (int i = 1; i <= n; i++){
//         if (n%i == 0 && n != i){
//             soma += i;
//         }
//     }
//     return soma;
// }

// int colegas(int n1, int n2){
//     int res1 = abs(divisores(n1) - n2);
//     int res2 = abs(divisores(n2) - n1);
//     if ( res1<= 2 && res2<= 2){
//         printf("S");
//     }
//     else{
//        printf("N");
//     }
// }

// int main(){
//     int n1,n2;
//     scanf("%d %d",&n1,&n2);
//     colegas(n1,n2);


// }
//=======================================================


 