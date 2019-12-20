#include <stdio.h>
#include "txtfind.h"

int main() {
    char c;
    char w[WORD];
    int i = 0;
    char compare1 = ' ';
    char compare2 = '\n';
    while ((c = getc(stdin)) != compare1) {
        w[i++] = c;
    }
    w[i] = '\0';
    char key;
    while ((c = getc(stdin)) != compare2) {
        key = c;
    }
    if (key == 'a') {
        print_lines(w);
    }
    if (key == 'b') {
        print_similar_words(w);
    }
    if (key != 'a' && key != 'b') {
        printf("Wrong command inserted(Not a/b), please try again!");
    }
}
