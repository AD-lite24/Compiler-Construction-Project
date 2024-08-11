#include "parserDef.h"
#include <time.h>
#include <unistd.h>

extern GRAMMAR grammar_glob;
// extern ParseTable
extern ProdRule ParseTable[NUM_NONTERMS][NUM_TERMS + 1];

LL_LL createNewList_LL() {
    LL_LL list = malloc(sizeof(ll_ll));
    list->head = NULL;
    list->count = 0;
    return list;
}
NODE_LL createNewNode_LL(LL_ELE data) {
    NODE_LL new_node = malloc(sizeof(node_LL));
    new_node->next = NULL;
    new_node->item = data;
    return new_node;
}
void insertNode_LLFirst(NODE_LL node, LL_LL list) {
    node->next = list->head;
    list->head = node;
    list->count++;
}
void insertNode_LLLast(NODE_LL node, LL_LL list) {
    if (!node || !list)
        return;

    if (list->head == NULL)
        list->head = node;
    else {
        NODE_LL temp = list->head;
        while (temp->next)
            temp = temp->next;
        temp->next = node;
    }
    node->next = NULL;
    list->count++;
}
void freeNode_LL(NODE_LL node) { free(node); }
void removeNode_LLFirst(LL_LL list) {
    if (!list->head)
        return;

    NODE_LL temp = list->head->next;
    NODE_LL rem = list->head;
    list->head = temp;
    rem->next = NULL;
    list->count--;
    freeNode_LL(rem);
}
void removeNode_LLLast(LL_LL list) {
    if (!list->head)
        return;

    NODE_LL temp = list->head;
    NODE_LL prev;
    while (temp->next) {
        prev = temp;
        temp = temp->next;
    }
    prev->next = NULL;
    freeNode_LL(temp);
    list->count--;
}
void freeLL_LL(LL_LL list) {
    NODE_LL current = list->head;
    NODE_LL next;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
    free(list);
}

LL_ELE createNewList_Ele() {
    LL_ELE list = malloc(sizeof(ll_ele));
    list->head = NULL;
    list->count = 0;
    return list;
}
NODE_ELE createNewNode_Ele(Elements data) {
    NODE_ELE new_node = malloc(sizeof(node_Ele));
    new_node->next = NULL;
    new_node->item = data;
    return new_node;
}
void insertNode_EleFirst(NODE_ELE node, LL_ELE list) {
    node->next = list->head;
    list->head = node;
    list->count++;
}
void insertNode_EleLast(NODE_ELE node, LL_ELE list) {
    if (!node || !list)
        return;

    if (list->head == NULL)
        list->head = node;
    else {
        NODE_ELE temp = list->head;
        while (temp->next)
            temp = temp->next;
        temp->next = node;
    }
    node->next = NULL;
    list->count++;
}
void freeNode_Ele(NODE_ELE node) { free(node); }
void removeNode_EleFirst(LL_ELE list) {
    if (!list->head)
        return;

    NODE_ELE temp = list->head->next;
    NODE_ELE rem = list->head;
    list->head = temp;
    rem->next = NULL;
    list->count--;
    freeNode_Ele(rem);
}
// void removeNode_EleLast(LL_ELE list) {
//     if (!list->head)
//         return;

//     NODE_ELE temp = list->head;
//     NODE_ELE prev;
//     while (temp->next) {
//         prev = temp;
//         temp = temp->next;
//     }
//     prev->next = NULL;
//     freeNode_Ele(temp);
//     list->count--;
// }
void freeLL_ELE(LL_ELE list) {
    NODE_ELE current = list->head;
    NODE_ELE next;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
    free(list);
}

Stack *createStack() {
    Stack *st = (Stack *)malloc(sizeof(Stack));
    st->list = createNewList_Ele();
    return st;
}

void push(Stack *st, Elements element) {

    NODE_ELE node = createNewNode_Ele(element);
    insertNode_EleFirst(node, st->list);
}

Elements top(Stack *st) { return ((st->list)->head)->item; }

void pop(Stack *st) {
    if (!st || st->list->count <= 1 || !st->list) {
        return;
    } else {
        removeNode_EleFirst(st->list);
    }
}

bool isEmpty(Stack *st) {
    if (st->list->count == 0)
        return true;
    else
        return false;
}

