#include "../../include/lexer/lexer.h"
#include "../../include/lexer/lexerDef.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void insertIntoTrie(TRIE root, char *word, enum Token tk) {
    TRIE current = root;

    for (int i = 0; i < strlen(word); i++) {
        if (current->next[word[i] - 'a'] == NULL) {
            current->next[word[i] - 'a'] = (TRIE)malloc(sizeof(struct Trie));
            current->next[word[i] - 'a']->c = word[i];
            for (int j = 0; j < 26; j++) {
                current->next[word[i] - 'a']->next[j] = NULL;
            }
        }

        current = current->next[word[i] - 'a'];
        if (i == strlen(word) - 1) {
            current->tk = tk;
        }
    }
}

TRIE populateTrie() {
    TRIE root = (TRIE)malloc(sizeof(struct Trie));
    root->c = '`';
    for (int i = 0; i < 26; i++) {
        root->next[i] = NULL;
    }
    insertIntoTrie(root, "with", TK_WITH);
    insertIntoTrie(root, "parameters", TK_PARAMETERS);
    insertIntoTrie(root, "end", TK_END);
    insertIntoTrie(root, "while", TK_WHILE);
    insertIntoTrie(root, "union", TK_UNION);
    insertIntoTrie(root, "endunion", TK_ENDUNION);
    insertIntoTrie(root, "definetype", TK_DEFINETYPE);
    insertIntoTrie(root, "as", TK_AS);
    insertIntoTrie(root, "type", TK_TYPE);
    insertIntoTrie(root, "global", TK_GLOBAL);
    insertIntoTrie(root, "parameter", TK_PARAMETER);
    insertIntoTrie(root, "list", TK_LIST);
    insertIntoTrie(root, "input", TK_INPUT);
    insertIntoTrie(root, "output", TK_OUTPUT);
    insertIntoTrie(root, "real", TK_REAL);
    insertIntoTrie(root, "int", TK_INT);
    insertIntoTrie(root, "endwhile", TK_ENDWHILE);
    insertIntoTrie(root, "if", TK_IF);
    insertIntoTrie(root, "then", TK_THEN);
    insertIntoTrie(root, "endif", TK_ENDIF);
    insertIntoTrie(root, "read", TK_READ);
    insertIntoTrie(root, "write", TK_WRITE);
    insertIntoTrie(root, "return", TK_RETURN);
    insertIntoTrie(root, "call", TK_CALL);
    insertIntoTrie(root, "record", TK_RECORD);
    insertIntoTrie(root, "endrecord", TK_ENDRECORD);
    insertIntoTrie(root, "else", TK_ELSE);

    return root;
}

enum Token lookupTrie(TRIE root, char *word) {
    TRIE current = root;
    for (int i = 0; i < strlen(word); i++) {
        if (current->next[word[i] - 'a'] == NULL) {
            return TK_NULL;
        } else
            current = current->next[word[i] - 'a'];
        if (i == strlen(word) - 1) {
            return current->tk;
        }
    }
}

#define BUFFER_SIZE 1024

char *buf1;
char *buf2;
char *lexemeBegin;
char *forward;
FILE *fpwcom;
int state;
int lineNumber;
char *tokensArr[] = {
    "TK_NULL",       "TK_ASSIGNOP", "TK_COMMENT",   "TK_FIELDID", "TK_ID",
    "TK_NUM",        "TK_RNUM",     "TK_FUNID",     "TK_RUID",    "TK_WITH",
    "TK_PARAMETERS", "TK_END",      "TK_WHILE",     "TK_UNION",   "TK_ENDUNION",
    "TK_DEFINETYPE", "TK_AS",       "TK_TYPE",      "TK_MAIN",    "TK_GLOBAL",
    "TK_PARAMETER",  "TK_LIST",     "TK_SQL",       "TK_SQR",     "TK_INPUT",
    "TK_OUTPUT",     "TK_INT",      "TK_REAL",      "TK_COMMA",   "TK_SEM",
    "TK_COLON",      "TK_DOT",      "TK_ENDWHILE",  "TK_OP",      "TK_CL",
    "TK_IF",         "TK_THEN",     "TK_ENDIF",     "TK_READ",    "TK_WRITE",
    "TK_RETURN",     "TK_PLUS",     "TK_MINUS",     "TK_MUL",     "TK_DIV",
    "TK_CALL",       "TK_RECORD",   "TK_ENDRECORD", "TK_ELSE",    "TK_AND",
    "TK_OR",         "TK_NOT",      "TK_LT",        "TK_LE",      "TK_EQ",
    "TK_GT",         "TK_GE",       "TK_NE",        "TK_EOF"};

