#include <stdio.h>
#include <string.h>

int main() {
    char text[100], subword[50], *word;

    printf("Enter the subword: ");
    fgets(subword, sizeof(subword), stdin);
    
    printf("Enter the text: ");
    fgets(text, sizeof(text), stdin);

    // Remove newline characters from the end of the strings
    text[strcspn(text, "\n")] = 0;
    subword[strcspn(subword, "\n")] = 0;

    word = strtok(text, " ");
    while(word != NULL) {
        if(strstr(word, subword) != NULL) {
            printf("%s\n", strstr(word, subword));
        }
        word = strtok(NULL, " ");
    }

    return 0;
}