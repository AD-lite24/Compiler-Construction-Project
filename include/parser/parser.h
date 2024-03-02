#ifndef PARSER_H
#define PARSER_H

#include "datastructures/linked_list_parser.h"
#include "datastructures/stack_parser.h"
#include "lexer/lexer.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_TERMS 58
#define NUM_NONTERMS 53
#define NUM_ELEMENTS 113


typedef struct grammar {
    LL_LL rules[NUM_NONTERMS];
} grammar;
typedef grammar *GRAMMAR;

GRAMMAR grammar_glob;

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

ProdRule ParseTable[NUM_NONTERMS][NUM_TERMS+1];
struct TreeNode {
    Elements x; //NodeSymbol
    int lineNumber; // lineno
    double value; // ValueIfNumber
    char * lexeme; // lexeme

    struct TreeNode * children[10];
    struct TreeNode * parent; // ParentNodeSymbol
    int count_children; // isLeafNode
};

typedef struct TreeNode TreeNode;
typedef TreeNode *TREE_NODE;

char *arrElemCauseCheck[] = {"program",
                             "mainFunction",
                             "otherFunctions",
                             "function",
                             "input_par",
                             "output_par",
                             "parameter_list",
                             "dataType",
                             "primitiveDatatype",
                             "constructedDatatype",
                             "remaining_list",
                             "stmts",
                             "typeDefinitions",
                             "actualOrRedefined",
                             "typeDefinition",
                             "fieldDefinitions",
                             "fieldDefinition",
                             "fieldType",
                             "moreFields",
                             "declarations",
                             "declaration",
                             "global_or_not",
                             "otherStmts",
                             "stmt",
                             "assignmentStmt",
                             "singleOrRecId",
                             "option_single_constructed",
                             "oneExpansion",
                             "moreExpansions",
                             "funCallStmt",
                             "outputParameters",
                             "inputParameters",
                             "iterativeStmt",
                             "conditionalStmt",
                             "elsePart",
                             "ioStmt",
                             "arithmeticExpression",
                             "expPrime",
                             "term",
                             "termPrime",
                             "factor",
                             "highPrecedenceOperator",
                             "lowPrecedenceOperators",
                             "booleanExpression",
                             "var",
                             "logicalOp",
                             "relationalOp",
                             "returnStmt",
                             "optionalReturn",
                             "idList",
                             "more_ids",
                             "definetypestmt",
                             "A",
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
                             "TK_NE",
                             "TK_DOLLAR",
                             "TK_EPSILON"
};

Elements stringToEnum(char *str);
void parseFile(char *filename);
int checkEpsilonInFirst(LL_ELE first);
void ComputeFirst(FIRSTANDFOLLOW firstAndFollowSet);
void ComputeFollow(FIRSTANDFOLLOW firstAndFollowSet);

FIRSTANDFOLLOW ComputeFirstAndFollowSets();

ProdRule convertLLtoProd(Elements lhs, NODE_LL rule);
void initialiseParseTable();
void entryIntoParseTable(FIRSTANDFOLLOW F, Elements lhs, ProdRule rule);
void createParseTable(FIRSTANDFOLLOW F);
TREE_NODE createTreeNode(Elements x,TREE_NODE parent);
void createParseTree(Stack * st,TREE_NODE root,int flag);
TREE_NODE parseInputSourceCode();
void printParseTree(TREE_NODE root, char *outfile);

#endif