Token tk;
TRIE trie;

FILE *removeComments(FILE *testcaseFile, FILE *cleanFile) {

    // open the file in which we supposed to write

    if (testcaseFile == NULL || cleanFile == NULL) {
        // handle error in opening of any file
        printf("Error reading file");
        exit(1);
    }

    char c; // read character by character input in this variable
    bool start = 0;
    // if start==0, no comment is being read
    // if start==1, a comment is being read

    while ((c = fgetc(testcaseFile)) != EOF) {
        if (c == '%') {
            // comment start
            start = 1;
        }
        if (start == 0) {
            // write only when no comment is being read
            fputc(c, cleanFile);
        }
        if (start == 1 && c == '\n') {
            // if comment is in progress and we encounter endline, end the
            // comment
            start = 0;
            lineNumber++;
            fputc('\n', cleanFile);
        }
    }
    return cleanFile;
}

char *getLexeme(char *begin, char *forward) {
    if ((begin <= (buf1 + BUFFER_SIZE + 1) &&
         forward <= (buf1 + BUFFER_SIZE + 1)) ||
        ((begin > (buf1 + BUFFER_SIZE + 1) &&
          begin <= (buf2 + BUFFER_SIZE + 1)) &&
         (forward > (buf1 + BUFFER_SIZE + 1)) &&
         forward <= (buf2 + BUFFER_SIZE + 1))) {
        char *res = (char *)malloc(sizeof(char) * (forward - begin));
        memcpy(res, begin, forward - begin - 1);
        res[forward - begin - 1] = '\0';
        return res;
    } else {
        if (begin <= (buf1 + BUFFER_SIZE + 1) &&
            forward <= (buf2 + BUFFER_SIZE + 1)) {
            char *temp = (char *)malloc(sizeof(char));
            while (*temp != '\0') {
                temp++;
            }
            char *temp1 = (char *)malloc(sizeof(char) * (temp - begin));
            memcpy(temp1, begin, temp - begin - 1);
            temp1[temp - begin - 1] = '\0';
            char *temp2 = (char *)malloc(sizeof(char) * (forward - buf2));
            memcpy(temp2, buf2, forward - buf2 - 1);
            temp2[forward - buf2 - 1] = '\0';
            char *res = (char *)malloc(sizeof(char) *
                                       (strlen(temp1) + strlen(temp2) + 1));
            strcpy(res, temp1);
            strcat(res, temp2);
            return res;
        } else {
            char *temp = (char *)malloc(sizeof(char));
            while (*temp != '\0') {
                temp++;
            }
            char *temp1 = (char *)malloc(sizeof(char) * (temp - begin));
            memcpy(temp1, begin, temp - begin - 1);
            temp1[temp - begin - 1] = '\0';
            char *temp2 = (char *)malloc(sizeof(char) * (forward - buf1));
            memcpy(temp2, buf1, forward - buf1 - 1);
            temp2[forward - buf1 - 1] = '\0';
            char *res = (char *)malloc(sizeof(char) *
                                       (strlen(temp1) + strlen(temp2) + 1));
            strcpy(res, temp1);
            strcat(res, temp2);
            return res;
        }
    }
}

