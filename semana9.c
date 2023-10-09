//=====================================================================================
// Processamento de Texto (Prefixos e Sufixos)


// # include <stdio.h>
// # include <string.h>

// void tirarEsp(char* str) 
// { 
//     int count = 0; 
  
//     for (int i = 0; str[i]; i++) 
//         if (str[i] != ' ') 
//             str[count++] = str[i]; 

//     str[count] = '\0'; 
// }


// char tirandoPref(char *palavra, char *prefixo){

//     int tamanhoPrefixo = strlen(prefixo);
//     int tamanhoPalavra = strlen(palavra);
//     int qntLetras = 0;
    
//     if (tamanhoPrefixo > tamanhoPalavra){
//         return '\0';
//     }
//     else{
//         // vemos letra por letra se o prefixo esta na palavra
//         for(int i = 0; i < tamanhoPrefixo; i++){
//             if(palavra[i] == prefixo[i]){
//                 qntLetras++;
//             }
//         }
//         //printf("%s\n",palavra);
//         //printf("qntLetras: %d\ntamanho prefixo: %d\n", qntLetras,tamanhoPrefixo);

//         // se a qntd de letars for igual ao tamanho do prefixo, subistiui por espacos
//         if (qntLetras == tamanhoPrefixo){
//             for(int i = 0; i < tamanhoPrefixo; i++){
//                 palavra[i] = ' ';
//             }  
//         }
//         // tirar espacos de uma string
//         tirarEsp(palavra);

//         return palavra;
//     } 
// }

// char tirandoSuf(char *palavra, char *sufixo){

//     int tamanhoSufixo = strlen(sufixo);
//     int tamanhoPalavra = strlen(palavra);
//     int qntLetras = 0;
    
//     if (tamanhoSufixo > tamanhoPalavra){
//         return '\0';
//     }
//     else{
//         // vemos letra por letra se o sufixo esta na palavra
//         for(int i = 0; i < tamanhoSufixo; i++){
//             if(palavra[tamanhoPalavra - 1 - i] == sufixo[tamanhoSufixo - 1 - i]){
//                 qntLetras++;
//             }
//         }
//         //printf("%s\n",palavra);
//         //printf("qntLetras: %d\ntamanho sufixo: %d\n", qntLetras,tamanhoSufixo);

//         // se a qntd de letras for igual ao tamanho do sufixo, subistiui por espacos
//         if (qntLetras == tamanhoSufixo){
//             for(int i = 0; i < tamanhoSufixo; i++){
//                 palavra[tamanhoPalavra - 1 - i] = ' ';
//             }  
//         }
//         // tirar espacos de uma string
//         tirarEsp(palavra);

//         return palavra;
//     } 
// }

// int main(){
    

//     int qntdPrefixos = 0;
//     int qntdSufixos = 0;

//     char prefixos[100][11];
//     char sufixos[100][11];
//     char palavra[101];
//     char original[101];


//     scanf("%d", &qntdPrefixos);
//     for(int i = 0; i < qntdPrefixos; i++){
//         scanf(" %s", prefixos[i]);
//     }

//     scanf("%d", &qntdSufixos);
//     for(int i = 0; i < qntdSufixos; i++){
//         scanf(" %s", sufixos[i]);
//     }

//     // printf("Prefixos:\n");
//     // for(int i = 0; i < qntdPrefixos; i++){
//     //     printf("%s\n", prefixos[i]);
//     // }

//     // receber as palavras

//     while (scanf("%s", palavra) != EOF && strcmp(palavra, "-1") != 0){
        
//         int count = 0;

//         for (int i = 0; i < qntdPrefixos; i++){
//             strcpy(original, palavra);
//             tirandoPref(palavra, prefixos[i]);
//             // se a palavra tiver o prefixo tiramos e printamos a palavra sem
//             if(strcmp(palavra, original) != 0){
//                 //printf("tiramos o pref: %s\n", prefixos[i]);
//                 count = 1;
                
//             } 
//         }

//         for(int i = 0; i < qntdSufixos;i++){
//             strcpy(original, palavra);
//             tirandoSuf(palavra, sufixos[i]);
//             // se a palavra tiver o sufixo tiramos e printamos a palavra sem
//             if(strcmp(palavra, original) != 0){
//                 //printf("tiramos o sufixo : %s\n", sufixos[i]);
//                 count = 1;
                
//             }
//         }
        
    
//         printf("%s\n", palavra);
        

//     }

// }
//=====================================================================================
// o imperio contra ataca 

// #include <stdio.h>
// #include <string.h>

// const char S[] =  {'0','1','2','3','4','5','6','7','8','9',
//                    'A','B','C','D','E','F','G','H','I','J',
//                    'K','L','M','N','O','P','Q','R','S','T',
//                    'U','V','W','X','Y','Z','.',',','?',' '};

// void calcularChave(int chave[], char palavraChave[], int comprimentosP[], int posicoes[]){
//     int contagem = 0, i = 0, j = 0;

//     while (contagem < 4 && i < strlen(palavraChave) - 4){
//         int n1 = ((comprimentosP[i] - posicoes[j]) + 40) % 40;
//         int n2 = ((comprimentosP[i+4] - posicoes[j+4]) + 40) % 40;

