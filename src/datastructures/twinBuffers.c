#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "../../include/datastructures/trie.h"
#include "../../include/tokens/tokens.h"

//To-Do:
//1) Buffer Size + 1 vs + 2
//2) 20 size limit fieldid
//3) Hardcoded tasks.json for now, need to see how to gcc trie.c while debugging
//4) getLexeme buffer split



#define BUFFER_SIZE 1024

char* buf1;
char* buf2;
char* lexemeBegin;
char* forward;
FILE* fpclean;
int state;
int lineNumber;

//Line number functionality yet to be implemented
Token tk;    
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
            lineNumber++;
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
    memcpy(res, begin, forward - begin-1);
    res[forward-begin-1]='\0';
    // printf("%s \n", res);
    return res;
}

void printToken(Token tk){
    printf("%d\n", tk);
}

void initializeBuffers(){
    buf1=(char*)calloc(BUFFER_SIZE+2,sizeof(char));
    buf2=(char*)calloc(BUFFER_SIZE+2,sizeof(char));
    FILE* fpwcom=fopen("t1.txt","r");
    fpclean=removeComments(fpwcom);
    fclose(fpwcom);
    fseek(fpclean,0,SEEK_SET);
    int readlen;
    if(fpclean && !feof(fpclean)){
        readlen=fread(buf1,sizeof(char),BUFFER_SIZE,fpclean);
    }
    if(feof(fpclean))buf1[readlen++]=' ';
    buf1[readlen++]='\0';
    
}

void reloadBuffer(char* buf){
    int readlen;
    if(fpclean && !feof(fpclean)) readlen=fread(buf,sizeof(char),BUFFER_SIZE,fpclean);
    if(feof(fpclean))buf[readlen++]=' ';
    buf[readlen++]='\0';
}

void incrementLexemeBegin(int val){
    for(int i=0;i<val;i++){
        if(*(lexemeBegin+1)!='\0')lexemeBegin++;
        else if((lexemeBegin-buf1)< BUFFER_SIZE+2)lexemeBegin=buf2;
        else lexemeBegin=buf1;
    }
}

void decrementForward(int val){
    if(forward==buf1){
        forward=buf2+BUFFER_SIZE-val;
    }else if(forward==buf2){
        forward=buf1+BUFFER_SIZE-val;
    }else{
        forward -= val;
    }
}

