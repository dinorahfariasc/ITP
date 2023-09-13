# include<stdio.h>

int lendoVet(int tam){

    int vet[tam];
    int count = tam;
    int dif = 0;

    for(int i =0; i < tam; i++){
        scanf("%d",&vet[i]);
    }

    for(int n = 1 ; n < tam; n++){
        dif = vet[n] - vet[n-1];

        //printf("%d %d, %d\n",vet[n],vet[n-1],n);

        if(abs(dif) % 2 != 0){
            count -= 1;
        }
    }
    //printf("%d\n", count);

    count == tam ? printf("Legal") : printf("Chato"); // operador ternario
    
}

int main(){
    int tamanho;
    scanf("%d",&tamanho);

    lendoVet(tamanho);
}