void synchPopulateParseTable(FIRSTANDFOLLOW Fnf) {
    Elements arr[] = {T_ID,   T_FUNID,  T_RUID, T_WHILE, T_UNION, T_DEFINETYPE,
                      T_TYPE, T_MAIN,   T_IF,   T_READ,  T_WRITE, T_RETURN,
                      T_CALL, T_RECORD, T_THEN, T_ELSE};
    for (int i = 0; i < NUM_NONTERMS; i++) {
        NODE_ELE ptr = Fnf->followSet[i]->head;
        while (ptr != NULL) {
            if (ParseTable[i][ptr->item - NUM_NONTERMS].LHS == T_NULL)
                ParseTable[i][ptr->item - NUM_NONTERMS].count_rhs = -1;
            ptr = ptr->next;
        }
        for (int j = 0; j < 16; j++) {
            if (ParseTable[i][arr[j] - NUM_NONTERMS].LHS == T_NULL)
                ParseTable[i][arr[j] - NUM_NONTERMS].count_rhs = -1;
        }
    }
}

char *enumToString[] = {"program",
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
                        "TK_EPSILON"};

// void printStack(Stack *st) {
//     NODE_ELE x = st->list->head;
//     while (x) {
//         printf("%s\n", enumToString[x->item]);
//         x = x->next;
//     }
// }