void failure() {
    if (strlen(getLexeme(lexemeBegin, forward)) == 1) {
        printf("Line No %d: ", lineNumber);
        printf("Error : Unknown symbol <");
        printf("%s", getLexeme(lexemeBegin, forward));
        printf(">\n");
    } else {
        printf("Line No %d: ", lineNumber);
        printf("Error : Unknown pattern <");
        printf("%s", getLexeme(lexemeBegin, forward));
        printf(">\n");
    }
}

void printToken(Token tk) {
    if (tk != TK_ID || strlen(getLexeme(lexemeBegin, forward)) <= 20) {
        printf("Line no. %d", lineNumber);
        printf("\t ");
        printf("Lexeme %s", getLexeme(lexemeBegin, forward));
        printf("\t\t ");
        printf("Token ");
        printf("%s\n", tokensArr[tk]);
    } else {
        printf("Line no. %d", lineNumber);
        printf("\t ");
        printf("Error :Variable Identifier is longer than the prescribed "
               "length of 20 characters");
        printf("\n");
    }
}

returnToken makeReturnToken(int t) {
    returnToken r;
    if (t == -2) {
        r.flag = t;
        r.t = TK_EOF;
        r.lexeme = getLexeme(lexemeBegin, forward);
        r.line = lineNumber;
        return r;
    }
    if (t < 0) {
        r.flag = t;
        r.t = TK_NULL;
        r.lexeme = getLexeme(lexemeBegin, forward);
        r.line = lineNumber;
        return r;
    }
    r.flag = 1;
    r.t = t;
    r.line = lineNumber;
    char *lex = getLexeme(lexemeBegin, forward);
    if (tk != TK_ID || strlen(lex) <= 20) {
        r.lexeme = lex;
    } else {
        printf("Line No. %d\t Error :Variable Identifier is longer than the "
               "prescribed length of 20 characters %s\n",
               lineNumber, lex);
        r.lexeme = lex;
        // r.t = -1;
        r.flag = -1;
    }
    // printf("line %d\t token %d\t lexeme %s\n", r.line, r.t, r.lexeme);
    return r;
}

void initializeBuffers(char *fileName) {
    buf1 = (char *)calloc(BUFFER_SIZE + 2, sizeof(char));
    buf2 = (char *)calloc(BUFFER_SIZE + 2, sizeof(char));

    fpwcom = fopen(fileName, "r");

    fseek(fpwcom, 0, SEEK_SET);
    int readlen;
    if (fpwcom && !feof(fpwcom)) {
        readlen = fread(buf1, sizeof(char), BUFFER_SIZE, fpwcom);
    }
    if (feof(fpwcom)) {
        buf1[readlen++] = ' ';
    }
    buf1[readlen++] = '\0';
}

void reloadBuffer(char *buf) {
    int readlen;
    if (fpwcom && !feof(fpwcom))
        readlen = fread(buf, sizeof(char), BUFFER_SIZE, fpwcom);
    if (feof(fpwcom))
        buf[readlen++] = ' ';
    buf[readlen++] = '\0';
}

void incrementLexemeBegin(int val) {
    for (int i = 0; i < val; i++) {
        if (*(lexemeBegin + 1) != '\0')
            lexemeBegin++;
        else if ((lexemeBegin - buf1) < BUFFER_SIZE + 2)
            lexemeBegin = buf2;
        else
            lexemeBegin = buf1;
    }
}

void decrementForward(int val) {
    if (forward == buf1) {
        forward = buf2 + BUFFER_SIZE - val;
    } else if (forward == buf2) {
        forward = buf1 + BUFFER_SIZE - val;
    } else {
        forward -= val;
    }
}

