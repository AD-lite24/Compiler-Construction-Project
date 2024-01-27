#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "tokens/tokens.h"

#define BUFFER_SIZE 1024

char* buf1;
char* buf2;
FILE* fpclean;
int state;
//Line number functionality yet to be implemented

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

void failure(){
    printf("Incorrect syntax!!! ");

}

char* getLexeme(char* begin, char* forward){
    char* res = (char*)malloc(sizeof(char) * (forward - begin));
    memcpy(res, begin, forward - begin);
    printf("%s \n", res);
    return res;
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
    state=0;
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
                    //This has to be changed.
                    return ;
                }
                break;
            default:
                printf("%c", c);
                //Just changing states as of now 
                switch (state)
                {
                case 0:
                    switch (c)
                    {
                    case '~':
                        state=1;
                        break;
                    case '<':
                        state=2;
                        break;
                    case '=':
                        state=7;
                        break;
                    case '>':
                        state=9;
                        break;
                    case '!':
                        state=11;
                        break;
                    case '#':
                        state=13;
                        break;
                    case '_':
                        state=23;
                        break;
                    case '\n':
                        lexemeBegin=forward;
                        state=0;
                        break;
                    case '\t':
                        lexemeBegin=forward;
                        state=0;
                        break;
                    case ' ':
                        lexemeBegin=forward;
                        state=0;
                        break;
                    default:
                        if(c>='0' && c<='9'){
                            state=15;
                        }else if(c>='b' && c<='d'){
                            state=26;
                        }else if(c>='a' && c<='z'){
                            state=29;
                        }else{
                            //This should give the failure state
                            //Since none of the recognizable characters are taken
                            failure();
                            lexemeBegin=forward;
                            state=0;//Temporary line
                        }
                        break;
                    }
                    break;
                    //case 0 ends here
                case 1:
                    //final state
                    lexemeBegin=forward;
                    state=0;
                    break;
                    //case 1 ends here
                case 2:
                    //final state
                    if(c=='='){
                        state=3;
                    }else if(c=='-'){
                        state=4;
                    }else{
                        //obtained TK_LT
                    }
                    break;
                    //case 2 ends here
                case 3:
                    //final state
                    break;
                    //case 3 ends here
                case 4:
                    if(c=='-'){
                        state=5;
                    }else{
                        //other condition
                    }
                    break;
                    //case 4 ends here
                case 5:
                    if(c=='-'){
                        state=6;
                    }else{
                        //other condition
                    }
                    break;
                    //case 5 ends here
                case 6:
                    //final state
                    break;
                    //case 6 ends here
                case 7:
                    if(c=='='){
                        state=8;
                    }else{
                        //other condition
                    }
                    break;
                    //case 7 ends here
                case 8:
                    //final state
                    break;
                    //case 8 ends here
                case 9:
                    //final state
                    if(c=='='){
                        state=10;
                    }else{
                        //other condition
                    }
                    break;
                    //case 9 ends here
                case 10:
                    //final state
                    break;
                    //case 10 ends here
                case 11:
                    if(c=='='){
                        state=12;
                    }else{
                        //other condition
                    }
                    break;
                    //case 11 ends here
                case 12:
                    //final
                    break;
                    //case 12 ends here
                case 13:
                    if(c>='a' && c<='z'){
                        state=14;
                    }else{
                        //other condition
                    }
                    break;
                    //case 13 ends here
                case 14:
                    //final state
                    if(c>='a' && c<='z'){
                        state=14;
                    }else{
                        //other condition
                    }
                    break;
                    //case 14 ends here
                case 15:
                    //final state
                    if(c>='0' && c<='9'){
                        state=15;
                    }else if (c=='.'){
                        state=16;
                    }else{
                        //other condition
                    }
                    break;
                    //case 15 ends here
                case 16:
                    if(c>='0' && c<='9'){
                        state=17;
                    }else{
                        //other condition
                    }
                    break;
                    //case 16 ends here
                case 17:
                    if(c>='0' && c <= '9') state = 18;
                    //other condition
                    break;
                    //case 17 ends here
                case 18:
                    if(c=='E') state = 19;
                    else{
                        //other condition
                    }
                    //final state
                    break;
                    //case 18 ends here
                case 19:
                    if(c=='+'||c=='-'){
                        state=20;
                    }else if(c>='0' && c<='9'){
                        state=21;
                    }else{
                        //other condition
                    }
                    break;
                    //case 19 ends here
                case 20:
                    if(c >= '0' && c<='9') state= 21;
                    else{
                        //other condition
                    }
                    break;
                    //case 20 ends here
                case 21:
                    if(c >= '0' && c<='9') state= 22;
                    else{
                        //other condition
                    }
                    break;
                    //case 21 ends here
                case 22:
                    //final state
                    break;
                    //case 22 ends here;
                case 23:
                    if(c>='a' && c<='z') state = 24;
                    else if(c>='A' && c<= 'Z') state = 24;
                    else{
                        //other condition
                    }
                    break;
                    //case 23 ends here
                case 24:
                    if(c>='a' && c<='z') state = 25;
                    else if(c>='A' && c<='Z') state = 25;
                    else if(c>='0' && c<= '9') state = 25;
                    else{
                        //other condition
                    }
                    //final state
                    break;
                    //case 24 ends here
                case 25:
                    if(c>='0' && c<='9') state = 25;
                    else{
                        //other condition
                    }
                    //final state
                    break;
                    //case 25 ends here
                case 26:
                    if(c>='2' && c<='7'){
                        state = 27;
                    }else if(c>='a' && c<='z'){
                        state=29;
                    }else{
                        //other condition
                    }
                    //final state
                    break;
                    //case 26 ends here
                case 27:
                    if(c>='b' && c<='d') state = 27;
                    else if(c>='2' && c<='7') state = 28;
                    else{
                        //other condition
                    }
                    //final state
                    break;
                    //case 27 ends here
                case 28:
                    if(c>='2' && c<='7') state = 28;
                    else{
                        //other condition
                    }
                    //final state
                    break;
                    //case 28 ends here
                case 29:
                    if(c>='a' && c<= 'z') state = 29;
                    else{
                        //other condition
                    }
                    //final state
                    break;
                    //case 29 ends here
                default:
                    break;
                }

        }
    }
    
}

int main(){
    initializeBuffers();
    traverseBuffer();
    // char* b = (char*)malloc(sizeof(char)*1000);
    // b = "owefdweihfncwiuehncireutviurtvekr";
    // char* c = b + 11;
    // getLexeme(b, c);


}