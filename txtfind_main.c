#include <stdio.h>
#include "txtfind.h"

int main() {
    char word[WORD];
    char command;
    getWord(word);
    scanf(" %c",&command);
    if(command=='a'){
        print_lines(word);
    }
    if(command=='b'){
        print_similar_words(word);
    }
    if(command!='a'&&command!='b'){
        printf("Wrong input inserted! Please try again.");
    }
}
