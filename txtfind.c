//
// Created by nivtal9 on 17.12.2019.
//
#include <stdbool.h>
#include "stdio.h"
#include "txtfind.h"
#include "string.h"
int lines250=0;
int getLine(char s[]){
    if(lines250>250){
        return -1;
    }
    int count=0;
    char ch=*(s);
    s[0]=ch;
    for (int i = 0; i <=LINE+1; i++) {
        if(s[i]!='\n'&&s[i]!='\0') {
            count++;
            ch=*(count+s);
            s[count]=ch;
            if(count>LINE){
                return -1;
            }
        }
        else{
            s[count]='\0';
            lines250++;
            break;
        }
    }
    return count;
}
int getWord(char w[]){
    if(lines250>250){
        return -1;
    }
    int count=0;
    char ch=*(w);
    w[0]=ch;
    for (int i = 0; i <=WORD+1; i++) {
        if(w[i]!='\n'&&w[i]!='\0'&&w[i]!=' '&&w[i]!='\t') {
            count++;
            ch=*(count+w);
            w[count]=ch;
            if(count>WORD){
                return -1;
            }
        }
        else{
            w[count]='\0';
            if(w[i]=='\n'){
                lines250++;
            }
            break;
        }
    }
    return count;
}
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
    int TotalChars=strlen(str);
    int TotalLinesCounter=0;
    char nextWord[WORD];
    strcpy(nextWord,str);
    int temp=getWord(nextWord);
    char nextText[LINE*TOTALLINE];
    strcpy(nextText,str);
    temp=0;
    int temp2=getLine(nextText);
    while(TotalChars>temp+temp2&&TotalLinesCounter<TOTALLINE){
        TotalLinesCounter++;
        temp+=temp2+1;
        str=str+temp2+1;
        strcpy(nextText,str);
        temp2=getLine(nextText);
        char WordsInLine[LINE];
        int WordsInLineCount=0;
        while(WordsInLineCount<temp2){
            strcpy(WordsInLine,nextText+WordsInLineCount);
            WordsInLineCount+=getWord(WordsInLine)+1;
            if(similar(WordsInLine,nextWord,1)==1){
                printf("%s\n",WordsInLine);
                break;
            }
        }
        strcpy(WordsInLine,nextText);
    }

}
void print_lines(char * str){
    int TotalChars=strlen(str);
    int TotalLinesCounter=0;
    char nextWord[WORD];
    strcpy(nextWord,str);
    int temp=getWord(nextWord);
    char nextText[LINE*TOTALLINE];
    strcpy(nextText,str);
    temp=0;
    int temp2=getLine(nextText);
    while(TotalChars>temp+temp2&&TotalLinesCounter<TOTALLINE){
        TotalLinesCounter++;
        temp+=temp2+1;
        str=str+temp2+1;
        strcpy(nextText,str);
        temp2=getLine(nextText);
        char WordsInLine[LINE];
        int WordsInLineCount=0;
        while(WordsInLineCount<temp2){
            strcpy(WordsInLine,nextText+WordsInLineCount);
            WordsInLineCount+=getWord(WordsInLine)+1;
            if(similar(WordsInLine,nextWord,1)==1){
                printf("%s\n",nextText);
                break;
            }
        }
        strcpy(WordsInLine,nextText);
    }
}