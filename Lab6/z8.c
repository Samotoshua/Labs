#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    char *text = (char *)calloc(200, sizeof(char));
    printf("Enter text: ");
    fgets(text, 200, stdin);

    char *words = (char *)calloc(100 * 6, sizeof(char));

    int wCount = 0, lIdx = 0;
    for (int i = 0; *(text + i) != '\0' && *(text + i) != '\n'; i++) {
        if (*(text + i) >= 'a' && *(text + i) <= 'z') {
            *(words + wCount * 6 + lIdx++) = *(text + i);
        } else if (*(text + i) == ',' || *(text + i) == '.') {
            *(words + wCount * 6 + lIdx) = '\0';
            wCount++;
            lIdx = 0;
            if (*(text + i) == '.') break;
        }
    }

    printf("Reversed: \n");
    for (int w = 0; w < wCount; w++) {
        int len = strlen(words + w * 6);
        for (int i = len - 1; i >= 0; i--) printf("%c", *(words + w * 6 + i));
        printf(w < wCount - 1 ? "," : ".\n");
    }

    free(words); free(text);
    return 0;
}