void incrementForward() {
    if ((forward) == (buf1 + BUFFER_SIZE + 1) ||
        (forward) == (buf1 + BUFFER_SIZE + 2)) {
        reloadBuffer(buf2);
        forward = buf2;
    } else if ((forward) == (buf2 + BUFFER_SIZE + 1) ||
               (forward) == (buf2 + BUFFER_SIZE + 2)) {
        reloadBuffer(buf1);
        forward = buf1;
    } else {
        forward++;
    }
}

returnToken getNextToken() {
    returnToken r;
    while (1) {
        char c = *forward;
        switch (*(forward++)) {
        case '\0':
            if ((forward) == (buf1 + BUFFER_SIZE + 1) ||
                (forward) == (buf1 + BUFFER_SIZE + 2)) {
                // reload buffer2
                reloadBuffer(buf2);
                // set forward to buffer2
                forward = buf2;
            } else if ((forward) == (buf2 + BUFFER_SIZE + 1) ||
                       (forward) == (buf2 + BUFFER_SIZE + 2)) {
                // reload buffer1
                reloadBuffer(buf1);
                // set forward to buffer1
                forward = buf1;
            } else {
                // terminate lexical analysis
                r = makeReturnToken(-2);

                return r;
            }
            break;
        default:
            switch (state) {
            case 0:
                switch (c) {
                case '%':
                    while (*forward != '\n') {
                        incrementForward();
                    }
                    lineNumber++;
                    incrementForward();
                    lexemeBegin = forward;
                    break;
                case '~':
                    state = 1;
                    break;
                case '<':
                    state = 2;
                    break;
                case '=':
                    state = 7;
                    break;
                case '>':
                    state = 9;
                    break;
                case '!':
                    state = 11;
                    break;
                case '#':
                    state = 13;
                    break;
                case '_':
                    state = 23;
                    break;
                case ',':
                    state = 30;
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
                    lexemeBegin = forward;
                    lineNumber++;
                    state = 0;
                    break;
                case '\t':
                    lexemeBegin = forward;
                    state = 0;
                    break;
                case ' ':
                    lexemeBegin = forward;
                    state = 0;
                    break;
                case '\r':
                    lexemeBegin = forward;
                    state = 0;
                    break;
                case '@':
                    state = 40;
                    break;
                case '&':
                    state = 43;
                    break;
                default:
                    if (c >= '0' && c <= '9') {
                        state = 15;
                    } else if (c >= 'b' && c <= 'd') {
                        state = 26;
                    } else if (c >= 'a' && c <= 'z') {
                        state = 29;
                    } else {
                        // This should give the failure state
                        // Since none of the recognizable characters are taken
                        failure();
                        r = makeReturnToken(-1);
                        lexemeBegin = forward;
                        state = 0;
                        return r;
                    }
                    break;
                }
                break;
                // case 0 ends here
            case 1:
                // final state
                state = 0;
                tk = TK_NOT;
                // printToken(tk);
                r = makeReturnToken(tk);
                decrementForward(1);
                lexemeBegin = forward;
                return r;
                break;
                // case 1 ends here
            case 2:
                // final state
                tk = TK_LT;
                if (c == '=') {
                    state = 3;
                } else if (c == '-') {
                    state = 4;
                } else {
                    // printToken(tk);
                    r = makeReturnToken(tk);
                    state = 0;
                    decrementForward(1);
                    lexemeBegin = forward;
                    return r;
                }
                break;
                // case 2 ends here
            case 3:
                // final state
                tk = TK_LE;
                // printToken(tk);
                r = makeReturnToken(tk);
                state = 0;
                decrementForward(1);
                lexemeBegin = forward;
                return r;
                break;
                // case 3 ends here
            case 4:
                if (c == '-') {
                    state = 5;
                } else {
                    // other condition
                    failure();
                    r = makeReturnToken(-1);
                    state = 0;
                    decrementForward(1);
                    lexemeBegin = forward;
                    return r;
                }
                break;
                // case 4 ends here
            case 5:
                if (c == '-') {
                    state = 6;
                } else {
                    // other condition
                    failure();
                    state = 0;
                    decrementForward(1);
                    lexemeBegin = forward;
                    return makeReturnToken(-1);
                }
                break;
                // case 5 ends here
            case 6:
                // final state
                tk = TK_ASSIGNOP;
                // printToken(tk);
                r = makeReturnToken(tk);
                state = 0;
                decrementForward(1);
                lexemeBegin = forward;
                return r;
                break;
                // case 6 ends here
            case 7:
                if (c == '=') {
                    state = 8;
                } else {
                    // other condition
                    failure();
                    r = makeReturnToken(-1);
                    state = 0;
                    incrementLexemeBegin(1);
                    forward = lexemeBegin;
                    return r;
                }
                break;
                // case 7 ends here
            case 8:
                // final state
                tk = TK_EQ;
                // printToken(tk);
                r = makeReturnToken(tk);
                state = 0;
                decrementForward(1);
                lexemeBegin = forward;
                return r;
                break;
                // case 8 ends here
            case 9:
                // final state
                if (c == '=') {
                    state = 10;
                } else {
                    // other condition
                    state = 0;
                    tk = TK_GT;
                    // printToken(tk);
                    r = makeReturnToken(tk);
                    decrementForward(1);
                    lexemeBegin = forward;
                    return r;
                }
                break;
                // case 9 ends here
            case 10:
                // final state
                tk = TK_GE;
                // printToken(tk);
                r = makeReturnToken(tk);
                state = 0;
                decrementForward(1);
                lexemeBegin = forward;
                return r;
                break;
                // case 10 ends here
            case 11:
                if (c == '=') {
                    state = 12;
                } else {
                    // other condition
                    failure();
                    r = makeReturnToken(-1);
                    state = 0;
                    incrementLexemeBegin(1);
                    forward = lexemeBegin;
                    return r;
                }
                break;
                // case 11 ends here
            case 12:
                // final
                tk = TK_NE;
                // printToken(tk);
                r = makeReturnToken(tk);
                state = 0;
                decrementForward(1);
                lexemeBegin = forward;
                return r;
                break;
                // case 12 ends here
            case 13:
                if (c >= 'a' && c <= 'z') {
                    state = 14;
                } else {
                    // other condition
                    failure();
                    r = makeReturnToken(-1);
                    state = 0;
                    incrementLexemeBegin(1);
                    forward = lexemeBegin;
                    return r;
                }
                break;
                // case 13 ends here
            case 14:
                // final state
                if (c >= 'a' && c <= 'z') {
                    state = 14;
                } else {
                    // other condition
                    tk = TK_RUID;
                    // printToken(tk);
                    r = makeReturnToken(tk);
                    state = 0;
                    decrementForward(1);
                    lexemeBegin = forward;
                    return r;
                }
                break;
                // case 14 ends here
            case 15:
                // final state
                tk = TK_NUM;
                if (c >= '0' && c <= '9') {
                    state = 15;
                } else if (c == '.') {
                    state = 16;
                } else {
                    // other condition
                    // printToken(tk);
                    r = makeReturnToken(tk);
                    state = 0;
                    decrementForward(1);
                    lexemeBegin = forward;
                    return r;
                }
                break;
                // case 15 ends here
            case 16:
                if (c >= '0' && c <= '9') {
                    state = 17;
                } else {
                    failure();
                    r = makeReturnToken(-1);
                    state = 0;
                    decrementForward(2);
                    lexemeBegin = forward;
                    return r;
                }
                break;
                // case 16 ends here
            case 17:
                if (c >= '0' && c <= '9')
                    state = 18;
                else {
                    failure();
                    r = makeReturnToken(-1);
                    state = 0;
                    decrementForward(1);
                    lexemeBegin = forward;
                    return r;
                }
                // other condition
                break;
                // case 17 ends here
            case 18:
                tk = TK_RNUM;
                if (c == 'E')
                    state = 19;
                else {
                    // other condition
                    // printToken(tk);
                    r = makeReturnToken(tk);
                    state = 0;
                    decrementForward(1);
                    lexemeBegin = forward;
                    return r;
                }
                // final state
                break;
                // case 18 ends here
            case 19:
                if (c == '+' || c == '-') {
                    state = 20;
                } else if (c >= '0' && c <= '9') {
                    state = 21;
                } else {
                    // other condition
                    // printToken(tk);
                    r = makeReturnToken(tk);
                    failure();
                    state = 0;
                    while (*(forward) != 'E') {
                        decrementForward(1);
                    }

                    lexemeBegin = forward;
                    return r;
                }
                break;
                // case 19 ends here
            case 20:
                if (c >= '0' && c <= '9')
                    state = 21;
                else {
                    // other condition
                    // printToken(tk);
                    r = makeReturnToken(tk);
                    failure();
                    state = 0;
                    while (*(forward) != 'E') {
                        decrementForward(1);
                    }
                    lexemeBegin = forward;
                    return r;
                }
                break;
                // case 20 ends here
            case 21:
                if (c >= '0' && c <= '9')
                    state = 22;
                else {
                    // other condition
                    // printToken(tk);
                    // r = NULL;
                    r = makeReturnToken(tk);
                    failure();
                    state = 0;
                    while ((*(forward)) != 'E') {
                        decrementForward(1);
                    }
                    lexemeBegin = forward;
                    // if (r !=)
                    return r;
                }
                break;
                // case 21 ends here
            case 22:
                // final state
                tk = TK_RNUM;
                // printToken(tk);
                r = makeReturnToken(tk);
                state = 0;
                decrementForward(1);
                lexemeBegin = forward;
                return r;
                break;
                // case 22 ends here;
            case 23:
                if (c >= 'a' && c <= 'z')
                    state = 24;
                else if (c >= 'A' && c <= 'Z')
                    state = 24;
                else {
                    // other condition
                    failure();
                    r = makeReturnToken(-1);
                    state = 0;
                    incrementLexemeBegin(1);
                    forward = lexemeBegin;
                    return r;
                }
                break;
                // case 23 ends here
            case 24:
                if (c >= 'a' && c <= 'z')
                    state = 24;
                else if (c >= 'A' && c <= 'Z')
                    state = 24;
                else if (c >= '0' && c <= '9')
                    state = 25;
                else {
                    // other condition
                    tk = TK_FUNID;
                    char *m = getLexeme(lexemeBegin, forward);
                    char *m2 = (char *)malloc(sizeof(char) * 6);
                    m2 = "_main";
                    if (strcmp(m, m2) == 0) {
                        tk = TK_MAIN;
                    }
                    // printToken(tk);
                    r = makeReturnToken(tk);
                    state = 0;
                    decrementForward(1);
                    lexemeBegin = forward;
                    return r;
                }
                // final state
                break;
                // case 24 ends here
            case 25:
                if (c >= '0' && c <= '9')
                    state = 25;
                else {
                    // other condition
                    tk = TK_FUNID;
                    // printToken(tk);
                    r = makeReturnToken(tk);
                    state = 0;
                    decrementForward(1);
                    lexemeBegin = forward;
                    return r;
                }
                // final state
                break;
                // case 25 ends here
            case 26:
                if (c >= '2' && c <= '7') {
                    state = 27;
                } else if (c >= 'a' && c <= 'z') {
                    state = 29;
                } else {
                    // other condition
                    tk = TK_FIELDID;
                    char *str = (char *)malloc(sizeof(char) *
                                               (forward - lexemeBegin - 1));
                    str = strndup(getLexeme(lexemeBegin, forward),
                                  strlen(getLexeme(lexemeBegin, forward)));
                    Token tk2 = lookupTrie(trie, str);
                    if (tk2 != 0) {
                        tk = tk2;
                    }
                    // printToken(tk);
                    r = makeReturnToken(tk);
                    state = 0;
                    decrementForward(1);
                    lexemeBegin = forward;
                    return r;
                }
                // final state
                break;
                // case 26 ends here
            case 27:
                if (c >= 'b' && c <= 'd')
                    state = 27;
                else if (c >= '2' && c <= '7')
                    state = 28;
                else {
                    // other condition
                    tk = TK_ID;
                    // printToken(tk);
                    r = makeReturnToken(tk);
                    state = 0;
                    decrementForward(1);
                    lexemeBegin = forward;
                    return r;
                }
                // final state
                break;
                // case 27 ends here
            case 28:
                if (c >= '2' && c <= '7')
                    state = 28;
                else {
                    // other condition
                    tk = TK_ID;
                    // printToken(tk);
                    r = makeReturnToken(tk);
                    state = 0;
                    decrementForward(1);
                    lexemeBegin = forward;
                    return r;
                }
                // final state
                break;
                // case 28 ends here
            case 29:
                if (c >= 'a' && c <= 'z')
                    state = 29;
                else {
                    // other condition
                    tk = TK_FIELDID;
                    char *str = (char *)malloc(sizeof(char) *
                                               (forward - lexemeBegin - 1));
                    str = strndup(getLexeme(lexemeBegin, forward),
                                  strlen(getLexeme(lexemeBegin, forward)));
                    Token tk2 = lookupTrie(trie, str);
                    if (tk2 != 0) {
                        tk = tk2;
                    }
                    // printToken(tk);
                    r = makeReturnToken(tk);
                    state = 0;
                    decrementForward(1);
                    lexemeBegin = forward;
                    return r;
                }
                // final state
                break;
                // case 29 ends here
            case 30:
                // final state
                state = 0;
                tk = TK_COMMA;
                // printToken(tk);
                r = makeReturnToken(tk);
                decrementForward(1);
                lexemeBegin = forward;
                return r;
                break;
            case 31:
                // final state
                state = 0;
                tk = TK_SEM;
                // printToken(tk);
                r = makeReturnToken(tk);
                decrementForward(1);
                lexemeBegin = forward;
                return r;
                break;
            case 32:
                // final state
                state = 0;
                tk = TK_SQL;
                // printToken(tk);
                r = makeReturnToken(tk);
                decrementForward(1);
                lexemeBegin = forward;
                return r;
                break;
            case 33:
                // final state
                state = 0;
                tk = TK_SQR;
                // printToken(tk);
                r = makeReturnToken(tk);
                decrementForward(1);
                lexemeBegin = forward;
                return r;
                break;
            case 34:
                // final state
                state = 0;
                tk = TK_OP;
                // printToken(tk);
                r = makeReturnToken(tk);
                decrementForward(1);
                lexemeBegin = forward;
                return r;
                break;
            case 35:
                // final state
                state = 0;
                tk = TK_CL;
                // printToken(tk);
                r = makeReturnToken(tk);
                decrementForward(1);
                lexemeBegin = forward;
                return r;
                break;
            case 36:
                // final state
                state = 0;
                tk = TK_PLUS;
                // printToken(tk);
                r = makeReturnToken(tk);
                decrementForward(1);
                lexemeBegin = forward;
                return r;
                break;
            case 37:
                // final state
                state = 0;
                tk = TK_MINUS;
                // printToken(tk);
                r = makeReturnToken(tk);
                decrementForward(1);
                lexemeBegin = forward;
                return r;
                break;
            case 38:
                // final state
                state = 0;
                tk = TK_MUL;
                // printToken(tk);
                r = makeReturnToken(tk);
                decrementForward(1);
                lexemeBegin = forward;
                return r;
                break;
            case 39:
                // final state
                state = 0;
                tk = TK_DIV;
                // printToken(tk);
                r = makeReturnToken(tk);
                decrementForward(1);
                lexemeBegin = forward;
                return r;
                break;
            case 40:
                if (c == '@') {
                    state = 41;
                } else {
                    failure();
                    r = makeReturnToken(-1);
                    state = 0;
                    incrementLexemeBegin(1);
                    forward = lexemeBegin;
                    return r;
                }
                break;
                // case 40 ends here
            case 41:
                if (c == '@') {
                    state = 42;
                } else {
                    // other condition
                    failure();
                    r = makeReturnToken(-1);
                    state = 0;
                    incrementLexemeBegin(1);
                    forward = lexemeBegin;
                    return r;
                }
                break;
                // case 41 ends here
            case 42:
                // final state
                tk = TK_OR;
                // printToken(tk);
                r = makeReturnToken(tk);
                state = 0;
                decrementForward(1);
                lexemeBegin = forward;
                return r;
                break;
            case 43:
                if (c == '&') {
                    state = 44;
                } else {
                    // other condition
                    failure();
                    r = makeReturnToken(-1);
                    state = 0;
                    incrementLexemeBegin(1);
                    forward = lexemeBegin;
                    return r;
                }
                break;
            case 44:
                if (c == '&') {
                    state = 45;
                } else {
                    // other condition
                    failure();
                    r = makeReturnToken(-1);
                    state = 0;
                    incrementLexemeBegin(2);
                    forward = lexemeBegin;
                    return r;
                }
                break;
            case 45:
                // final state
                tk = TK_AND;
                // printToken(tk);
                r = makeReturnToken(tk);
                state = 0;
                decrementForward(1);
                lexemeBegin = forward;
                return r;
                break;
            case 46:
                // final state
                state = 0;
                tk = TK_COLON;
                // printToken(tk);
                r = makeReturnToken(tk);
                decrementForward(1);
                lexemeBegin = forward;
                return r;
                break;
            case 47:
                // final state
                state = 0;
                tk = TK_DOT;
                // printToken(tk);
                r = makeReturnToken(tk);
                decrementForward(1);
                lexemeBegin = forward;
                return r;
                break;
            default:
                return makeReturnToken(-1);
                break;
            }
        }
        // r.flag = -1;
        // return r;
    }
}

