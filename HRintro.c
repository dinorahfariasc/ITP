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

