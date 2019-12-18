//
// Created by nivtal9 on 17.12.2019.
//

#ifndef FIND_MAIN_TXTFIND_H
#define FIND_MAIN_TXTFIND_H
#define LINE 256
#define WORD 30
#define TOTALLINE 250
int getLine(char s[]);
int getWord(char w[]);
int substring(char * str1,char * str2);
int similar(char *s,char*t,int n);
void print_similar_words(char * str);
void print_lines(char * str);
#endif //FIND_MAIN_TXTFIND_H