void printTokens() {
    // lexemeBegin = (char *)malloc(sizeof(char));
    // forward = (char *)malloc(sizeof(char));
    // lexemeBegin = buf1;
    // forward = buf1;
    // state = 0;
    // lineNumber = 1;
    // trie = populateTrie();
    // returnToken* r = malloc (sizeof(returnToken));
    // *r = getNextToken();
    // int ind = 1;
    // // printf("Print called \n");
    // while (r->flag != -2 && ind < 100) {
    //     // printf("r\n");
    //     ind = ind*2;
    //     // printf("%d\n", ind);
    //     // printf("Line %d, %s", r->line, r->lexeme);
    //     *r = getNextToken();
    // }
    while (1) {
        returnToken r = getNextToken();
        if (r.t == 58) {
            int fuckyoumf = 69;
        }
        printf("line %d\t token %d\t lexeme %s\n", r.line, r.t, r.lexeme);
        if (r.flag == -2) {
            break;
        }
    }
}

void initLexer(char *fileName) {
    initializeBuffers(fileName);
    lexemeBegin = (char *)malloc(sizeof(char));
    forward = (char *)malloc(sizeof(char));
    lexemeBegin = buf1;
    forward = buf1;
    state = 0;
    lineNumber = 1;
    trie = populateTrie();
}

// int main()
// {
//     FILE *fp1 = (FILE *)malloc(sizeof(FILE));
//     fp1 = fopen("t1.txt", "r");
//     FILE *fp2 = (FILE *)malloc(sizeof(FILE));
//     fp2 = fopen("WithoutComments.txt", "w+");
//     removeComments(fp1, fp2);
//     fclose(fp1);
//     fclose(fp2);
//     initializeBuffers();
//     printTokens();
// }