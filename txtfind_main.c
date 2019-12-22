#include <stdio.h>
#include "txtfind.h"

int main() {
    char command;
    char text[WORD];
    int i = 0;
    char compare1 = ' ';
    char compare2 = '\n';
    while ((command = getc(stdin)) != compare1) {
        text[i++] = command;
    }
    text[i] = '\0';
    char key;
    while ((command = getc(stdin)) != compare2) {
        key = command;
    }
    if (key == 'a') {
        print_lines(text);
    }
    if (key == 'b') {
        print_similar_words(text);
    }
    if (key != 'a' && key != 'b') {
        printf("Wrong command inserted(Not a/b), please try again!");
    }
}
