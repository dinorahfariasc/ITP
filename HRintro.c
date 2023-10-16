#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

// int main() 
// {
//     // read a single character, a word and a whole sentence
//     char ch;
//     char s[100], sen[100];
    
//     scanf("%c\n",&ch);
//     scanf("%s\n",&s);
//     scanf("%[^\n]%*c", &sen);
    
//     printf("%c\n",ch);
//     printf("%s\n",s);
//     printf("%s\n",sen);
    
       
//     return 0;
// }
// ====================================================================================================
// int main()
// {
//     // read two integers and two floating point numbers and print the sum and difference of each pair
// 	int int1,int2;
//     float flo1, flo2;
    
//     scanf("%d %d",&int1, &int2);
//     scanf("%f %f", &flo1, &flo2);
    
//     int sumint = int1 + int2;
//     int difint = int1 - int2;
//     float sumflo = flo1 + flo2;
//     float difflo = flo1 - flo2;
    
//     printf("%d %d\n",sumint, difint);
//     printf("%.1f %.1f\n", sumflo, difflo);
    
//     return 0;
// }
//=====================================================================================================
// #include <stdio.h>
// // creates a function that returns the max of four numbers

// int max_of_four(int a, int b, int c, int d){
//         int max = 0;
//         if(a > b && a > c && a > d){
//             max = a;
//         }
//         if(b > c && b > d && b > a){
//             max = b;
//         }
//         if(c > d && c > a && c > b){
//             max = c;
//         }
//         if(d > a && d > b && d > c){
//             max = d;
//         }

//         return max;
        
//     }

// int main() {
//     int a, b, c, d;
    
//     scanf("%d %d %d %d", &a, &b, &c, &d);
//     int ans = max_of_four(a, b, c, d);
//     printf("%d", ans);
    
//     return 0;
// }
//=====================================================================================================
// #include <stdio.h>

// // creates a function with the poiters that return a sum of two numbers and the absolute difference of two numbers
// void update(int *a,int *b) {
//     int a2 = *a + *b;
//     int b2 = *a - *b;
//     b2 = abs(b2);
//     *a = a2;
//     *b = b2; 
// }

// int main() {
//     int a, b;
//     int *pa = &a, *pb = &b;
    
//     scanf("%d %d", &a, &b);
//     update(pa, pb);
//     printf("%d\n%d", a, b);

//     return 0;
// }

//=====================================================================================================
// Conditional Statements in C
// int main(){
    
//      if(n == 1){
//         printf("one");
//     }
//     if(n == 2){
//         printf("two");
//     }
//     if(n == 3){
//         printf("three");
//     }
//     if(n == 4){
//         printf("four");
//     }
//     if(n == 5){
//         printf("five");
//     }
//     if(n == 6){
//         printf("six");
//     }
//     if(n == 7){
//         printf("seven");
//     }
//     if(n == 8){
//         printf("eight");
//     }
//     if(n == 9){
//         printf("nine");
//     }
//     if(n > 9){
//         printf("Greater than 9");
//     }
// }
//=====================================================================================================

// for loop in c

// int main() 
// {
//     int a, b;
//     scanf("%d\n%d", &a, &b);
    
//   	for(int i = a; i <= b; i++){
//           if (i > 9 && i%2 == 0 ){
//               printf("even");
//           }
//           else if( i > 9 && i%2 != 0){
//               printf("odd");
//           }
//           switch (i) {
//             case 1 :
//             printf("one");
//             break;
            
//             case 2:
//             printf("two");
//             break;
            
//             case 3:
//             printf("three");
//             break;
            
//             case 4:
//             printf("four");
//             break;
            
//             case 5:
//             printf("five");
//             break;
            
//             case 6:
//             printf("six");
//             break;
            
//             case 7:
//             printf("seven");
//             break;
            
//             case 8:
//             printf("eight");
//             break;
            
//             case 9:
//             printf("nine");
//             break;
          
//           }
          
//       }

//     return 0;
// }
//=====================================================================================================
// Sum of Digits of a Five Digit Number