Elements stringToEnum(char *str) {
    if (strcmp(str, "TK_NULL") == 0) {
        return T_NULL;
    } else if (strcmp(str, "TK_ASSIGNOP") == 0) {
        return T_ASSIGNOP;
    } else if (strcmp(str, "TK_COMMENT") == 0) {
        return T_COMMENT;
    } else if (strcmp(str, "TK_FIELDID") == 0) {
        return T_FIELDID;
    } else if (strcmp(str, "TK_ID") == 0) {
        return T_ID;
    } else if (strcmp(str, "TK_NUM") == 0) {
        return T_NUM;
    } else if (strcmp(str, "TK_RNUM") == 0) {
        return T_RNUM;
    } else if (strcmp(str, "TK_FUNID") == 0) {
        return T_FUNID;
    } else if (strcmp(str, "TK_RUID") == 0) {
        return T_RUID;
    } else if (strcmp(str, "TK_WITH") == 0) {
        return T_WITH;
    } else if (strcmp(str, "TK_PARAMETERS") == 0) {
        return T_PARAMETERS;
    } else if (strcmp(str, "TK_END") == 0) {
        return T_END;
    } else if (strcmp(str, "TK_WHILE") == 0) {
        return T_WHILE;
    } else if (strcmp(str, "TK_UNION") == 0) {
        return T_UNION;
    } else if (strcmp(str, "TK_ENDUNION") == 0) {
        return T_ENDUNION;
    } else if (strcmp(str, "TK_DEFINETYPE") == 0) {
        return T_DEFINETYPE;
    } else if (strcmp(str, "TK_AS") == 0) {
        return T_AS;
    } else if (strcmp(str, "TK_TYPE") == 0) {
        return T_TYPE;
    } else if (strcmp(str, "TK_MAIN") == 0) {
        return T_MAIN;
    } else if (strcmp(str, "TK_GLOBAL") == 0) {
        return T_GLOBAL;
    } else if (strcmp(str, "TK_PARAMETER") == 0) {
        return T_PARAMETER;
    } else if (strcmp(str, "TK_LIST") == 0) {
        return T_LIST;
    } else if (strcmp(str, "TK_SQL") == 0) {
        return T_SQL;
    } else if (strcmp(str, "TK_SQR") == 0) {
        return T_SQR;
    } else if (strcmp(str, "TK_INPUT") == 0) {
        return T_INPUT;
    } else if (strcmp(str, "TK_OUTPUT") == 0) {
        return T_OUTPUT;
    } else if (strcmp(str, "TK_INT") == 0) {
        return T_INT;
    } else if (strcmp(str, "TK_REAL") == 0) {
        return T_REAL;
    } else if (strcmp(str, "TK_COMMA") == 0) {
        return T_COMMA;
    } else if (strcmp(str, "TK_SEM") == 0) {
        return T_SEM;
    } else if (strcmp(str, "TK_COLON") == 0) {
        return T_COLON;
    } else if (strcmp(str, "TK_DOT") == 0) {
        return T_DOT;
    } else if (strcmp(str, "TK_ENDWHILE") == 0) {
        return T_ENDWHILE;
    } else if (strcmp(str, "TK_OP") == 0) {
        return T_OP;
    } else if (strcmp(str, "TK_CL") == 0) {
        return T_CL;
    } else if (strcmp(str, "TK_IF") == 0) {
        return T_IF;
    } else if (strcmp(str, "TK_THEN") == 0) {
        return T_THEN;
    } else if (strcmp(str, "TK_ENDIF") == 0) {
        return T_ENDIF;
    } else if (strcmp(str, "TK_READ") == 0) {
        return T_READ;
    } else if (strcmp(str, "TK_WRITE") == 0) {
        return T_WRITE;
    } else if (strcmp(str, "TK_RETURN") == 0) {
        return T_RETURN;
    } else if (strcmp(str, "TK_PLUS") == 0) {
        return T_PLUS;
    } else if (strcmp(str, "TK_MINUS") == 0) {
        return T_MINUS;
    } else if (strcmp(str, "TK_MUL") == 0) {
        return T_MUL;
    } else if (strcmp(str, "TK_DIV") == 0) {
        return T_DIV;
    } else if (strcmp(str, "TK_CALL") == 0) {
        return T_CALL;
    } else if (strcmp(str, "TK_RECORD") == 0) {
        return T_RECORD;
    } else if (strcmp(str, "TK_ENDRECORD") == 0) {
        return T_ENDRECORD;
    } else if (strcmp(str, "TK_ELSE") == 0) {
        return T_ELSE;
    } else if (strcmp(str, "TK_AND") == 0) {
        return T_AND;
    } else if (strcmp(str, "TK_OR") == 0) {
        return T_OR;
    } else if (strcmp(str, "TK_NOT") == 0) {
        return T_NOT;
    } else if (strcmp(str, "TK_LT") == 0) {
        return T_LT;
    } else if (strcmp(str, "TK_LE") == 0) {
        return T_LE;
    } else if (strcmp(str, "TK_EQ") == 0) {
        return T_EQ;
    } else if (strcmp(str, "TK_GT") == 0) {
        return T_GT;
    } else if (strcmp(str, "TK_GE") == 0) {
        return T_GE;
    } else if (strcmp(str, "TK_NE") == 0) {
        return T_NE;
    } else if (strcmp(str, "TK_EPSILON") == 0) {
        return T_EPSILON;
    } else if (strcmp(str, "TK_DOLLAR") == 0) {
        return T_DOLLAR;
    } else if (strcmp(str, "program") == 0) {
        return program;
    } else if (strcmp(str, "mainFunction") == 0) {
        return mainFunction;
    } else if (strcmp(str, "otherFunctions") == 0) {
        return otherFunctions;
    } else if (strcmp(str, "function") == 0) {
        return function;
    } else if (strcmp(str, "input_par") == 0) {
        return input_par;
    } else if (strcmp(str, "output_par") == 0) {
        return output_par;
    } else if (strcmp(str, "parameter_list") == 0) {
        return parameter_list;
    } else if (strcmp(str, "dataType") == 0) {
        return dataType;
    } else if (strcmp(str, "primitiveDatatype") == 0) {
        return primitiveDatatype;
    } else if (strcmp(str, "constructedDatatype") == 0) {
        return constructedDatatype;
    } else if (strcmp(str, "remaining_list") == 0) {
        return remaining_list;
    } else if (strcmp(str, "stmts") == 0) {
        return stmts;
    } else if (strcmp(str, "typeDefinitions") == 0) {
        return typeDefinitions;
    } else if (strcmp(str, "actualOrRedefined") == 0) {
        return actualOrRedefined;
    } else if (strcmp(str, "typeDefinition") == 0) {
        return typeDefinition;
    } else if (strcmp(str, "fieldDefinitions") == 0) {
        return fieldDefinitions;
    } else if (strcmp(str, "fieldDefinition") == 0) {
        return fieldDefinition;
    } else if (strcmp(str, "fieldType") == 0) {
        return fieldType;
    } else if (strcmp(str, "moreFields") == 0) {
        return moreFields;
    } else if (strcmp(str, "declarations") == 0) {
        return declarations;
    } else if (strcmp(str, "declaration") == 0) {
        return declaration;
    } else if (strcmp(str, "global_or_not") == 0) {
        return global_or_not;
    } else if (strcmp(str, "otherStmts") == 0) {
        return otherStmts;
    } else if (strcmp(str, "stmt") == 0) {
        return stmt;
    } else if (strcmp(str, "stmt") == 0) {
        return stmt;
    } else if (strcmp(str, "assignmentStmt") == 0) {
        return assignmentStmt;
    } else if (strcmp(str, "singleOrRecId") == 0) {
        return singleOrRecId;
    } else if (strcmp(str, "option_single_constructed") == 0) {
        return option_single_constructed;
    } else if (strcmp(str, "oneExpansion") == 0) {
        return oneExpansion;
    } else if (strcmp(str, "moreExpansions") == 0) {
        return moreExpansions;
    } else if (strcmp(str, "funCallStmt") == 0) {
        return funCallStmt;
    } else if (strcmp(str, "outputParameters") == 0) {
        return outputParameters;
    } else if (strcmp(str, "inputParameters") == 0) {
        return inputParameters;
    } else if (strcmp(str, "iterativeStmt") == 0) {
        return iterativeStmt;
    } else if (strcmp(str, "conditionalStmt") == 0) {
        return conditionalStmt;
    } else if (strcmp(str, "elsePart") == 0) {
        return elsePart;
    } else if (strcmp(str, "ioStmt") == 0) {
        return ioStmt;
    } else if (strcmp(str, "arithmeticExpression") == 0) {
        return arithmeticExpression;
    } else if (strcmp(str, "expPrime") == 0) {
        return expPrime;
    } else if (strcmp(str, "term") == 0) {
        return term;
    } else if (strcmp(str, "termPrime") == 0) {
        return termPrime;
    } else if (strcmp(str, "factor") == 0) {
        return factor;
    } else if (strcmp(str, "highPrecedenceOperator") == 0) {
        return highPrecedenceOperator;
    } else if (strcmp(str, "lowPrecedenceOperators") == 0) {
        return lowPrecedenceOperators;
    } else if (strcmp(str, "booleanExpression") == 0) {
        return booleanExpression;
    } else if (strcmp(str, "var") == 0) {
        return var;
    } else if (strcmp(str, "logicalOp") == 0) {
        return logicalOp;
    } else if (strcmp(str, "relationalOp") == 0) {
        return relationalOp;
    } else if (strcmp(str, "returnStmt") == 0) {
        return returnStmt;
    } else if (strcmp(str, "optionalReturn") == 0) {
        return optionalReturn;
    } else if (strcmp(str, "idList") == 0) {
        return idList;
    } else if (strcmp(str, "more_ids") == 0) {
        return more_ids;
    } else if (strcmp(str, "definetypestmt") == 0) {
        return definetypestmt;
    } else if (strcmp(str, "A") == 0) {
        return A;
    }
    return -1;
}

