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
int main() 
{

    int n;
    scanf("%d", &n);
    

    for(int  i = 1;i<= n +(n-1);i++){
        for(int c =1;c <= n + (n-1);c++){

           if(i == 1 || i == n + (n-1)){
                printf("%d ",n);
            }
            else if (c == 1 || c == n + (n-1)){
                printf("%d ",n);
            }
            else{
                printf("x ");
            }
        }
        printf("\n");
        
    }
    return 0;

}

//  else if(c== 2 || i ==2){
//                 printf("%d ",n-1);
//             }