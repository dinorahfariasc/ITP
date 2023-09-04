# include <stdio.h>

int main(){
    
    int qnt, herois, monstros;
    
    scanf("%d %d %d\n",&qnt,&herois,&monstros);
    
    int forca = (qnt*herois);
    
    if(herois == 5){
        printf("Heróis vencerão!");
    }
    else if(herois > monstros){
        printf("Heróis vencerão!");
    }
    else if(herois == monstros){
        if(qnt == 3){
        printf("Heróis vencerão!");
        }
        else{
            printf("Melhor chamar Saitama!");
        }
    }
    else if(herois < monstros){
        printf("Melhor chamar Saitama!");
    }
    
}