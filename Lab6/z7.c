#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    char *text = (char *)calloc(200, sizeof(char));
    printf("Enter text: ");
    fgets(text, 200, stdin);

    char (*words)[6] = calloc(100, sizeof(*words));

    int wCount = 0, lIdx = 0;
    for (int i = 0; text[i] != '\0' && text[i] != '\n'; i++) {
        if (text[i] >= 'a' && text[i] <= 'z') {
            words[wCount][lIdx++] = text[i];
        } else if (text[i] == ',' || text[i] == '.') {
            words[wCount++][lIdx] = '\0';
            lIdx = 0;
            if (text[i] == '.') break;
        }
    }

    for (int w = 0; w < wCount; w++) {
        for (int i = strlen(words[w]) - 1; i >= 0; i--) {
            printf("%c", words[w][i]);
        }
        printf(w < wCount - 1 ? "," : ".\n");
    }

    free(words); 
    free(text);
    
    return 0;
}