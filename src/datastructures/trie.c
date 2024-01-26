#include<stdio.h>
#include<stdlib.h>
#include<string.h>

enum Token {TK_NULL, TK_ASSIGNOP, TK_COMMENT, TK_FIELDID, TK_ID, TK_NUM, TK_RNUM, TK_FUNID, TK_RUID, TK_WITH, TK_PARAMETERS, TK_END, TK_WHILE, TK_UNION, TK_ENDUNION, TK_DEFINETYPE, TK_AS, TK_TYPE, TK_MAIN, TK_GLOBAL, TK_PARAMETER, TK_LIST, TK_SQL, TK_SQR, TK_INPUT, TK_OUTPUT, TK_INT, TK_REAL, TK_COMMA, TK_SEM, TK_COLON, TK_DOT, TK_ENDWHILE, TK_OP, TK_CL, TK_IF, TK_THEN, TK_ENDIF, TK_READ, TK_WRITE, TK_RETURN, TK_PLUS, TK_MINUS, TK_MUL, TK_DIV, TK_CALL, TK_RECORD, TK_ENDRECORD, TK_ELSE, TK_AND, TK_OR, TK_NOT, TK_LT, TK_LE, TK_EQ, TK_GT, TK_GE, TK_NE};

typedef struct Trie * TRIE;

struct Trie{
    char c;
    TRIE next[26];
    enum Token tk;
};

void insertIntoTrie(TRIE root, char* word, enum Token tk){
    TRIE current = root;
    // int i = 0;
    // while(word[i] != '\0'){
    // printf("%lu\n", sizeof(word)/sizeof(char));
    // printf("%lu\n", strlen(word));
    for(int i = 0; i<strlen(word); i++){
        if(current->next[word[i] - 'a'] == NULL){
            current->next[word[i] - 'a'] = (TRIE)malloc(sizeof(struct Trie));
            current->next[word[i] - 'a']->c = word[i];
            for(int j = 0; j<26; j++){
                current->next[word[i]-'a']->next[j] = NULL;
            }
        }
        
        current = current->next[word[i] - 'a'];
        if(i == strlen(word) - 1){
            current->tk = tk;
        }
    }
    // }
}



TRIE populateTrie(){
    TRIE root = (TRIE)malloc(sizeof(struct Trie));
    root->c = '`';
    for(int i = 0; i<26; i++){
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

enum Token lookupTrie(TRIE root, char* word){
    TRIE current = root;
    for(int i = 0; i<strlen(word); i++){
        if(current->next[word[i]-'a'] == NULL){
            return TK_NULL;
        }
        else current = current->next[word[i] - 'a'];
        if(i == strlen(word) - 1){
            return current->tk;
        }
    }
}

int main(){
    TRIE root = populateTrie();
    // char * str = (char*)malloc(sizeof(char)*20);
    // insertIntoTrie(root, "while", TK_WHILE);
    // populateTrie();
    // printf("%lu\n", sizeof("while"));
    // printf("%d\n", sizeof("qwertyuiop"));
    printf("%d\n", lookupTrie(root, "thene"));
}