//         if (n1 == n2){
//             chave[i % 4] = n1;
//             contagem++, i++, j++;
//         } else i -= contagem, contagem = 0, j = 0, i++;
//     }

//     if(!contagem){
//         printf("Mensagem não é da Resistência!\n");
//         palavraChave[0] = '\0';
//     } else{
//         for(int i = 0; i < 4; i++){
//             printf("%i", chave[i]);
//         }
//         printf("\n");
//     }
// }

// void decifrar(char textoCifrado[], int chave[]){
//     for (int i = 0; i < strlen(textoCifrado); i++){
//         for (int j = 0; j < 40; j++){
//              if (textoCifrado[i] == S[j]) {
//                 textoCifrado[i] = S[((j-chave[i % 4]) + 40) % 40];
//                 break;
//             }
//         }
//     }
// }

// int main(){
//     char frase[] = "QUE A FORÇA ESTEJA COM VOCÊ";
//     int posicoesFrase[27] = {0};
    
//     for (int i = 0; i < strlen(frase); i++)
//         for (int j = 0; j < sizeof(S); j++)
//             if (frase[i] == S[j])
//                 posicoesFrase[i] = j;

//     char mensagem[202];
//     fgets(mensagem, sizeof(mensagem), stdin);
//     if (mensagem[strlen(mensagem)-1] == '\n')
//         mensagem[strlen(mensagem)-1] = '\0';

//     int posicoesM[200] = {0};
    
//     for (int i = 0; i < strlen(mensagem); i++)
//         for (int j = 0; j < sizeof(S); j++)
//             if (mensagem[i] == S[j])
//                 posicoesM[i] = j;

//     int chave[4] = {0};
//     calcularChave(chave, mensagem, posicoesM, posicoesFrase);
//     decifrar(mensagem, chave);

//     printf("%s", mensagem);
    
//     return 0;
// }


//=====================================================================================
// casamento de padrao otimizado
// #include <stdio.h>
// #include <string.h>

// int main() {
//     char texto[50], padrao[50];
    
//     int i, j, t = 0;
    
//     scanf("%s", texto);
//     scanf("%s", padrao);
    
//     char *res = strstr(texto, padrao);
//     int lenT = strlen(texto);
//     int lenP = strlen(padrao);
    
    
//     // vemos se tem t no padrao
//     for(i = 0; i < lenP; i++){
//         if(padrao[i] == 'T'){
//             t = 1;
//         }
//     }
    
//     // verificacao entre o padrao e o texto
//     for(i = 0; i < lenT; i++){
//         for(j = 0; j < lenP; j++){
//             if(lenT - i < lenP){
//                 i = lenT;
//                 break;
//             }
//             else if(texto[i+j] == padrao[j]){
//                 printf("%c ", texto[i+j]);
//                 if(j == lenP - 1){
//                     printf("sim\n");
//                     i = i + j;
//                 }
//             }
//             else{
//                 printf("%c não\n", texto[i+j]);
//                 if(texto[i+j] == 'T' && !t){
//                     i = i + j;
//                 }
//                 break;
//             }
//         }
//     }

//     if(res != NULL){
//         printf("Achei o padrão no índice %ld\n", res - texto);
//     }
//     else{
//         printf("Não achei o padrão\n");
//     }

//     return 0;
// }
//=====================================================================================
// uma nova esperança 
// #include <stdio.h>
// #include <string.h>

// const char S[] =
//     {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
//      'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J',
//      'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T',
//      'U', 'V', 'W', 'X', 'Y', 'Z', '.', ',', '?', ' '};

// int validaChave(const char *chave) {
//     if (strlen(chave) != 4) {
//         printf("Chave invalida!\n");
//         return 0;
//     }
//     for (int i = 0; i < 4; i++) {
//         if (chave[i] < '0' || chave[i] > '9') {
//             printf("Chave invalida!\n");
//             return 0;
//         }
//     }
//     return 1;
// }

// int validaMensagem(const char *mensagem) {
//     for (int i = 0; mensagem[i]; i++) {
//         if (!strchr(S, mensagem[i])) {
//             printf("Caractere invalido na entrada!\n");
//             return 0;
//         }
//     }
//     return 1;
// }

// void cifra(char *mensagem, const char *chave) {
//     int tamanhoChave = strlen(chave);
//     int tamanhoMensagem = strlen(mensagem);

//     for (int i = 0; i < tamanhoMensagem; i++) {
//         if (strchr(S, mensagem[i])) {
//             int indiceCaractere = strchr(S, mensagem[i]) - S;
//             int digitoChave = chave[i % tamanhoChave] - '0';
//             int novoIndice = (indiceCaractere + digitoChave) % sizeof(S);
//             mensagem[i] = S[novoIndice];
//         }
//     }
// }

// int main() {
//     char chave[5];
//     char mensagem[201];
    
//     scanf("%s", chave);

//     if (!validaChave(chave)) {
//         return 1;
//     }
    
//     scanf(" %[^\n]", mensagem);

//     if (!validaMensagem(mensagem)) {
//         return 1;
//     }

//     cifra(mensagem, chave);
//     printf("%s\n", mensagem);

//     return 0;
// }
//=====================================================================================