void parseFile(char *filename) {
    FILE *fp = fopen(filename, "r");
    if (!fp) {
        printf("Error in opening file\n");
        return;
    }
    for (int i = 0; i < NUM_NONTERMS; i++) {
        grammar_glob->rules[i] = createNewList_LL();
    }
    char buff[1024];
    while (fgets(buff, 1024, fp) != NULL) {
        Elements tempArr[15];
        for (int i = 0; i < 15; i++)
            tempArr[i] = T_NULL;
        // memset(tempArr, -1, sizeof(tempArr));
        char delim1[] = " ";
        char delim2[] = "\n";

        char *fullLine = strtok(buff, delim2);
        char *firstptr = strtok(fullLine, delim1);
        int LHS_NonTerm = stringToEnum(firstptr);
        firstptr = strtok(NULL, delim1);
        firstptr = strtok(NULL, delim1);
        LL_ELE curr = createNewList_Ele();
        while (firstptr) {
            if (firstptr[0] == ';') {
                insertNode_LLLast(createNewNode_LL(curr),
                                  grammar_glob->rules[LHS_NonTerm]);
                curr = createNewList_Ele();
                firstptr = strtok(NULL, delim1);
                continue;
            }
            NODE_ELE one = createNewNode_Ele(stringToEnum(firstptr));
            insertNode_EleLast(one, curr);
            firstptr = strtok(NULL, delim1);
        }
        insertNode_LLLast(createNewNode_LL(curr),
                          grammar_glob->rules[LHS_NonTerm]);
    }
    fclose(fp);
    return;
}

int checkEpsilonInFirst(LL_ELE first) {
    NODE_ELE ptr = first->head;
    while (ptr != NULL) {
        if (ptr->item == T_EPSILON)
            return 1;
        ptr = ptr->next;
    }
    return 0;
}

