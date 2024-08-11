#ifndef PARSERDEF_H
#define PARSERDEF_H

#include "lexer.h"
#include "lexerDef.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_TERMS 58
#define NUM_NONTERMS 53
#define NUM_ELEMENTS 113

enum Elements {
    program,
    mainFunction,
    otherFunctions,
    function,
    input_par,
    output_par,
    parameter_list,
    dataType,
    primitiveDatatype,
    constructedDatatype,
    remaining_list,
    stmts,
    typeDefinitions,
    actualOrRedefined,
    typeDefinition,
    fieldDefinitions,
    fieldDefinition,
    fieldType,
    moreFields,
    declarations,
    declaration,
    global_or_not,
    otherStmts,
    stmt,
    assignmentStmt,
    singleOrRecId,
    option_single_constructed,
    oneExpansion,
    moreExpansions,
    funCallStmt,
    outputParameters,
    inputParameters,
    iterativeStmt,
    conditionalStmt,
    elsePart,
    ioStmt,
    arithmeticExpression,
    expPrime,
    term,
    termPrime,
    factor,
    highPrecedenceOperator,
    lowPrecedenceOperators,
    booleanExpression,
    var,
    logicalOp,
    relationalOp,
    returnStmt,
    optionalReturn,
    idList,
    more_ids,
    definetypestmt,
    A,
    T_NULL,
    T_ASSIGNOP,
    T_COMMENT,
    T_FIELDID,
    T_ID,
    T_NUM,
    T_RNUM,
    T_FUNID,
    T_RUID,
    T_WITH,
    T_PARAMETERS,
    T_END,
    T_WHILE,
    T_UNION,
    T_ENDUNION,
    T_DEFINETYPE,
    T_AS,
    T_TYPE,
    T_MAIN,
    T_GLOBAL,
    T_PARAMETER,
    T_LIST,
    T_SQL,
    T_SQR,
    T_INPUT,
    T_OUTPUT,
    T_INT,
    T_REAL,
    T_COMMA,
    T_SEM,
    T_COLON,
    T_DOT,
    T_ENDWHILE,
    T_OP,
    T_CL,
    T_IF,
    T_THEN,
    T_ENDIF,
    T_READ,
    T_WRITE,
    T_RETURN,
    T_PLUS,
    T_MINUS,
    T_MUL,
    T_DIV,
    T_CALL,
    T_RECORD,
    T_ENDRECORD,
    T_ELSE,
    T_AND,
    T_OR,
    T_NOT,
    T_LT,
    T_LE,
    T_EQ,
    T_GT,
    T_GE,
    T_NE,
    T_DOLLAR,
    T_EPSILON
};
typedef enum Elements Elements;

typedef struct NodeEle {
    Elements item;
    struct NodeEle *next;
} node_Ele;
typedef node_Ele *NODE_ELE;

typedef struct LinkedListEle {
    NODE_ELE head;
    int count;
} ll_ele;
typedef ll_ele *LL_ELE;

typedef struct NodeLL {
    LL_ELE item;
    struct NodeLL *next;
} node_LL;
typedef node_LL *NODE_LL;

typedef struct LinkedListLL {
    NODE_LL head;
    int count;
} ll_ll;
typedef ll_ll *LL_LL;

struct Stack {
    LL_ELE list;
};
typedef struct Stack Stack;

typedef struct grammar {
    LL_LL rules[NUM_NONTERMS];
} grammar;
typedef grammar *GRAMMAR;

typedef struct FirstAndFollow {
    LL_ELE firstSet[NUM_ELEMENTS];
    LL_ELE followSet[NUM_NONTERMS];
} FirstAndFollow;

typedef struct FirstAndFollow *FIRSTANDFOLLOW;

struct ProdRule {
    Elements LHS;
    Elements RHS[10];
    int count_rhs;
};
typedef struct ProdRule ProdRule;

struct TreeNode {
    Elements x;     // NodeSymbol
    int lineNumber; // lineno
    char *value;    // ValueIfNumber
    char *lexeme;   // lexeme

    struct TreeNode *children[10];
    struct TreeNode *parent; // ParentNodeSymbol
    int count_children;      // isLeafNode
};
typedef struct TreeNode TreeNode;
typedef TreeNode *TREE_NODE;

#endif