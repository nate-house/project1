#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <file>\n", argv[0]);
        return 1;
    }

    FILE *fp = fopen(argv[1], "r");
    if (!fp) {
        perror("fopen");
        return 1;
    }

    int c, words = 0, lines = 0, chars = 0;
    int in_word = 0;

    while ((c = fgetc(fp)) != EOF) {
        chars++;
        if (c == '\n') lines++;
        if (c == ' ' || c == '\n' || c == '\t') {
            in_word = 0;
        } else if (!in_word) {
            in_word = 1;
            words++;
        }
    }

    fclose(fp);

    printf("%d %d %d %s\n", lines, words, chars, argv[1]);
    return 0;
}


