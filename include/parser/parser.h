#ifndef PARSER_H
#define PARSER_H

#include "grammar.h"
#include "datastructures/linked_list.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_NONTERMS 53
#define NUM_ELEMENTS 112

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
    T_EPSILON,
    T_DOLLAR
};

typedef enum Elements Elements;

void trim(char *str);
Elements stringToEnum(char *str);
void printHEHE(LL_LL eqn);
void printFirollow(FIRSTANDFOLLOW fnf, Elements id);
GRAMMAR parseFile(char *filename);
int checkEpsilonInFirst(LL_ELE first);
void ComputeFirst(GRAMMAR G, FIRSTANDFOLLOW firstAndFollowSet);
void ComputeFollow(GRAMMAR G, FIRSTANDFOLLOW firstAndFollowSet);

Elements *computeFirstSpecial(ProdRule rule);
Elements *computeFollowSpecial(ProdRule rule);

FIRSTANDFOLLOW ComputeFirstAndFollowSets(GRAMMAR G);




#endif