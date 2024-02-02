#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "../../include/tokens/tokens.h"
#include "../../include/datastructures/trie.h"


void insertIntoTrie(TRIE root, char* word, enum Token tk){
    TRIE current = root;

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