void ComputeFirst(FIRSTANDFOLLOW firstAndFollowSet) {
    /*
    1. If X is a terminal, then FIRST(X) = {X}.
    2. If X is a nonterminal and X -> Y1 Y2 ... Yk is a production for some k >=
    1, then place a in FIRST(X) if for some i, a is in FIRST(Yi), and eps is in
    all of       eps. If eps is in FIRST(Y ) FIRST(Y1 ); : : : ; FIRST(Yi,1 );
    that is, Y1 ... Yi,1 )
    j
    for all j = 1; 2; : : : ; k, then add eps to FIRST(X ). For example,
    everything in FIRST(Y1 ) is surely in FIRST(X ). If Y1 does not derive eps,
    then we add eps, then we add FIRST(Y ), and nothing more to FIRST(X ), but
    if Y1 )
    2
    so on.
    3. If X -> eps is a production, then add eps to FIRST(X).
    */

    int change = 1;
    Elements lhs = T_NULL;
    for (; lhs < NUM_ELEMENTS; lhs++) {
        insertNode_EleLast(createNewNode_Ele(lhs),
                           firstAndFollowSet->firstSet[lhs]);
    }
    while (change) {
        change = 0;
        lhs = program;
        for (; lhs < NUM_NONTERMS; lhs++) {
            NODE_ELE firstLhsHead = firstAndFollowSet->firstSet[lhs]->head;
            NODE_LL currRHS = grammar_glob->rules[lhs]->head;

            if (currRHS->item->head->item == T_EPSILON &&
                !checkEpsilonInFirst(firstAndFollowSet->firstSet[lhs])) {
                insertNode_EleLast(createNewNode_Ele(T_EPSILON),
                                   firstAndFollowSet->firstSet[lhs]);
                currRHS = currRHS->next;
                continue;
            }
            while (currRHS != NULL) {
                NODE_ELE currTerm = currRHS->item->head;
                while (currTerm != NULL) {
                    NODE_ELE firstTerm =
                        firstAndFollowSet->firstSet[currTerm->item]->head;
                    while (firstTerm != NULL) {
                        if (firstTerm->item == T_EPSILON) {
                            firstTerm = firstTerm->next;
                            continue;
                        }
                        NODE_ELE tempLhs = firstLhsHead;
                        int visited = 0;
                        while (tempLhs != NULL) {
                            if (tempLhs->item == firstTerm->item)
                                visited = 1;
                            tempLhs = tempLhs->next;
                        }
                        if (!visited) {
                            insertNode_EleLast(
                                createNewNode_Ele(firstTerm->item),
                                firstAndFollowSet->firstSet[lhs]);
                            change = 1;
                        }
                        firstTerm = firstTerm->next;
                    }
                    if (currTerm->next == NULL &&
                        checkEpsilonInFirst(
                            firstAndFollowSet->firstSet[currTerm->item]) &&
                        !checkEpsilonInFirst(firstAndFollowSet->firstSet[lhs]))
                        insertNode_EleLast(createNewNode_Ele(T_EPSILON),
                                           firstAndFollowSet->firstSet[lhs]);
                    if (!checkEpsilonInFirst(
                            firstAndFollowSet->firstSet[currTerm->item]))
                        break;
                    // if (currTerm->next == NULL &&
                    // checkEpsilonInFirst(firstAndFollowSet->firstSet[lhs]))
                    //     insertNode_EleLast(createNewNode_Ele(TK_EPSILON),
                    //     firstAndFollowSet->firstSet[lhs]);
                    currTerm = currTerm->next;
                }

                currRHS = currRHS->next;
            }
        }
    }
}

