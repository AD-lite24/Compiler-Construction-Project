#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../../include/datastructures/trie.h"
#include "../../include/tokens/tokens.h"

#define BUFFER_SIZE 1024

char* buf1;
char* buf2;
char* lexemeBegin;
char* forward;
FILE* fp;
int state;
int lineNumber;
Token tk;
char* tokensArr[]={
    "TK_NULL", 
    "TK_ASSIGNOP", 
    "TK_COMMENT", 
    "TK_FIELDID", 
    "TK_ID", 
    "TK_NUM", 
    "TK_RNUM", 
    "TK_FUNID", 
    "TK_RUID", 
    "TK_WITH", 
    "TK_PARAMETERS", 
    "TK_END", 
    "TK_WHILE", 
    "TK_UNION", 
    "TK_ENDUNION", 
    "TK_DEFINETYPE", 
    "TK_AS", 
    "TK_TYPE", 
    "TK_MAIN", 
    "TK_GLOBAL", 
    "TK_PARAMETER", 
    "TK_LIST", 
    "TK_SQL", 
    "TK_SQR", 
    "TK_INPUT", 
    "TK_OUTPUT", 
    "TK_INT", 
    "TK_REAL", 
    "TK_COMMA",
    "TK_SEM", 
    "TK_COLON", 
    "TK_DOT", 
    "TK_ENDWHILE", 
    "TK_OP", 
    "TK_CL", 
    "TK_IF", 
    "TK_THEN", 
    "TK_ENDIF", 
    "TK_READ", 
    "TK_WRITE", 
    "TK_RETURN", 
    "TK_PLUS", 
    "TK_MINUS", 
    "TK_MUL", 
    "TK_DIV", 
    "TK_CALL",
    "TK_RECORD", 
    "TK_ENDRECORD", 
    "TK_ELSE", 
    "TK_AND", 
    "TK_OR", 
    "TK_NOT", 
    "TK_LT", 
    "TK_LE", 
    "TK_EQ", 
    "TK_GT", 
    "TK_GE", 
    "TK_NE"};

void removeComments(FILE* fp1,FILE* fp2){
    fp2=fopen("WithoutComments.txt","w+");
    if(fp1==NULL || fp2==NULL){
        printf("Error reading file");
        exit(1);
    }
    char c;
    bool start=false;
    while((c=fgetc(fp1))!=EOF){
        if(c=='%'){
            start=true;
        }
        if(!start){
            fputc(c,fp2);
        }
        if(start && c=='\n'){
            start=false;
            lineNumber++;
            fputc('\n',fp2);
        }
    }
}

void initializeBuffers(){
    buf1=(char*)calloc(BUFFER_SIZE+2,sizeof(char));
    buf2=(char*)calloc(BUFFER_SIZE+2,sizeof(char));
    fseek(fp,0,SEEK_SET);
    int readlen;
    if(fp && !feof(fp)){
        readlen=fread(buf1,sizeof(char),BUFFER_SIZE,fp);
    }
    if(feof(fp))buf1[readlen++]=' ';
    buf1[readlen++]='\0';
}


FILE* getStream(FILE* fp){
    initializeBuffers();

}

Token getNextToken(char* buf1, char* buf2){

}

int main(){
    // getStream();
    // getNextToken();
}