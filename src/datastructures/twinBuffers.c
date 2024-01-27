#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define BUFFER_SIZE 1024

char* buf1;
char* buf2;
FILE* fpclean;
int state;

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
                            //failure();
                            state=0;//Temporary line
                        }
                        break;
                    }
                    break;
                    //case 0 ends here
                case 1:
                    break;
                    //case 1 ends here
                case 2:
                    break;
                    //case 2 ends here
                case 3:
                    break;
                    //case 3 ends here
                case 4:
                    break;
                    //case 4 ends here
                case 5:
                    break;
                    //case 5 ends here
                case 6:
                    break;
                    //case 6 ends here
                case 7:
                    break;
                    //case 7 ends here
                case 8:
                    break;
                    //case 8 ends here
                case 9:
                    break;
                    //case 9 ends here
                case 10:
                    break;
                    //case 10 ends here
                case 11:
                    break;
                    //case 11 ends here
                case 12:
                    break;
                    //case 12 ends here
                case 13:
                    break;
                    //case 13 ends here
                case 14:
                    break;
                    //case 14 ends here
                case 15:
                    break;
                    //case 15 ends here
                case 16:
                    break;
                    //case 16 ends here
                case 17:
                    break;
                    //case 17 ends here
                case 18:
                    break;
                    //case 18 ends here
                case 19:
                    break;
                    //case 19 ends here
                case 20:
                    break;
                    //case 20 ends here
                case 21:
                    break;
                    //case 21 ends here
                case 22:
                    break;
                    //case 22 ends here
                case 23:
                    break;
                    //case 23 ends here
                case 24:
                    break;
                    //case 24 ends here
                case 25:
                    break;
                    //case 25 ends here
                case 26:
                    break;
                    //case 26 ends here
                case 27:
                    break;
                    //case 27 ends here
                case 28:
                    break;
                    //case 28 ends here
                case 29:
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
}