void ComputeFollow(FIRSTANDFOLLOW firstAndFollowSet) {
    /*
    1. Place $ in FOLLOW(S), where S is the start symbol, and $ is the input
    right endmarker.
    2. If there is a production A->aBb , then everything in FIRST(b) except eps
    is in FOLLOW(B).
    3. If there is a production A->aB , or a production A->aBb , where FIRST(b)
    contains eps, then everything in FOLLOW(A) is in FOLLOW(B).
    */
    insertNode_EleLast(createNewNode_Ele(stringToEnum("TK_DOLLAR")),
                       firstAndFollowSet->followSet[0]);
    int change = 1;
    while (change) {
        change = 0;
        int lhs = 0;
        for (; lhs < NUM_NONTERMS; lhs++) {
            NODE_LL currRHS = grammar_glob->rules[lhs]->head;
            while (currRHS != NULL) {
                NODE_ELE currTerm = currRHS->item->head;
                NODE_ELE nextTerm = currTerm;
                while (currTerm != NULL) {
                    if (currTerm->item >= NUM_NONTERMS) {
                        currTerm = currTerm->next;
                        nextTerm = currTerm;
                        continue;
                    }

                    nextTerm = nextTerm->next;
                    // if (currTerm->item < NUM_NONTERMS) {
                    //     currRHS = currRHS->next;
                    //     continue;
                    // }
                    if (nextTerm == NULL) {

                        NODE_ELE lhsPtr =
                            firstAndFollowSet->followSet[lhs]->head;
                        while (lhsPtr != NULL) {
                            Elements term = lhsPtr->item;
                            NODE_ELE bPtr =
                                firstAndFollowSet->followSet[currTerm->item]
                                    ->head;
                            int visited = 0;
                            while (bPtr != NULL) {
                                if (bPtr->item == term)
                                    visited = 1;
                                bPtr = bPtr->next;
                            }
                            if (!visited) {
                                insertNode_EleLast(
                                    createNewNode_Ele(term),
                                    firstAndFollowSet
                                        ->followSet[currTerm->item]);
                                change = 1;
                            }
                            lhsPtr = lhsPtr->next;
                        }
                    } else {
                        NODE_ELE betaPtr =
                            firstAndFollowSet->firstSet[nextTerm->item]->head;
                        while (betaPtr != NULL) {
                            Elements term = betaPtr->item;
                            if (term == T_EPSILON) {
                                betaPtr = betaPtr->next;
                                continue;
                            }
                            NODE_ELE bPtr =
                                firstAndFollowSet->followSet[currTerm->item]
                                    ->head;
                            int visited = 0;
                            while (bPtr != NULL) {
                                if (bPtr->item == term)
                                    visited = 1;
                                bPtr = bPtr->next;
                            }
                            if (!visited) {
                                insertNode_EleLast(
                                    createNewNode_Ele(term),
                                    firstAndFollowSet
                                        ->followSet[currTerm->item]);
                                change = 1;
                            }
                            betaPtr = betaPtr->next;
                        }
                        if (checkEpsilonInFirst(
                                firstAndFollowSet->firstSet[nextTerm->item]))
                            continue;
                        if (checkEpsilonInFirst(
                                firstAndFollowSet->firstSet[nextTerm->item]) &&
                            (nextTerm->next == NULL)) {
                            NODE_ELE lhsPtr =
                                firstAndFollowSet->followSet[lhs]->head;
                            while (lhsPtr != NULL) {
                                Elements term = lhsPtr->item;
                                NODE_ELE bPtr =
                                    firstAndFollowSet->followSet[currTerm->item]
                                        ->head;
                                int visited = 0;
                                while (bPtr != NULL) {
                                    if (bPtr->item == term)
                                        visited = 1;
                                    bPtr = bPtr->next;
                                }
                                if (!visited) {
                                    insertNode_EleLast(
                                        createNewNode_Ele(term),
                                        firstAndFollowSet
                                            ->followSet[currTerm->item]);
                                    change = 1;
                                }
                                lhsPtr = lhsPtr->next;
                            }
                        }
                    }
                    currTerm = currTerm->next;
                    nextTerm = currTerm;
                }
                currRHS = currRHS->next;
            }
        }
    }
}

FIRSTANDFOLLOW ComputeFirstAndFollowSets() {
    FIRSTANDFOLLOW firstAndFollowSet =
        (FIRSTANDFOLLOW)malloc(sizeof(FirstAndFollow));
    for (int i = 0; i < NUM_NONTERMS; i++) {
        firstAndFollowSet->firstSet[i] = createNewList_Ele();
        firstAndFollowSet->followSet[i] = createNewList_Ele();
    }
    for (int i = NUM_NONTERMS; i < NUM_ELEMENTS; i++)
        firstAndFollowSet->firstSet[i] = createNewList_Ele();
    ComputeFirst(firstAndFollowSet);
    ComputeFollow(firstAndFollowSet);
    return firstAndFollowSet;
}

ProdRule convertLLtoProd(Elements lhs, NODE_LL rule) {
    ProdRule ans;
    ans.LHS = lhs;
    for (int i = 0; i < 10; i++)
        ans.RHS[i] = T_NULL;
    // memset(ans.RHS, -1, 10 * sizeof(Elements));
    NODE_ELE ptr = rule->item->head;
    int cnt = 0;
    while (ptr) {
        ans.RHS[cnt++] = ptr->item;
        ptr = ptr->next;
    }
    ans.count_rhs = cnt;
    return ans;
}
// void printRule(ProdRule r) {
//     printf("Cnt = %d\n", r.count_rhs);
//     printf("%s -> ", enumToString[r.LHS]);
//     for (int i = 0; i < r.count_rhs; i++) {
//         printf("%s\t", enumToString[r.RHS[i]]);
//     }
//     printf("\n");
// }