// int main() {
	
//     int n;
//     scanf("%d", &n);
    
//     int sum = 0;
//     while(n !=0){
//         sum += n % 10;
//         n = n/10; 
//         //printf("%d\n",sum);       
//     }
//     printf("%d",sum);
    
    
//     return 0;
// }
//=====================================================================================================

// Bitwise Operators

// void calculate_the_maximum(int n, int k) {
//     int and = n & k;
//     printf("%d",and);
// }

// int main() {
//     int n, k;
  
//     scanf("%d %d", &n, &k);
//     calculate_the_maximum(n, k);
 
//     return 0;
// }
//=====================================================================================================
// printing pattern using loops

// int main() 
// {
//     int n;
//     scanf("%d", &n);

//     int i = n;
//     int r = 1;

//     for(int  linha = 1;linha<= n +(n-1);linha++){
//         for(int coluna =1;coluna <= n + (n-1);coluna++){
            
//            if(linha == 1 || linha == n + (n-1)){
//                 printf("%d ",n);
//             }
//             else if (coluna == 1 || coluna == n + (n-1)){
//                 printf("%d ",n);
//             }

//             else if (linha == 2 || linha == n + (n-2)){
//                 printf("%d ",n-1);
//             }
//             else if (coluna == 2 || coluna == n + (n-2)){
//                 printf("%d ",n-1);
//             }
//             else{
//                 printf("x ");
//             }
//         }

//         if (i >= 1 && r != n){
//             i--;
//             r++;
//         }
//         else{
//             i++;
//         }
        

//         printf("\n");

//     }
//     return 0;

// }

            

//=====================================================================================================


//=====================================================================================================

// jogo da velha

// #include <stdio.h>

// int main(){

//     char velha[3][3];

//     for(int linha = 0; linha < 3; linha++){
//         scanf("%c%c%c", &velha[linha][0], &velha[linha][1], &velha[linha][2]);
//     } 
    
//     int testes;
//     scanf("%d", &testes);
    

    

//     return 0;
// }
//======================================================
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

//=====================================================================================================
// for(int i = 0; i < testes; i++){
//         printf("foi");
//         int linha, coluna;
//         char jogador;

//         scanf("%d %d %c", &linha, &coluna,&jogador);

//         if (velha[linha][coluna] == '.'){
//             velha[linha][coluna] = jogador;
//         }
//         else{
//             printf("Jogada invalida!\n");
//         }
        
//     }

 
//==========================================

// fronteira final

// #include <stdio.h>

// int main(){

//     int tamLinhas, tamColunas;
//     int total = 0;

//     scanf("%d %d", &tamLinhas, &tamColunas);

//     char matriz[tamLinhas][tamColunas];

//     for(int i = 0; i < tamLinhas; i++){
//         for(int j = 0; j < tamColunas; j++){
//             scanf("%c", &matriz[i][j]);
//             total += 1;
//         }
//     }

//     char letras[5] = {'~', 'X','^','*','.'};
//     int resultado[5] = {0,0,0,0,0};

//     int cont = 0;

//     for (int k = 0; k < 5; k++){
//         for(int i = 0; i < tamLinhas; i++){
//             for(int j = 0; j < tamColunas; j++){
//                 if (matriz[i][j] == letras[k]){
//                     resultado[k] += 1;
//                 }
//             }
//         }
//     }


//     for(int j = 0; j < 5; j++){
//         printf("%d ", resultado[j]);
//     }

    

//     printf("\n%d\n", total);
    
//     if (resultado[0] >= (total * 0.5) && resultado[3] >= (total * 0.2) && resultado[1] == (0)){
//         printf("Planeta Classe M\n");
//     }
//     else if(resultado[1] >= 1){
//         printf("Planeta Hostil\n");
//     }
//     else if(resultado[0] >= (total * 0.85)){
//         printf("Planeta Aquático\n");
//     }
//     else if(resultado[2] >= (total * 0.6)){
//         printf("Planeta Deserto\n");
//     }
    
// }

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