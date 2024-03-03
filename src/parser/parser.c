#include "../../include/parser/parser.h"
#include "../../include/tokens/tokens.h"

#include <stdbool.h>
// #include <parser.h>
// #include <tokens.h>
// void populateSynchSet() {
//     memset(SynchSet, -1, NUM_NONTERMS*25);
//     FIRSTANDFOLLOW;
//     for (int i = 0 ; i < NUM_NONTERMS ; i++) {
//         int ind = 0;
//         NODE_ELE ptr = FIRSTANDFOLLOW->followSet[i]->head;
//         while (ptr != NULL) {
//             SynchSet[i][ind++] = ptr->item;
//             ptr = ptr->next;
//         }
//         ptr = FIRSTANDFOLLOW->firstSet[i]->head;
//         while (ptr != NULL) {
//             if (!terminalBelongsSynchSet(i, ptr->item - NUM_NONTERMS))
//                 SynchSet[i][ind++] = ptr->item;
//         }
//     }
// }
void synchPopulateParseTable(FIRSTANDFOLLOW Fnf){
    // FIRSTANDFOLLOW->fir
    Elements arr[] = {T_ID, T_FUNID, T_RUID, T_WHILE, T_UNION, T_DEFINETYPE, T_TYPE, T_MAIN, T_IF, T_READ, T_WRITE, T_RETURN, T_CALL, T_RECORD, T_THEN, T_ELSE};
    for(int i = 0; i<NUM_NONTERMS; i++){
        // NODE_ELE fol = Fnf->followSet[i]->head;
    
        // while (fol != NULL) {
        //     if (ParseTable[i][fol->item].LHS == -1)
        //         ParseTable[i][fol->item].LHS = -2;
        //     fol = fol->next;
        // }
        for (int j = 0 ; j < 16 ; j++) {
            if (ParseTable[i][arr[j]-NUM_NONTERMS].LHS == T_NULL)
                ParseTable[i][arr[j]-NUM_NONTERMS].count_rhs = -1;
        }
        
    }
    // for (int i = 0 ; )
}
// bool terminalBelongsSynchSet(Elements a, Token t){
//     Elements synchSeta[] = SynchSet[a];
//     int i = 0;
//     while(synchSeta[i] != -1){
//         if(synchSeta[i] == t){
//             return 1;
//         }
//     }
//     return 0;
// }
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

void printStack(Stack * st) {
    NODE_ELE x = st->list->head;
    while (x) {
        printf("%s\n",enumToString[x->item]);
        x = x->next;
    }
}

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
}