void initialiseParseTable() {
    for (int i = 0; i < NUM_NONTERMS; i++) {
        for (int j = 0; j < NUM_TERMS + 1; j++) {
            ParseTable[i][j].LHS = T_NULL;
            for (int k = 0; k < 10; k++) {
                ParseTable[i][j].RHS[k] = T_NULL;
            }
            ParseTable[i][j].count_rhs = 0;
        }
    }
}

void entryIntoParseTable(FIRSTANDFOLLOW F, Elements lhs, ProdRule rule) {
    LL_ELE setToAdd = createNewList_Ele();
    bool flag = false;
    for (int i = 0; i < rule.count_rhs; i++) {
        if (!checkEpsilonInFirst(F->firstSet[rule.RHS[i]])) {
            NODE_ELE temp1 = F->firstSet[rule.RHS[i]]->head;
            while (temp1) {
                NODE_ELE insert1 = createNewNode_Ele(temp1->item);
                insertNode_EleLast(insert1, setToAdd);
                temp1 = temp1->next;
            }
            flag = true;
            break;
        }
        if (rule.RHS[i] != T_EPSILON) {
            NODE_ELE temp2 = F->firstSet[rule.RHS[i]]->head;
            while (temp2) {
                if (temp2->item == T_EPSILON) {
                    temp2 = temp2->next;
                    continue;
                }
                NODE_ELE insert2 = createNewNode_Ele(temp2->item);
                insertNode_EleLast(insert2, setToAdd);
                temp2 = temp2->next;
            }
        }
    }
    if (!flag) {
        NODE_ELE temp3 = F->followSet[lhs]->head;
        while (temp3) {
            if (temp3->item == T_EPSILON) {
                temp3 = temp3->next;
                continue;
            }
            NODE_ELE insert3 = createNewNode_Ele(temp3->item);
            insertNode_EleLast(insert3, setToAdd);
            temp3 = temp3->next;
        }
    }
    NODE_ELE temp4 = setToAdd->head;
    while (temp4) {
        if (temp4->item != T_EPSILON)
            ParseTable[lhs][temp4->item - NUM_NONTERMS] = rule;
        temp4 = temp4->next;
    }
}

void createParseTable(FIRSTANDFOLLOW F) {
    for (int i = 0; i < NUM_NONTERMS; i++) {
        LL_LL rulesForNonTerm = grammar_glob->rules[i];
        NODE_LL currRule = rulesForNonTerm->head;
        while (currRule) {
            ProdRule temp = convertLLtoProd(i, currRule);
            entryIntoParseTable(F, i, temp);
            currRule = currRule->next;
        }
    }
}

TREE_NODE createTreeNode(Elements x, TREE_NODE parent, returnToken *k) {
    TREE_NODE y = malloc(sizeof(TreeNode));

    y->value = malloc(25);
    y->value = "----";
    if (k->t == TK_NUM || k->t == TK_RNUM) {
        y->value = NULL;
        free(y->value);
        y->value = malloc(25);
        strcpy(y->value, k->lexeme);
    }

    if (x >= NUM_NONTERMS) {
        y->lexeme = k->lexeme;
        y->lineNumber = k->line;
    } else {
        y->lexeme = "----";
        y->lineNumber = -1;
    }
    y->x = x;
    y->parent = parent;
    for (int i = 0; i < 10; i++)
        y->children[i] = NULL;
    return y;
}