void traverseBuffer(){
    lexemeBegin=(char*) malloc(sizeof(char));
    forward=(char*) malloc(sizeof(char));
    lexemeBegin=buf1;
    forward=buf1;
    state=0;
    lineNumber=1;
    TRIE trie = populateTrie();
    // ind1 ind2 ind3 \0 buf2 buf21 buf22
    // lB^^         
    //
    while(1){
        char c=*forward;
        switch(*(forward++)){
            case '\0':
                if((forward)==(buf1+BUFFER_SIZE+1) || (forward)==(buf1+BUFFER_SIZE+2)){
                    //reload buffer2
                    reloadBuffer(buf2);
                    //set forward to buffer2
                    forward=buf2;
                }else if((forward)==(buf2+BUFFER_SIZE+1) || (forward)==(buf2+BUFFER_SIZE+2)){
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
                        // printf("TK_NOT");
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
                    case ',':
                        state=30;
                        break;
                    case ';':
                        state = 31;
                        break;
                    case '[':
                        state = 32;
                        break;
                    case ']':
                        state = 33;
                        break;
                    case '(':
                        state = 34;
                        break;
                    case ')':
                        state = 35;
                        break;
                    case '+':
                        state = 36;
                        break;
                    case '-':
                        state = 37;
                        break;
                    case '*':
                        state = 38;
                        break;
                    case ':':
                        state = 46;
                        break;
                    case '.':
                        state = 47;
                        break;
                    case '/':
                        state = 39;
                        break;
                    case '\n':
                        lexemeBegin=forward;
                        lineNumber++;
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
                    case '\r':
                        lexemeBegin=forward;
                        state=0;
                        break;
                    case '@':
                        state=40;
                        break;
                    case '&':
                        state=43;
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
                    state=0;
                    tk = TK_NOT;
                    printToken(tk);
                    // printf("%s %s\n", tk, getLexeme(lexemeBegin, forward));
                    // char * temp=getLexeme(lexemeBegin,forward);
                    // printf("%s %c \n",tk,temp);
                    // printf("%s ",temp);
                    // lexemeBegin=forward-1;
                    decrementForward(1);
                    lexemeBegin=forward;
                    // forward=lexemeBegin;
                    break;
                    //case 1 ends here
                case 2:
                    //final state
                    if(c=='='){
                        state=3;
                    }else if(c=='-'){
                        state=4;
                    }else{
                        tk=TK_LT;
                        printToken(tk);
                        state = 0;
                        // printf("%s %s\n", tk, getLexeme(lexemeBegin, forward));
                        // lexemeBegin = forward-1;
                        // forward=lexemeBegin;
                        decrementForward(1);
                        lexemeBegin=forward;
                    }
                    break;
                    //case 2 ends here
                case 3:
                    //final state
                    tk = TK_LE;
                    printToken(tk);
                    state = 0;
                    // printf("%s %s\n", tk, getLexeme(lexemeBegin, forward));
                    lexemeBegin = forward;
                    break;
                    //case 3 ends here
                case 4:
                    if(c=='-'){
                        state=5;
                    }else{
                        //other condition
                        // failure();
                        state=0;
                        // lexemeBegin++;
                        incrementLexemeBegin(1);
                        forward=lexemeBegin;
                    }
                    break;
                    //case 4 ends here
                case 5:
                    if(c=='-'){
                        state=6;
                    }else{
                        //other condition
                        // failure();
                        state=0;
                        // lexemeBegin++;
                        incrementLexemeBegin(1);
                        forward=lexemeBegin;
                    }
                    break;
                    //case 5 ends here
                case 6:
                    //final state
                    tk = TK_ASSIGNOP;
                    printToken(tk);
                    state=0;
                    // printf("%s %s\n", tk, getLexeme(lexemeBegin, forward));
                    // lexemeBegin = forward-1;
                    // forward=lexemeBegin;
                    decrementForward(1);
                    lexemeBegin=forward;
                    break;
                    //case 6 ends here
                case 7:
                    if(c=='='){
                        state=8;
                    }else{
                        //other condition
                        failure();
                        state=0;
                        // lexemeBegin++;
                        // forward=lexemeBegin;
                        incrementLexemeBegin(1);
                        forward=lexemeBegin;
                    }
                    break;
                    //case 7 ends here
                case 8:
                    //final state
                    tk = TK_EQ;
                    printToken(tk);
                    state=0;
                    // printf("%s %s\n", tk, getLexeme(lexemeBegin, forward));
                    // lexemeBegin = forward-1;
                    // forward=lexemeBegin;
                    decrementForward(1);
                    lexemeBegin=forward;
                    break;
                    //case 8 ends here
                case 9:
                    //final state
                    if(c=='='){
                        state=10;
                    }else{
                        //other condition
                        state=0;
                        tk=TK_GT;
                        printToken(tk);
                        // lexemeBegin=forward-1;
                        // forward=lexemeBegin;
                        decrementForward(1);
                        lexemeBegin=forward;
                    }
                    break;
                    //case 9 ends here
                case 10:
                    //final state
                    tk=TK_GE;
                    printToken(tk);
                    state=0;
                    // lexemeBegin=forward-1;
                    // forward=lexemeBegin;
                    decrementForward(1);
                    lexemeBegin=forward;
                    break;
                    //case 10 ends here
                case 11:
                    if(c=='='){
                        state=12;
                    }else{
                        //other condition
                        failure();
                        state=0;
                        // lexemeBegin++;
                        incrementLexemeBegin(1);
                        forward=lexemeBegin;
                    }
                    break;
                    //case 11 ends here
                case 12:
                    //final
                    tk=TK_NE;
                    printToken(tk);
                    state=0;
                    // lexemeBegin=forward-1;
                    // forward=lexemeBegin;
                    decrementForward(1);
                    lexemeBegin=forward;
                    break;
                    //case 12 ends here
                case 13:
                    if(c>='a' && c<='z'){
                        state=14;
                    }else{
                        //other condition
                        failure();
                        state=0;
                        // lexemeBegin++;
                        incrementLexemeBegin(1);
                        forward=lexemeBegin;
                    }
                    break;
                    //case 13 ends here
                case 14:
                    //final state
                    if(c>='a' && c<='z'){
                        state=14;
                    }else{
                        //other condition
                        tk=TK_RUID;
                        printToken(tk);
                        state=0;
                        // lexemeBegin=forward-1;
                        // forward=lexemeBegin;
                        decrementForward(1);
                        lexemeBegin=forward;
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
                        tk=TK_NUM;
                        printToken(tk);
                        state=0;
                        // lexemeBegin=forward-1;
                        // forward=lexemeBegin;
                        decrementForward(1);
                        lexemeBegin=forward;
                    }
                    break;
                    //case 15 ends here
                case 16:
                    if(c>='0' && c<='9'){
                        state=17;
                    }else{
                        //other condition
                        // failure();
                        state=0;
                        // lexemeBegin++;
                        incrementLexemeBegin(1);
                        forward=lexemeBegin;
                    }
                    break;
                    //case 16 ends here
                case 17:
                    if(c>='0' && c <= '9') state = 18;
                    else{
                        // failure();
                        state=0;
                        incrementLexemeBegin(1);
                        forward=lexemeBegin;
                    }
                    //other condition
                    break;
                    //case 17 ends here
                case 18:
                    if(c=='E') state = 19;
                    else{
                        //other condition
                        tk=TK_RNUM;
                        printToken(tk);
                        state=0;
                        decrementForward(1);
                        lexemeBegin = forward;
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
                        // failure();
                        state=0;
                        incrementLexemeBegin(4);
                        forward=lexemeBegin;
                    }
                    break;
                    //case 19 ends here
                case 20:
                    if(c >= '0' && c<='9') state= 21;
                    else{
                        //other condition
                        // failure();
                        state=0;
                        incrementLexemeBegin(4);
                        forward=lexemeBegin;
                    }
                    break;
                    //case 20 ends here
                case 21:
                    if(c >= '0' && c<='9') state= 22;
                    else{
                        //other condition
                        // failure();
                        state=0;
                        incrementLexemeBegin(4);
                        forward=lexemeBegin;
                    }
                    break;
                    //case 21 ends here
                case 22:
                    //final state
                    tk=TK_RNUM;
                    printToken(tk);
                    state=0;
                    decrementForward(1);
                    lexemeBegin = forward;
                    break;
                    //case 22 ends here;
                case 23:
                    if(c>='a' && c<='z') state = 24;
                    else if(c>='A' && c<= 'Z') state = 24;
                    else{
                        //other condition
                        failure();
                        state=0;
                        incrementLexemeBegin(1);
                        forward=lexemeBegin;
                    }
                    break;
                    //case 23 ends here
                case 24:
                    if(c>='a' && c<='z') state = 24;
                    else if(c>='A' && c<='Z') state = 24;
                    else if(c>='0' && c<= '9') state = 25;
                    else{
                        //other condition
                        tk=TK_FUNID;
                        char * m = getLexeme(lexemeBegin, forward);
                        char* m2 = (char*)malloc(sizeof(char)*6);
                        m2 = "_main";
                        if(strcmp(m, m2)==0){
                            tk = TK_MAIN;
                        }
                        printToken(tk);

                        state=0;
                        decrementForward(1);
                        lexemeBegin = forward;
                    }
                    //final state
                    break;
                    //case 24 ends here
                case 25:
                    if(c>='0' && c<='9') state = 25;
                    else{
                        //other condition
                        tk=TK_FUNID;
                        printToken(tk);
                        state=0;
                        decrementForward(1);
                        lexemeBegin = forward;
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
                        tk=TK_FIELDID;
                        char* str = (char*)malloc(sizeof(char)*(forward - lexemeBegin -1));
                        // str[forward - lexemeBegin - 1] = '\0';
                        str = strndup(lexemeBegin, forward - 1- lexemeBegin);
                        Token tk2 = lookupTrie(trie, str);
                        printToken(tk);
                        if(tk2!=0){
                            tk = tk2;
                        }
                        printToken(tk);
                        state=0;
                        decrementForward(1);
                        lexemeBegin = forward;
                    }
                    //final state
                    break;
                    //case 26 ends here
                case 27:
                    if(c>='b' && c<='d') state = 27;
                    else if(c>='2' && c<='7') state = 28;
                    else{
                        //other condition
                        tk=TK_ID;
                        printToken(tk);
                        state=0;
                        decrementForward(1);
                        lexemeBegin = forward;
                    }
                    //final state
                    break;
                    //case 27 ends here
                case 28:
                    if(c>='2' && c<='7') state = 28;
                    else{
                        //other condition
                        tk=TK_ID;
                        printToken(tk);
                        state=0;
                        decrementForward(1);
                        lexemeBegin = forward;
                    }
                    //final state
                    break;
                    //case 28 ends here
                case 29:
                    if(c>='a' && c<= 'z') state = 29;
                    else{
                        //other condition
                        tk=TK_FIELDID;
                        char* str = (char*)malloc(sizeof(char)*(forward - lexemeBegin -1));
                        // str[forward - lexemeBegin - 1] = '\0';
                        str = strndup(lexemeBegin, forward - 1- lexemeBegin);
                        Token tk2 = lookupTrie(trie, str);
                        if(tk2!=0){
                            tk = tk2;
                        }
                        printToken(tk);
                        state=0;
                        decrementForward(1);
                        lexemeBegin = forward;
                    }
                    //final state
                    break;
                    //case 29 ends here
                case 30:
                    //final state
                    state=0;
                    tk = TK_COMMA;
                    printToken(tk);
                    // printf("%s %s\n", tk, getLexeme(lexemeBegin, forward));
                    // char * temp=getLexeme(lexemeBegin,forward);
                    // printf("%s %c \n",tk,temp);
                    // printf("%s ",temp);
                    decrementForward(1);
                    lexemeBegin = forward;
                    break;
                case 31:
                    //final state
                    state=0;
                    tk = TK_SEM;
                    printToken(tk);
                    // printf("%s %s\n", tk, getLexeme(lexemeBegin, forward));
                    // char * temp=getLexeme(lexemeBegin,forward);
                    // printf("%s %c \n",tk,temp);
                    // printf("%s ",temp);
                    decrementForward(1);
                    lexemeBegin = forward;
                    break;
                case 32:
                    //final state
                    state=0;
                    tk = TK_SQL;
                    printToken(tk);
                    // printf("%s %s\n", tk, getLexeme(lexemeBegin, forward));
                    // char * temp=getLexeme(lexemeBegin,forward);
                    // printf("%s %c \n",tk,temp);
                    // printf("%s ",temp);
                    decrementForward(1);
                    lexemeBegin = forward;
                    break;
                case 33:
                    //final state
                    state=0;
                    tk = TK_SQR;
                    printToken(tk);
                    // printf("%s %s\n", tk, getLexeme(lexemeBegin, forward));
                    // char * temp=getLexeme(lexemeBegin,forward);
                    // printf("%s %c \n",tk,temp);
                    // printf("%s ",temp);
                    decrementForward(1);
                    lexemeBegin = forward;
                    break;
                case 34:
                    //final state
                    state=0;
                    tk = TK_OP;
                    printToken(tk);
                    // printf("%s %s\n", tk, getLexeme(lexemeBegin, forward));
                    // char * temp=getLexeme(lexemeBegin,forward);
                    // printf("%s %c \n",tk,temp);
                    // printf("%s ",temp);
                    decrementForward(1);
                    lexemeBegin = forward;
                    break;
                case 35:
                    //final state
                    state=0;
                    tk = TK_CL;
                    printToken(tk);
                    // printf("%s %s\n", tk, getLexeme(lexemeBegin, forward));
                    // char * temp=getLexeme(lexemeBegin,forward);
                    // printf("%s %c \n",tk,temp);
                    // printf("%s ",temp);
                    decrementForward(1);
                    lexemeBegin = forward;
                    break;
                case 36:
                    //final state
                    state=0;
                    tk = TK_PLUS;
                    printToken(tk);
                    // printf("%s %s\n", tk, getLexeme(lexemeBegin, forward));
                    // char * temp=getLexeme(lexemeBegin,forward);
                    // printf("%s %c \n",tk,temp);
                    // printf("%s ",temp);
                    decrementForward(1);
                    lexemeBegin = forward;
                    break;
                case 37:
                    //final state
                    state=0;
                    tk = TK_MINUS;
                    printToken(tk);
                    // printf("%s %s\n", tk, getLexeme(lexemeBegin, forward));
                    // char * temp=getLexeme(lexemeBegin,forward);
                    // printf("%s %c \n",tk,temp);
                    // printf("%s ",temp);
                    decrementForward(1);
                    lexemeBegin = forward;
                    break;
                case 38:
                    //final state
                    state=0;
                    tk = TK_MUL;
                    printToken(tk);
                    // printf("%s %s\n", tk, getLexeme(lexemeBegin, forward));
                    // char * temp=getLexeme(lexemeBegin,forward);
                    // printf("%s %c \n",tk,temp);
                    // printf("%s ",temp);
                    decrementForward(1);
                    lexemeBegin = forward;
                    break;
                case 39:
                    //final state
                    state=0;
                    tk = TK_DIV;
                    printToken(tk);
                    // printf("%s %s\n", tk, getLexeme(lexemeBegin, forward));
                    // char * temp=getLexeme(lexemeBegin,forward);
                    // printf("%s %c \n",tk,temp);
                    // printf("%s ",temp);
                    decrementForward(1);
                    lexemeBegin = forward;
                    break;    
                case 40:
                    if(c=='@'){
                        state=41;
                    }else{
                        failure();
                        state=0;
                        incrementLexemeBegin(1);
                        forward=lexemeBegin;
                    }
                    break;
                    //case 40 ends here
                case 41:
                    if(c=='@'){
                        state=42;
                    }else{
                        //other condition
                        failure();
                        state=0;
                        incrementLexemeBegin(1);
                        forward=lexemeBegin;
                    }
                    break;
                    //case 41 ends here
                case 42:
                    //final state
                    tk=TK_OR;
                    printToken(tk);
                    state=0;
                    decrementForward(1);
                    lexemeBegin = forward;
                    break;
                case 43:
                    if(c=='&'){
                        state=44;
                    }else{
                        //other condition
                        failure();
                        state=0;
                        incrementLexemeBegin(1);
                        forward=lexemeBegin;
                    }
                    break;
                case 44:
                    if(c=='&'){
                        state=45;
                    }else{
                        //other condition
                        failure();
                        state=0;
                        incrementLexemeBegin(1);
                        forward=lexemeBegin;
                    }
                    break;
                case 45:
                    //final state
                    tk=TK_AND;
                    printToken(tk);
                    state=0;
                    decrementForward(1);
                    lexemeBegin = forward;
                    break;
                case 46:
                    //final state
                    state=0;
                    tk = TK_COLON;
                    printToken(tk);
                    // printf("%s %s\n", tk, getLexeme(lexemeBegin, forward));
                    // char * temp=getLexeme(lexemeBegin,forward);
                    // printf("%s %c \n",tk,temp);
                    // printf("%s ",temp);
                    decrementForward(1);
                    lexemeBegin = forward;
                    break;
                case 47:
                    //final state
                    state=0;
                    tk = TK_DOT;
                    printToken(tk);
                    // printf("%s %s\n", tk, getLexeme(lexemeBegin, forward));
                    // char * temp=getLexeme(lexemeBegin,forward);
                    // printf("%s %c \n",tk,temp);
                    // printf("%s ",temp);
                    decrementForward(1);
                    lexemeBegin = forward;
                    break;
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

    // printToken(TK_AND);

}