void parseFile(char *filename) {
    FILE *fp = fopen(filename, "r");
    if (!fp) {
        printf("Error in opening file\n");
        return;
    }
    grammar_glob = malloc(sizeof(grammar));
    for (int i = 0; i < NUM_NONTERMS; i++) {
        grammar_glob->rules[i] = createNewList_LL();
    }
    int line_count = 0;
    char buff[1024];
    while (fgets(buff, 1024, fp) != NULL) {
        Elements tempArr[15];
        for (int i = 0;i<15;i++) tempArr[i] = T_NULL;
        // memset(tempArr, -1, sizeof(tempArr));
        char delim1[] = " ";
        char delim2[] = "\n";

        char *fullLine = strtok(buff, delim2);
        char *firstptr = strtok(fullLine, delim1);
        // printf("%s\n", firstptr);
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
        // printFirollow(firstAndFollowSet, 100);
        // printf("Hehe\n");
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
                    // printf("WOOOOO %d %d\n", currTerm->item, nextTerm->item);
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
    for (int i = 0 ; i < 10 ; i++)
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
void printRule (ProdRule r) {
    printf("%s -> ", enumToString[r.LHS]);
    for (int i = 0;i<r.count_rhs;i++) {
        printf("%s\t",enumToString[r.RHS[i]]);
    }
    printf("\n");
}

void initialiseParseTable() {
    ProdRule dummy;
    // dummy.LHS = -1;
    // memset(dummy.RHS, -1, 10 * sizeof(Elements));
    // dummy.count_rhs = 0;
    for (int i = 0; i < NUM_NONTERMS; i++) {
        for (int j = 0; j < NUM_TERMS+1; j++) {
            ParseTable[i][j].LHS = T_NULL;
            for(int k=0;k<10;k++){
                ParseTable[i][j].RHS[k]=T_NULL;
            }
            ParseTable[i][j].count_rhs = 0;
        }
    }
    printf("MY NIGA\n");
    printRule(ParseTable[4][70]);
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

TREE_NODE createTreeNode(Elements x, TREE_NODE parent,returnToken * k) {
    TREE_NODE y = malloc(sizeof(TreeNode));
    if (x >= NUM_NONTERMS) {
        y->lexeme = k->lexeme;
        y->lineNumber = k->line;
        // if (x == TK_INT || x == TK_REAL) 
        //     // y->value = strtod(k.lexeme,);
        // else
        //     y->value = -1;
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

int createParseTree(Stack *st, TREE_NODE root, returnToken * k) {


    /*
    ERROR HANDLING :
        1. Unknown pattern vs Unknown Symbol
        2. If invalid token, call on next token seedha

    TYPES OF ERRORS :
        Line <LineNo.> Error :
        : Invalid Token <Terminal Enum> encountered with value <Terminal lexeme> stack top <NonTerminal enum>
        : The token <Terminal Enum> for <lexeme Terminal>  does not match with the expected token <Terminal enum> 
        : Unknown Pattern <lexeme>
        : Unknown Symbol <lexeme>
    */
    // returnToken k;
    if (k->flag == -1) {
        // printf("%d\n", k.lexeme[2]);
        if (k->lexeme == NULL) {
            *k = getNextToken();
            // printf("%d %d\n",k->t,k->flag);
            return createParseTree(st, root, k);
        }
        printf ("Line %d Error : Unknown pattern <%s> %d\n", k->line, k->lexeme,k->t);
        *k = getNextToken();
        while (1) {
            if (ParseTable[0][k->t].LHS == T_NULL && ParseTable[0][k->t].count_rhs == -1)
                break;
            *k = getNextToken();
        }


        return createParseTree(st, root, k);
        // k = getNextToken(); // has to return line number of code and value if
                            // number and lexeme
    }
    if (root->x == T_EPSILON) return 0;
    // printf("%s, %s, %s, %s\n", enumToString[top(st)], enumToString[root->x], enumToString[k->t+NUM_NONTERMS], k->lexeme);
            // printStack(st);

    // printf("hehe\n");
    Elements a = top(st);

    // if (k.flag == -1) {
    //     // Error, lexer could not identify token
    // } else 

    if (a != T_DOLLAR && k->flag == -2) {
        printf("Line %d Error : Some token expected but file abrupty ended\n", k->line);
        printf("Line %d Error : Input file ended before complete parsing\n", k->line);
        return 0;
        // Error, no tokens left but stack is not empty
    }

    if (a < NUM_NONTERMS) {
        ProdRule rule = ParseTable[a][k->t];
        // printRule(rule);
        if (rule.LHS != T_NULL) {
            pop(st);
            root->count_children = rule.count_rhs;
            for (int i = rule.count_rhs - 1; i >= 0; i--) {
                if (rule.RHS[i] != T_EPSILON)
                    push(st, rule.RHS[i]);
            }
            for (int i = 0; i < rule.count_rhs; i++) {
                
                root->children[i] = createTreeNode(rule.RHS[i], root,k);
                int y = createParseTree(st,root->children[i],k);
                if (y == -1) {
                    *k = getNextToken();
                    // printf ("usaahfpouwfho;%s %s %d\n", enumToString[k->t+NUM_NONTERMS], k->lexeme,k->flag);
                }
            }

        } else {
            printf("Line %d Error : Invalid Token %s encountered with value %s stack top %s\n", 
                    k->line, enumToString[k->t+NUM_NONTERMS], k->lexeme, enumToString[a]);
            if (rule.LHS == T_NULL && rule.count_rhs==0) {
                do {
                    *k = getNextToken();
                    if (k->flag == -1) {
                        printf ("Line %d Error : Unknown pattern <%s> \n", k->line, k->lexeme);
                        continue;
                    } else if (k->flag == -2) {
                        printf("File has ended\n");
                        return 0;
                    }
                    rule = ParseTable[a][k->t];
                } while (rule.LHS == T_NULL);
            }
            // if (rule.LHS == -2) {
            //     pop(st);
            //     int y = createParseTree (st, root, k);
            //     return y;
            // }
            if (rule.LHS == T_NULL && rule.count_rhs == -1) {
                do {
                    pop (st);
                    
                    a = top(st);
                    if (a == T_DOLLAR) {
                        printf("Stack be empty, tokens left\n");
                        return 0;
                    }
                    if (a < NUM_NONTERMS)
                    rule = ParseTable[a][k->t];

                } while (rule.LHS == T_NULL);
            }
            
            // int f = 0;
            // while(!f){
            //     k = getNextToken();
            //     if (k.flag == -2)
            //         return 0;
            //     if(terminalBelongsSynchSet(a, k.t) == 1){
            //         f = 1;
            //     }
            //     else{
            //         //getNextToken()
            //     }
            // }
            // createParseTree(st, root, k);
            // Error, syntactically incorrect as no production rule found
        }
    } else {
        if (k->t == a - NUM_NONTERMS) {
            pop(st);
            return -1;
        } else {
            // Error, Incorrect terminal found

            // TODO : See prints
            printf("Line %d Error : The token %s for %s does not match with the expected token %s\n", k->line, enumToString[k->t+NUM_NONTERMS], k->lexeme, enumToString[a]);
            printf("                Token was automatically inserted, resuming parsing\n");
            // k = getNextToken();
            if (top(st) == T_DOLLAR) {
                printf("Stack is now Empty\n");
                return 0;
            }
            pop(st);

            return createParseTree(st, root, k);
        }
    }

    if (top(st) == T_DOLLAR) {
        if (k->flag == -2) {
            if (root->x == program)  {
                printf("Code is syntactically correct\n");
                // exit(0);
            }
        } else {
            printf("Line %d Error : Extra content in input file\n", k->line);
            // exit(0);
            // Error, Stack empty but leftover tokens found
        }
    }
    return 0;
}

TREE_NODE parseInputSourceCode() {

    Stack *st = createStack();
    push(st, T_DOLLAR);
    push(st, program);
    
    returnToken * r = malloc(sizeof(returnToken));
    r->t = TK_NULL;
    r->lexeme = NULL;
    r->flag = -1;
    TREE_NODE root = createTreeNode(program, NULL,r);
    createParseTree(st, root, r);
    return root;
}

void inOrderTraversal(FILE *fp, TREE_NODE root) {
    char *lexeme = root->lexeme;
    int lineNumber = root->lineNumber;
    char *tokenName = enumToString[root->x];
    char value[10];

    char *nodeSymbol = "----";
    char *isLeafNode = "Yes";
    char *parent = "ROOT";

    if (root->x == T_INT || root->x == T_REAL)
        sprintf(value, "%.2f\n", root->value);
    if (root->parent)
        parent = enumToString[root->parent->x];

    if (root->count_children) {
        lexeme = "----";
        inOrderTraversal(fp, root->children[0]);
        tokenName = "----";
        nodeSymbol = enumToString[root->x];
        isLeafNode = "No";
    }

    fprintf(fp, "%s\t%d\t%s\t%s\t%s\t%s\t%s\n",lexeme,lineNumber,  tokenName, value,
            parent, isLeafNode, nodeSymbol);
    
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

int main(){
    parseFile("/home/harsh/Compiler-Construction-Project/src/parser/ModifiedGrammar.txt");
    printf("here1\n");
    FIRSTANDFOLLOW fnfset = ComputeFirstAndFollowSets(grammar_glob);
    printf("here2\n");
    initLexer();
    initialiseParseTable();
    printf("here3\n");
    createParseTable(fnfset);
    printf("here4\n");
    synchPopulateParseTable(fnfset);
    printf("here5\n");
    TREE_NODE one = parseInputSourceCode();
    printf("here6\n");
    printParseTree(one, "/home/harsh/Compiler-Construction-Project/src/hehe.txt");
    printf("here7\n");
    return 0;
}
// int main() {
//     parseFile("src/parser/ModifiedGrammar.txt");
//     printf("Grammar Rules : \n");
//     for (int i = 0; i < NUM_NONTERMS; i++) {
//         printf("%-3d  :  ", i);
//         // printHEHE(grammar_glob->rules[i]);
//         // printf("\n");

//         NODE_LL ptr =grammar_glob->rules[i]->head;
//         while (ptr != NULL) {
//             NODE_ELE hehe = ptr->item->head;
//             while (hehe != NULL) {
//                 printf("%-3d ", hehe->item);
//                 hehe = hehe->next;
//             }
//             printf("| ");
//             ptr = ptr->next;
//         }
//         // printHEHE(GG->rules[i]);
//         printf("\n");
//     }
//     printf("----\n");
//     FIRSTANDFOLLOW fnfset = ComputeFirstAndFollowSets(grammar_glob);
//     printf("/*************************************************\n");
//     printf("First Sets\n");
//     for (int i = 0; i < NUM_ELEMENTS; i++) {
//         printf("{ %s\t-> ", enumToString[i]);
//         NODE_ELE ptr = fnfset->firstSet[i]->head;
//         while (ptr != NULL) {
//             printf("%s ", enumToString[ptr->item]);
//             ptr = ptr->next;
//         }
//         printf("}\n");
//     }
//     printf("/*************************************************\n");
//     printf("Follow Sets\n");
//     for (int i = 0; i < NUM_NONTERMS; i++) {
//         printf("{ %s  =>  ", enumToString[i]);
//         NODE_ELE ptr = fnfset->followSet[i]->head;
//         while (ptr != NULL) {
//             printf("%s ", enumToString[ptr->item]);
//             ptr = ptr->next;
//         }
//         printf("}\n");
//     }
//     printf("/*************************************************\n");
//     printf("Checking Prod Rule Conversion\n");
//     for (int i = 0; i < NUM_NONTERMS; i++) {
//         LL_LL rulesForNonTerm = grammar_glob->rules[i];
//         NODE_LL currRule = rulesForNonTerm->head;
//         while (currRule) {
//             ProdRule temp = convertLLtoProd(i, currRule);
//             printf("%-3d  -> ", i);
//             for (int j = 0; j < temp.count_rhs; j++) {
//                 printf("%-3d ", temp.RHS[j]);
//             }
//             printf("\n");
//             currRule = currRule->next;
//         }
//     }
//     printf("/*************************************************\n");
//     printf("Checking Parse Table Filling\n");
//     initialiseParseTable();
//     createParseTable(fnfset);
//     int cnt = 0;
//     for (int i = 0; i < 53; i++) {
//         for (int j = 0; j < 59; j++) {
//             // printf("%-3d ",ParseTable[i][j].count_rhs);
//             if (ParseTable[i][j].count_rhs) {
//                 printf("NT %s, \t", enumToString[i]);
//                 printf("Term %s, \t", enumToString[j + 53]);
//                 printf("Rule \t");
//                 printf("%s => ", enumToString[ParseTable[i][j].LHS]);
//                 for (int k = 0; k < ParseTable[i][j].count_rhs; k++) {
//                     printf("%s ",
//                     enumToString[ParseTable[i][j].RHS[k]]);
//                 }
//                 printf("\n");
//                 cnt++;
//             }
//         }
//         // printf("\n");
//     }
//     printf("%-3d \n", cnt);
//     return 0;
// }
