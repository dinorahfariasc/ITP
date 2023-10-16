
// planeta hostil
// #include <stdio.h>

// int main(){
//     int n,m;
    
//     scanf("%d %d", &n, &m);
    
// 	char planeta[n][m];
	
// 	char til = '~';
// 	char xis = 'X';
// 	char acento = '^';
// 	char asterisco = '*';
// 	char ponto = '.';
    
//     int c1 = 0;
//     int c2 = 0;
//     int c3 = 0;
//     int c4 = 0;
//     int c5 = 0;
    
		
// 	int i, j;

// 	for(i=0; i<n;i++){
// 		for(j=0;j<m;j++){
// 		    scanf(" %c", &planeta[i][j]);
// 		    if (planeta[i][j] == til){
// 		        c1++;
// 		    }
// 		    else if(planeta[i][j] == xis){
// 		        c2++;
// 		    }
// 		    else if(planeta[i][j] == acento){
// 		        c3++;
// 		    }
// 		    else if(planeta[i][j] == asterisco){
// 		        c4++;
// 		    }
// 		    else{
// 		        c5++;
// 		    }
// 		}
// 	}
	

//     if((double)c1 / (n*m) >= 0.5 && (double)c4 / (n*m) >= 0.2 && (double)c2 == 0){
//         printf("Planeta Classe M");
//     }
//     else if((double)c2 >= 1){
//         printf("Planeta Hostil");
//     }
//     else if((double)c1 / (n*m) >= 0.85){
//         printf("Planeta Aquático");
//     }
//     else if((double)c3 / (n*m) >= 0.6){
//         printf("Planeta Desértico");
//     }
//     else if((double)c4 / (n*m) >= 0.65){
//         printf("Planeta Selvagem");
//     }
//     else{
//         printf("Planeta Inóspito");
//     }
	
// 	return 0;
// }
//===============================================================================
// jogo da velha 

// #include <stdio.h>
// #include <string.h>

// int vitoria(char tabuleiro[3][3], char simb){
//     for(int i = 0; i < 3; i++){
//         if(tabuleiro[i][0] == simb && tabuleiro[i][1] == simb && tabuleiro[i][2] == simb){
//             return 1;
//         }
//         if(tabuleiro[0][i] == simb && tabuleiro[1][i] == simb && tabuleiro[2][i] == simb){
//             return 1;
//         }
//     }
//     if(tabuleiro[0][0] == simb && tabuleiro[1][1] == simb && tabuleiro[2][2] == simb){
//         return 1;
//     }
//     if(tabuleiro[0][2] == simb && tabuleiro[1][1] == simb && tabuleiro[2][0] == simb){
//         return 1;
//     }
//     return 0;
// }

// int main(){
//     char tabuleiro[3][3];
    
//     int i,j;
    
//     for(i=0;i<3;i++){
//         for(j=0;j<3;j++){
//             scanf(" %c", &tabuleiro[i][j]);
//         }
//     }
    
    
//     int N;
//     scanf("%d", &N); 
    
//     char saida[500];
//     int X;
//     int Y;
//     char simb;
    
//     for(i = 0; i < N; i++){
//        scanf("%d %d %c", &X, &Y, &simb);
//        X--;
//        Y--;
       
//        if(!(X >= 0  && X < 3 && Y >= 0 && Y < 3 && tabuleiro[X][Y] == '.')){
//            strcat(saida, "Jogada inválida!\n");
//        }
//        else{
//            tabuleiro[X][Y] = simb;
//            if(vitoria(tabuleiro,simb)){
//                strcat(saida, "Boa jogada, vai vencer!\n");
//                tabuleiro[X][Y] = '.';
//            }
//            else{
//                strcat(saida, "Continua o jogo.\n");
//                tabuleiro[X][Y] = '.';
//            }
//        }
//     }
//     printf("%s", saida);
//     return 0;
// }
//==================================================
// piramide (reeutilizei a logica de uma questao parecida que resolvi no hackerrank)
// #include <stdio.h>

// int main() {
//     int tamanho;

//     scanf("%d", &tamanho);

//     for (int linha = 0; linha < tamanho; linha++) {
//         for (int coluna = 0; coluna < tamanho; coluna++) {
            
            
//             int minDistance = linha < coluna ? linha : coluna; // 
//             minDistance = minDistance < tamanho - linha ? minDistance : tamanho - linha - 1;
//             minDistance = minDistance < tamanho - coluna - 1 ? minDistance : tamanho - coluna - 1;
    
            
//             int numero = 1 + minDistance;

//             printf("%d ", numero);
//         }
//         printf("\n");
//     }

//     return 0;
// }
//==================================================
#include <stdio.h>
#include <string.h>

void removeSufixo(char *palavra, const char *sufixo) {
    int palavraLen = strlen(palavra);
    int sufixoLen = strlen(sufixo);

    if (palavraLen < sufixoLen) {
        return;
    }

    int i = palavraLen - 1;
    int j = sufixoLen - 1;

    while (j >= 0 && palavra[i] == sufixo[j]) {
        i--;
        j--;
    }

    if (j < 0) {
        palavra[i + 1] = '\0'; 
    }
}

void removePrefixo(char *palavra, const char *prefixo) {
    int palavraLen = strlen(palavra);
    int prefixoLen = strlen(prefixo);

    if (palavraLen < prefixoLen) {
        return;
    }

    int i = 0;
    int j = 0;

    while (j < prefixoLen && palavra[i] == prefixo[j]) {
        i++;
        j++;
    }

    if (j == prefixoLen) {
        strcpy(palavra, palavra + i);
    }
}

int main() {
    int numPrefixos, numSufixos;
    char prefixos[100][11];
    char sufixos[100][11];
    char palavra[101];

    scanf("%d", &numPrefixos);
    for (int i = 0; i < numPrefixos; i++) {
        scanf("%s", prefixos[i]);
    }

    scanf("%d", &numSufixos);
    for (int i = 0; i < numSufixos; i++) {
        scanf("%s", sufixos[i]);
    }

    while (scanf("%s", palavra) != EOF && strcmp(palavra, "-1") != 0) {
        int removeu = 0;

        for (int i = 0; i < numSufixos; i++) {
            removeSufixo(palavra, sufixos[i]);
            if (strlen(palavra) == 0) {
                removeu = 1;
                break;
            }
        }

        if (!removeu) {
            for (int i = 0; i < numPrefixos; i++) {
                removePrefixo(palavra, prefixos[i]);
                if (strlen(palavra) == 0) {
                    break;
                }
            }
            
        if (strlen(palavra) > 0) {
            printf("%s\n", palavra);
        }
    }

    }
    
    return 0;
}