int lolFlag = 0;
int errorred = 0;
int createParseTree(Stack *st, TREE_NODE root, returnToken *k) {
    Elements a = top(st);
    if (k->flag == -1 && k->lexeme != NULL)
        errorred = 1;
    if (a == T_DOLLAR) {
        if (k->flag == -2) {
            if (errorred == 0)
                // printf("Code is syntactically correct\n");
                return 0;
        } else {
            printf("Line %d Error : Extra content in input file, but, "
                   "Stack is "
                   "Empty\n",
                   k->line);
            errorred = 1;
            return 0;
        }
    } else {
        // Invalid Token
        if (k->flag == -1) {
            // Start of File
            if (k->lexeme == NULL) {
                *k = getNextToken();
                return createParseTree(st, root, k);
            }
            // When, Unknown pattern/Symbol is coming in input
            *k = getNextToken();

            return createParseTree(st, root, k);
        }
        if (k->flag == -2) {
            // EOF reached
            printf("Stack is not empty but file ended\n");
            errorred = 1;
            return 0;
        }
    }
    // Reached a terminal present in SynchArray
    if (root->x == T_EPSILON)
        return 0;

    // Uncomment to see input token and top of stack, and line until which code
    // printf("Line %d : %s, %s\n", k->line, enumToString[top(st)],
    // enumToString[k->t+NUM_NONTERMS]);

    if (a < NUM_NONTERMS) {
        ProdRule rule = ParseTable[a][k->t];
        if (rule.LHS != T_NULL) {
            lolFlag = 0;
            pop(st);

            root->count_children = rule.count_rhs;
            for (int i = rule.count_rhs - 1; i >= 0; i--) {
                if (rule.RHS[i] != T_EPSILON) {
                    push(st, rule.RHS[i]);
                }
            }
            for (int i = 0; i < rule.count_rhs; i++) {
                root->children[i] = createTreeNode(rule.RHS[i], root, k);
                int y = createParseTree(st, root->children[i], k);
                // if (y == -1) {
                //     *k = getNextToken();
                // }
            }
            return 0;
        } else {
            errorred = 1;
            if (lolFlag == 0)
                printf("Line %d Error : Invalid Token %s encountered with "
                       "value %s "
                       "stack top %s\n",
                       k->line, enumToString[k->t + NUM_NONTERMS], k->lexeme,
                       enumToString[a]);
            lolFlag = 1;
            if (rule.count_rhs == 0) {
                *k = getNextToken();

                return createParseTree(st, root, k);
            }
            if (rule.count_rhs == -1) {

                pop(st);
                return createParseTree(st, root, k);
            }
            // Error, syntactically incorrect as no production rule found
        }
    } else {
        if (k->t == a - NUM_NONTERMS) {
            pop(st);
            *k = getNextToken();
            return -1;
        } else {
            errorred = 1;
            // Error, Incorrect terminal found

            // TODO : See prints
            if (lolFlag == 0)
                printf(
                    "Line %d Error : The token %s for %s does not match with "
                    "the expected token %s\n",
                    k->line, enumToString[k->t + NUM_NONTERMS], k->lexeme,
                    enumToString[a]);
            lolFlag = 1;

            pop(st);

            return createParseTree(st, root, k);
        }
    }

    return 0;
}

TREE_NODE parseInputSourceCode() {

    Stack *st = createStack();
    push(st, T_DOLLAR);

    push(st, program);

    returnToken *r = malloc(sizeof(returnToken));
    r->t = TK_NULL;
    r->lexeme = NULL;
    r->flag = -1;
    TREE_NODE root = createTreeNode(program, NULL, r);
    createParseTree(st, root, r);
    if (errorred == 0) {
        // time_t start_time = time(NULL);
        // int JUMP_HEIGHT = 5;
        // int ANIMATION_TIME = 3;
        // int ANIMATION_SPEED_US = 500000;

        // while (difftime(time(NULL), start_time) < ANIMATION_TIME) {
        //     for (int i = 0; i < JUMP_HEIGHT; i++) {
        //         printf("\n");
        //     }

            printf("Code is SYNTACTICALLY correct\n");

    //         for (int i = 0; i < JUMP_HEIGHT; i++) {
    //             printf("\033[F"); // Move cursor up
    //         }

    //         fflush(stdout);
    //         usleep(ANIMATION_SPEED_US);
    //     }
    }
    return root;
}

void inOrderTraversal(FILE *fp, TREE_NODE root) {
    char *lexeme = root->lexeme;
    int lineNumber = root->lineNumber;
    char *tokenName = enumToString[root->x];

    char *nodeSymbol = "----";
    char *isLeafNode = "Yes";

    char *parent = "ROOT";

    if (root->parent)
        parent = enumToString[root->parent->x];

    if (root->count_children) {
        lexeme = "----";
        inOrderTraversal(fp, root->children[0]);
        tokenName = "----";
        nodeSymbol = enumToString[root->x];
        isLeafNode = "No";
    }

    fprintf(fp, "%-25s%-10d%-20s%-10s%-30s%-10s%-20s\n", lexeme, lineNumber,
            tokenName, root->value, parent, isLeafNode, nodeSymbol);

    for (int i = 1; i < root->count_children; i++)
        inOrderTraversal(fp, root->children[i]);

    return;
}

void printParseTree(TREE_NODE root, char *outfile) {
    FILE *fp = fopen(outfile, "w+");
    inOrderTraversal(fp, root);
    fclose(fp);
    return;
}
