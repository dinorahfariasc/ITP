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
#include <stdio.h>
int melhorRodada(int skt[9]){
    int a, maior, menor;
    int notaskt[3];

    for (int i = 3; i<=9; i = i + 3){

        a = skt[i-3];
        maior = skt[i-3];
        menor = skt[i-3];

        for(int x = i - 3 ; x < i; x++){
            if(maior > skt[x] && skt[x] > menor){
                a = skt[x];
            }

            if (skt[x] > maior){
                maior = skt[x];
            }

            if (skt[x] < menor){
                menor = skt[x];
            }
            
            printf("***maior: %d menor: %d nota: %d\n",maior,menor,a);
        }

        if (i == 3){
            notaskt[0] = a;
        }
        if (i == 6){
            notaskt[1] = a;
        }
        if (i ==9){
            notaskt[2] = a;
        }
        
    }

    int final1 = notaskt[0];
    maior = notaskt[0];
    menor = notaskt[0];


    for (int i = 0; i < 3; i++){
        if (notaskt[i] > maior){
            maior = notaskt[i];
        }
        if (notaskt[i] < menor){
            menor = notaskt[i];
            
        }
       
    }

    for (int i = 0; i < 3; i++) {
        if (notaskt[i] != maior && notaskt[i] != menor) {
            final1 = notaskt[i];
            break;
        }
    }

    //printf("cada rodada 1:%d 2:%d 3:%d \n",notaskt[0],notaskt[1],notaskt[2]);

    return final1;
}




int main(){

    int notas[18];
    int skt1[9];
    int skt2[9];


    for (int i = 0; i < 18; i++){
        scanf("%d",&notas[i]);
    }

    for (int i = 0; i < 9; i++){
        skt1[i] = notas[i];
        skt2[i] = notas[i+9]; 
    }

    // chamar funcao melhorRodada
    printf("melhor rodada skt1: %d\n",melhorRodada(skt1));
    printf("melhor rodada skt2: %d\n",melhorRodada(skt2));

    if (melhorRodada(skt1) > melhorRodada(skt2)){
        printf("A");
    }
    else if (melhorRodada(skt1) < melhorRodada(skt2)){
        printf("B");
    }
    else{
        printf("empate");
    }

}
   


 