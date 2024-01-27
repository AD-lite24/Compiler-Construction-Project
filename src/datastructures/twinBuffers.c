#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define BUFFER_SIZE 1024

char* buf1;
char* buf2;
FILE* fpclean;
FILE* removeComments(FILE* fp1){
    FILE* fp2=(FILE*) malloc(sizeof(FILE));
    fp2 = fopen("WithoutComments.txt", "w+");
    // open the file in which we supposed to write

    if (fp1 == NULL || fp2 == NULL)
    {
        // handle error in opening of any file
        printf("Error reading file");
        exit(1);
    }

    char c; // read character by character input in this variable
    bool start = 0;
    // if start==0, no comment is being read
    // if start==1, a comment is being read
    
    while ((c = fgetc(fp1)) != EOF)
    {
        if (c == '%')
        {
            // comment start
            start = 1;
        }
        if (start == 0)
        {
            // write only when no comment is being read
            fputc(c, fp2);
        }
        if (start == 1 && c == '\n')
        {
            // if comment is in progress and we encounter endline, end the comment
            start = 0;
            fputc('\n',fp2);
        }
    }

    // fclose(fp1);
    // fclose(fp2);
    return fp2;
}

void initializeBuffers(){
    buf1=(char*)calloc(BUFFER_SIZE+1,sizeof(char));
    buf2=(char*)calloc(BUFFER_SIZE+1,sizeof(char));
    FILE* fpwcom=fopen("t.txt","r");
    fpclean=removeComments(fpwcom);
    fclose(fpwcom);
    fseek(fpclean,0,SEEK_SET);
    int readlen;
    if(fpclean && !feof(fpclean)){
        readlen=fread(buf1,sizeof(char),BUFFER_SIZE,fpclean);
    }
    buf1[readlen++]='\0';
    
}

void reloadBuffer(char* buf){
    int readlen;
    if(fpclean && !feof(fpclean)) readlen=fread(buf,sizeof(char),BUFFER_SIZE,fpclean);
    buf[readlen++]='\0';
}

void traverseBuffer(){
    char* lexemeBegin=(char*) malloc(sizeof(char));
    char * forward=(char*) malloc(sizeof(char));
    lexemeBegin=buf1;
    forward=buf1;
    while(1){
        char c=*forward;
        switch(*(forward++)){
            case '\0':
                if((forward)==(buf1+BUFFER_SIZE+1)){
                    //reload buffer2
                    reloadBuffer(buf2);
                    //set forward to buffer2
                    forward=buf2;
                }else if((forward)==(buf2+BUFFER_SIZE+1)){
                    //reload buffer1
                    reloadBuffer(buf1);
                    //set forward to buffer1
                    forward=buf1;
                }else{
                    //terminate lexical analysis
                    return ;
                }
                break;
            default:
                printf("%c", c);

        }
    }
    
}

int main(){
    initializeBuffers();
    traverseBuffer();
}