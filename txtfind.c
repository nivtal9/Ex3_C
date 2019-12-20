//
// Created by nivtal9 on 17.12.2019.
//
#include <stdbool.h>
#include "stdio.h"
#include "txtfind.h"
#include "string.h"
int substring(char * str1,char * str2){
    if(strstr(str1, str2) != NULL){
        return 1;
    }
    return 0;
}
int similar(char *s,char*t,int n){
    int count=0;int ans=1;bool flag=true;
    int diff=strlen(s)-strlen(t);
    if(diff>n||diff<0) {
        ans=0;
        flag=false;
    }
    while(*t!='\0'&&flag){
        if(*t==*s){
            t++;
            s++;
        } else{
            count++;
            s++;
            if(n<count){
                ans=0;
            }
        }
    }
    return ans;
}
void print_similar_words(char * str){
    int i=  0;
    char similar_word[WORD] =  {{0}};
    char c=  NULL;
    while ( (c = getc ( stdin )!=EOF ) ){
        if(  c == ' '  ||  c == '\n'  ||  c == '\t'  ){
            similar_word[ i ]  =  '\0';
            i =  0 ;
            if (similar( similar_word,  str,  1) ==  1){
                printf( " %s\n",  similar_word);
            }
        }
        else
            similar_word[ i++ ] =  c;
    }

}
void print_lines(char * str){
    char similar_line [LINE] = {{0}};
    char c=  NULL;
    int i =  0;
    while ( (c = getc(stdin)) !=  EOF){
        i =  1;
        similar_line[ 0 ] =  c;
        while ('\n'!=(c = getc(stdin)) && 0<c){

            similar_line[ i++ ] =  c;
        }
        similar_line[ i ] = '\n';
        if (substring (similar_line, str) ==  1) {
            printf(" %s", similar_line);
            int j = 0;
            while (j < LINE) {
                similar_line[j++] = 0;
            }
        }
    }
}