#ifndef LINKED_LIST_PARSER
#define LINKED_LIST_PARSER

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
    struct NodeEle* next;
} node_Ele;

typedef node_Ele* NODE_ELE;
typedef struct LinkedListEle {
    NODE_ELE head;
    int count;
} ll_ele;
typedef ll_ele* LL_ELE;

typedef struct NodeLL {
    LL_ELE item;
    struct NodeLL* next;
} node_LL;
typedef node_LL* NODE_LL;
typedef struct LinkedListLL {
    NODE_LL head;
    int count;
} ll_ll;
typedef ll_ll* LL_LL;

LL_LL createNewList_LL();
NODE_LL createNewNode_LL(LL_ELE data);
void freeNode_LL(NODE_LL node);
void insertNode_LLFirst(NODE_LL node, LL_LL list);
void insertNode_LLLast(NODE_LL node, LL_LL list);
void removeNode_LLFirst(LL_LL list);
void removeNode_LLLast(LL_LL list);
void freeLL_LL(LL_LL list);

LL_ELE createNewList_Ele();
NODE_ELE createNewNode_Ele(Elements data);
void freeNode_Ele(NODE_ELE node);
void insertNode_EleFirst(NODE_ELE node, LL_ELE list);
void insertNode_EleLast(NODE_ELE node, LL_ELE list);
void removeNode_EleFirst(LL_ELE list);
void removeNode_EleLast(LL_ELE list);
void freeLL_ELE(LL_ELE list);

#endif
