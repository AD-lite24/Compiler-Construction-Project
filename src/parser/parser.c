#include "../../include/parser/parser.h"
#include "../../include/parser/parse_table.h"
#include "../../include/tokens/tokens.h"

#include <stdbool.h>

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
        return T_PARAMETER;
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

GRAMMAR parseFile(char *filename) {
    FILE *fp = fopen(filename, "r");
    if (!fp) {
        printf("Error in opening file\n");
        return NULL;
    }
    GRAMMAR G = malloc(sizeof(grammar));
    for (int i = 0; i < NUM_NONTERMS; i++) {
        G->rules[i] = createNewList_LL();
    }
    int line_count = 0;
    char buff[1024];
    while (fgets(buff, 1024, fp) != NULL) {
        Elements tempArr[15];
        memset(tempArr, -1, sizeof(tempArr));
        char delim1[] = " ";
        char delim2[] = "\n";

        char *fullLine = strtok(buff, delim2);
        char *firstptr = strtok(fullLine, delim1);
        int LHS_NonTerm = stringToEnum(firstptr);
        firstptr = strtok(NULL, delim1);
        int index = 0;
        firstptr = strtok(NULL, delim1);
        LL_ELE curr = createNewList_Ele();
        while (firstptr) {
            if (firstptr[0] == ';') {
                insertNode_LLLast(createNewNode_LL(curr),
                                  G->rules[LHS_NonTerm]);
                curr = createNewList_Ele();
                firstptr = strtok(NULL, delim1);
                continue;
            }
            NODE_ELE one = createNewNode_Ele(stringToEnum(firstptr));
            insertNode_EleLast(one, curr);
            firstptr = strtok(NULL, delim1);
        }
        insertNode_LLLast(createNewNode_LL(curr), G->rules[LHS_NonTerm]);
    }
    return G;
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

void ComputeFirst(GRAMMAR G, FIRSTANDFOLLOW firstAndFollowSet) {
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
            NODE_LL currRHS = G->rules[lhs]->head;

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

void ComputeFollow(GRAMMAR G, FIRSTANDFOLLOW firstAndFollowSet) {
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
            NODE_LL currRHS = G->rules[lhs]->head;
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

FIRSTANDFOLLOW ComputeFirstAndFollowSets(GRAMMAR G) {
    FIRSTANDFOLLOW firstAndFollowSet =
        (FIRSTANDFOLLOW)malloc(sizeof(FirstAndFollow));
    for (int i = 0; i < NUM_NONTERMS; i++) {
        firstAndFollowSet->firstSet[i] = createNewList_Ele();
        firstAndFollowSet->followSet[i] = createNewList_Ele();
    }
    for (int i = NUM_NONTERMS; i < NUM_ELEMENTS; i++)
        firstAndFollowSet->firstSet[i] = createNewList_Ele();
    ComputeFirst(G, firstAndFollowSet);
    ComputeFollow(G, firstAndFollowSet);
    return firstAndFollowSet;
}

ProdRule convertLLtoProd(Elements lhs, NODE_LL rule) {
    ProdRule ans;
    ans.LHS = lhs;
    memset(ans.RHS, -1, 10 * sizeof(Elements));
    NODE_ELE ptr = rule->item->head;
    int cnt = 0;
    while (ptr) {
        ans.RHS[cnt++] = ptr->item;
        ptr = ptr->next;
    }
    ans.count_rhs = cnt;
    return ans;
}

void initialiseParseTable() {
    ProdRule dummy;
    dummy.LHS = -1;
    memset(dummy.RHS, -1, 10 * sizeof(Elements));
    dummy.count_rhs = 0;
    for (int i = 0; i < 53; i++) {
        for (int j = 0; j < 59; j++) {
            ParseTable[i][j] = dummy;
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
            ParseTable[lhs][temp4->item - 53] = rule;
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

TREE_NODE createTreeNode(Elements x) {
    TREE_NODE y = malloc(sizeof(TreeNode));
    y->x = x;
    y->parent = NULL;
    y->right_sibling = NULL;
    for (int i = 0; i < 10; i++)
        y->children[i] = NULL;
    return y;
}

TREE_NODE parseInputSourceCode(char *testcase, ProdRule **ParseTable) {
    FILE *fp = fopen(testcase, "r");

    if (!fp) {
        printf("Error in opening file\n");
        return;
    }

    Stack *st = createStack();
    push(st, T_DOLLAR);
    push(st, program);

    Token k;
    Elements a;

    TREE_NODE root = createTreeNode(program);
    TREE_NODE node = root;

    while (T_DOLLAR != top(st)) {
        k = getNextToken();
        a = top(st);
        if (k == -1) {
            // Error Recovery, Token cannot be assigned
        } else if (k == -2) {
            // Error, Inputs are over but stack is not empty
        }

        if (a < 53) {
            
            ProdRule rule = ParseTable[a][k];
            if (rule.LHS == -1) {
                printf("You fucked up again");
            }

            else {

                pop(st);
                node->count_children = rule.count_rhs;
                for (int i = rule.count_rhs - 1; i >= 0; i--) {
                    push(st, rule.RHS[i]);
                    node->children[i] = createTreeNode(rule.RHS[i]);
                    node->children[i]->parent = node;
                    
                    if (i != rule.count_rhs -1) {
                        node->children[i]->right_sibling = node->children[i+1];
                    }
                }

                if (node->right_sibling == NULL && node->children[0] == NULL) node = node->parent;
                else if (node->children[0] != NULL){
                    node = node->children[0];
                }
                else{
                    if (node->right_sibling)
                        node = node->right_sibling;
                    else    
                        node = node->parent;
                }
            }

        } else {
            // check if k == a else error
            if (k == a - NUM_NONTERMS) {
                pop(st);
                
                continue;
            } else {
                // Error R
                printf("You fucked up");
            }
        }
    }

    k = getNextToken();
    if (k == -2) {
        // write case when just one final dollar is left
        printf("Input source code is syntactically correct\n");
    } else {
        // Error
    }
    return root;
}

void printParseTree(TREE_NODE root, char *outfile) {}

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
                             "T_NULL",
                             "T_ASSIGNOP",
                             "T_COMMENT",
                             "T_FIELDID",
                             "T_ID",
                             "T_NUM",
                             "T_RNUM",
                             "T_FUNID",
                             "T_RUID",
                             "T_WITH",
                             "T_PARAMETERS",
                             "T_END",
                             "T_WHILE",
                             "T_UNION",
                             "T_ENDUNION",
                             "T_DEFINETYPE",
                             "T_AS",
                             "T_TYPE",
                             "T_MAIN",
                             "T_GLOBAL",
                             "T_PARAMETER",
                             "T_LIST",
                             "T_SQL",
                             "T_SQR",
                             "T_INPUT",
                             "T_OUTPUT",
                             "T_INT",
                             "T_REAL",
                             "T_COMMA",
                             "T_SEM",
                             "T_COLON",
                             "T_DOT",
                             "T_ENDWHILE",
                             "T_OP",
                             "T_CL",
                             "T_IF",
                             "T_THEN",
                             "T_ENDIF",
                             "T_READ",
                             "T_WRITE",
                             "T_RETURN",
                             "T_PLUS",
                             "T_MINUS",
                             "T_MUL",
                             "T_DIV",
                             "T_CALL",
                             "T_RECORD",
                             "T_ENDRECORD",
                             "T_ELSE",
                             "T_AND",
                             "T_OR",
                             "T_NOT",
                             "T_LT",
                             "T_LE",
                             "T_EQ",
                             "T_GT",
                             "T_GE",
                             "T_NE",
                             "T_EPSILON",
                             "T_DOLLAR"};

int main() {
    GRAMMAR GG = parseFile("src/parser/ModifiedGrammar.txt");
    // TODO :
    grammar_glob = GG;
    printf("Grammar Rules : \n");
    for (int i = 0; i < NUM_NONTERMS; i++) {
        printf("%-3d  :  ", i);
        // printHEHE(GG->rules[i]);
        // printf("\n");

        NODE_LL ptr = GG->rules[i]->head;
        while (ptr != NULL) {
            NODE_ELE hehe = ptr->item->head;
            while (hehe != NULL) {
                printf("%-3d ", hehe->item);
                hehe = hehe->next;
            }
            printf("| ");
            ptr = ptr->next;
        }
        // printHEHE(GG->rules[i]);
        printf("\n");
    }
    printf("----\n");
    FIRSTANDFOLLOW fnfset = ComputeFirstAndFollowSets(GG);
    printf("/*************************************************\n");
    printf("First Sets\n");
    for (int i = 0; i < NUM_ELEMENTS; i++) {
        printf("{ %s\t-> ", arrElemCauseCheck[i]);
        NODE_ELE ptr = fnfset->firstSet[i]->head;
        while (ptr != NULL) {
            printf("%s ", arrElemCauseCheck[ptr->item]);
            ptr = ptr->next;
        }
        printf("}\n");
    }
    printf("/*************************************************\n");
    printf("Follow Sets\n");
    for (int i = 0; i < NUM_NONTERMS; i++) {
        printf("{ %s  =>  ", arrElemCauseCheck[i]);
        NODE_ELE ptr = fnfset->followSet[i]->head;
        while (ptr != NULL) {
            printf("%s ", arrElemCauseCheck[ptr->item]);
            ptr = ptr->next;
        }
        printf("}\n");
    }
    printf("/*************************************************\n");
    printf("Checking Prod Rule Conversion\n");
    for (int i = 0; i < NUM_NONTERMS; i++) {
        LL_LL rulesForNonTerm = GG->rules[i];
        NODE_LL currRule = rulesForNonTerm->head;
        while (currRule) {
            ProdRule temp = convertLLtoProd(i, currRule);
            printf("%-3d  -> ", i);
            for (int j = 0; j < temp.count_rhs; j++) {
                printf("%-3d ", temp.RHS[j]);
            }
            printf("\n");
            currRule = currRule->next;
        }
    }
    printf("/*************************************************\n");
    printf("Checking Parse Table Filling\n");
    initialiseParseTable();
    createParseTable(fnfset);
    int cnt = 0;
    for (int i = 0; i < 53; i++) {
        for (int j = 0; j < 59; j++) {
            // printf("%-3d ",ParseTable[i][j].count_rhs);
            if (ParseTable[i][j].count_rhs) {
                printf("NT %s, \t", arrElemCauseCheck[i]);
                printf("Term %s, \t", arrElemCauseCheck[j + 53]);
                printf("Rule \t");
                printf("%s => ", arrElemCauseCheck[ParseTable[i][j].LHS]);
                for (int k = 0; k < ParseTable[i][j].count_rhs; k++) {
                    printf("%s ", arrElemCauseCheck[ParseTable[i][j].RHS[k]]);
                }
                printf("\n");
                cnt++;
            }
        }
        // printf("\n");
    }
    printf("%-3d \n", cnt);
    return 0;
}
