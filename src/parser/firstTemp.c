#include "/mnt/d/Coco/Compiler-Construction-Project/include/parser/grammar.h"
#include "/mnt/d/Coco/Compiler-Construction-Project/include/parser/parser.h"
// #include "parser.c"
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include "/mnt/d/Coco/Compiler-Construction-Project/include/datastructures/linked_list.h"
#include "/mnt/d/Coco/Compiler-Construction-Project/src/datastructures/linked_list.c"

// #include "../../include/parser/parser.h"
// // #include "../include/datastructures/hashtable.h"
// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// #include 

Elements stringToEnumTerm(char * str) {
    if (strcmp(str,"TK_NULL") == 0) {
        return TK_NULL;
    } 
    else if (strcmp(str,"TK_ASSIGNOP") == 0) {
        return TK_ASSIGNOP;
    }
    else if (strcmp(str,"TK_COMMENT") == 0) {
        return TK_COMMENT;
    }
    else if (strcmp(str,"TK_FIELDID") == 0) {
        return TK_FIELDID;
    }
    else if (strcmp(str,"TK_ID") == 0) {
        return TK_ID;
    }
    else if (strcmp(str,"TK_NUM") == 0) {
        return TK_NUM;
    }
    else if (strcmp(str,"TK_RNUM") == 0) {
        return TK_RNUM;
    }
    else if (strcmp(str,"TK_FUNID") == 0) {
        return TK_FUNID;
    }
    else if (strcmp(str,"TK_RUID") == 0) {
        return TK_RUID;
    }
    else if (strcmp(str,"TK_WITH") == 0) {
        return TK_WITH;
    }
    else if (strcmp(str,"TK_PARAMETERS") == 0) {
        return TK_PARAMETER;
    }
    else if (strcmp(str,"TK_END") == 0) {
        return TK_END;
    }
    else if (strcmp(str,"TK_WHILE") == 0) {
        return TK_WHILE;
    }
    else if (strcmp(str,"TK_UNION") == 0) {
        return TK_UNION;
    }
    else if (strcmp(str,"TK_ENDUNION") == 0) {
        return TK_ENDUNION;
    }
    else if (strcmp(str,"TK_DEFINETYPE") == 0) {
        return TK_DEFINETYPE;
    }
    else if (strcmp(str,"TK_AS") == 0) {
        return TK_AS;
    }
    else if (strcmp(str,"TK_TYPE") == 0) {
        return TK_TYPE;
    }
    else if (strcmp(str,"TK_MAIN") == 0) {
        return TK_MAIN;
    }
    else if (strcmp(str,"TK_GLOBAL") == 0) {
        return TK_GLOBAL;
    }
    else if (strcmp(str,"TK_PARAMETER") == 0) {
        return TK_PARAMETER;
    }
    else if (strcmp(str,"TK_LIST") == 0) {
        return TK_LIST;
    }
    else if (strcmp(str,"TK_SQL") == 0) {
        return TK_SQL;
    }
    else if (strcmp(str,"TK_SQR") == 0) {
        return TK_SQR;
    }
    else if (strcmp(str,"TK_INPUT") == 0) {
        return TK_INPUT;
    }
    else if (strcmp(str,"TK_OUTPUT") == 0) {
        return TK_OUTPUT;
    }
    else if (strcmp(str,"TK_INT") == 0) {
        return TK_INT;
    }
    else if (strcmp(str,"TK_REAL") == 0) {
        return TK_REAL;
    }
    else if (strcmp(str,"TK_COMMA") == 0) {
        return TK_COMMA;
    }
    else if (strcmp(str,"TK_SEM") == 0) {
        return TK_SEM;
    }
    else if (strcmp(str,"TK_COLON") == 0) {
        return TK_COLON;
    }
    else if (strcmp(str,"TK_DOT") == 0) {
        return TK_DOT;
    }
    else if (strcmp(str,"TK_ENDWHILE") == 0) {
        return TK_ENDWHILE;
    }
    else if (strcmp(str,"TK_OP") == 0) {
        return TK_OP;
    }
    else if (strcmp(str,"TK_CL") == 0) {
        return TK_CL;
    }
    else if (strcmp(str,"TK_IF") == 0) {
        return TK_IF;
    }
    else if (strcmp(str,"TK_THEN") == 0) {
        return TK_THEN;
    }
    else if (strcmp(str,"TK_ENDIF") == 0) {
        return TK_ENDIF;
    }
    else if (strcmp(str,"TK_READ") == 0) {
        return TK_READ;
    }
    else if (strcmp(str,"TK_WRITE") == 0) {
        return TK_WRITE;
    }
    else if (strcmp(str,"TK_RETURN") == 0) {
        return TK_RETURN;
    }
    else if (strcmp(str,"TK_PLUS") == 0) {
        return TK_PLUS;
    }
    else if (strcmp(str,"TK_MINUS") == 0) {
        return TK_MINUS;
    }
    else if (strcmp(str,"TK_MUL") == 0) {
        return TK_MUL;
    }
    else if (strcmp(str,"TK_DIV") == 0) {
        return TK_DIV;
    }
    else if (strcmp(str,"TK_CALL") == 0) {
        return TK_CALL;
    }
    else if (strcmp(str,"TK_RECORD") == 0) {
        return TK_RECORD;
    }
    else if (strcmp(str,"TK_ENDRECORD") == 0) {
        return TK_ENDRECORD;
    }
    else if (strcmp(str,"TK_ELSE") == 0) {
        return TK_ELSE;
    }
    else if (strcmp(str,"TK_AND") == 0) {
        return TK_AND;
    }
    else if (strcmp(str,"TK_OR") == 0) {
        return TK_OR;
    }
    else if (strcmp(str,"TK_NOT") == 0) {
        return TK_NOT;
    }
    else if (strcmp(str,"TK_LT") == 0) {
        return TK_LT;
    }
    else if (strcmp(str,"TK_LE") == 0) {
        return TK_LE;
    }
    else if (strcmp(str,"TK_EQ") == 0) {
        return TK_EQ;
    }
    else if (strcmp(str,"TK_GT") == 0) {
        return TK_GT;
    }
    else if (strcmp(str,"TK_GE") == 0) {
        return TK_GE;
    }
    else if (strcmp(str,"TK_NE") == 0) {
        return TK_NE;
    }
    else if (strcmp(str,"TK_EPSILON") == 0) {
        return TK_EPSILON;
    }
    else if (strcmp(str,"TK_DOLLAR") == 0) {
        return TK_DOLLAR;
    }
    else if (strcmp(str,"program") == 0) {
        return program;
    }
    else if (strcmp(str,"mainFunction") == 0) {
        return mainFunction;
    }
    else if (strcmp(str,"otherFunctions") == 0) {
        return otherFunctions;
    }
    else if (strcmp(str,"function") == 0) {
        return function;
    }
    else if (strcmp(str,"input_par") == 0) {
        return input_par;
    }
    else if (strcmp(str,"output_par") == 0) {
        return output_par;
    }
    else if (strcmp(str,"parameter_list") == 0) {
        return parameter_list;
    }
    else if (strcmp(str,"dataType") == 0) {
        return dataType;
    }
    else if (strcmp(str,"primitiveDatatype") == 0) {
        return primitiveDatatype;
    }
    else if (strcmp(str,"constructedDatatype") == 0) {
        return constructedDatatype;
    }
    else if (strcmp(str,"remaining_list") == 0) {
        return remaining_list;
    }
    else if (strcmp(str,"stmts") == 0) {
        return stmts;
    }
    else if (strcmp(str,"typeDefinitions") == 0) {
        return typeDefinitions;
    }
    else if(strcmp(str, "actualOrRedefined") == 0){
        return actualOrRedefined;
    }    
    else if (strcmp(str,"typeDefinition") == 0) {
        return typeDefinition;
    }
    else if (strcmp(str,"fieldDefinitions") == 0) {
        return fieldDefinitions;
    }
    else if (strcmp(str,"fieldDefinition") == 0) {
        return fieldDefinition;
    }
    else if (strcmp(str,"moreFields") == 0) {
        return moreFields;
    }
    else if (strcmp(str,"declarations") == 0) {
        return declarations;
    }
    else if (strcmp(str,"declaration") == 0) {
        return declaration;
    }
    else if (strcmp(str,"global_or_not") == 0) {
        return global_or_not;
    }
    else if (strcmp(str,"otherStmts") == 0) {
        return otherStmts;
    }
    else if(strcmp(str, "stmt") == 0){
        return stmt;
    }
    else if (strcmp(str,"assignmentStmt") == 0) {
        return assignmentStmt;
    }
    else if (strcmp(str,"singleOrRecId") == 0) {
        return singleOrRecId;
    }
    else if(strcmp(str, "option_single_constructed") == 0){
        return option_single_constructed;
    }
    else if(strcmp(str, "oneExpansion") == 0){
        return oneExpansion;
    }
    else if (strcmp(str,"moreExpansions") == 0) {
        return moreExpansions;
    }
    else if (strcmp(str,"funCallStmt") == 0) {
        return funCallStmt;
    }
    else if (strcmp(str,"outputParameters") == 0) {
        return outputParameters;
    }
    else if (strcmp(str,"inputParameters") == 0) {
        return inputParameters;
    }
    else if (strcmp(str,"iterativeStmt") == 0) {
        return iterativeStmt;
    }
    else if (strcmp(str,"conditionalStmt") == 0) {
        return conditionalStmt;
    }
    else if (strcmp(str,"elsePart") == 0) {
        return elsePart;
    }
    else if (strcmp(str,"ioStmt") == 0) {
        return ioStmt;
    }
    else if (strcmp(str,"arithmeticExpression") == 0) {
        return arithmeticExpression;
    }
    else if (strcmp(str,"expPrime") == 0) {
        return expPrime;
    }
    else if (strcmp(str,"term") == 0) {
        return term;
    }
    else if (strcmp(str,"termPrime") == 0) {
        return termPrime;
    }
    else if (strcmp(str,"factor") == 0) {
        return factor;
    }
    else if (strcmp(str,"highPrecedenceOperator") == 0) {
        return highPrecedenceOperator;
    }
    else if (strcmp(str,"lowPrecedenceOperators") == 0) {
        return lowPrecedenceOperators;
    }
    else if(strcmp(str, "booleanExpression") == 0){
        return booleanExpression;
    }
    else if (strcmp(str,"var") == 0) {
        return var;
    }
    else if (strcmp(str,"logicalOp") == 0) {
        return logicalOp;
    }
    else if (strcmp(str,"relationalOp") == 0) {
        return relationalOp;
    }
    else if (strcmp(str,"returnStmt") == 0) {
        return returnStmt;
    }
    else if (strcmp(str,"optionalReturn") == 0) {
        return optionalReturn;
    }
    else if (strcmp(str,"idList") == 0) {
        return idList;
    }
    else if (strcmp(str,"more_ids") == 0) {
        return more_ids;
    }
    else if (strcmp(str,"definetypestmt") == 0) {
        return definetypestmt;
    }
    else if (strcmp(str,"A") == 0) {
        return A;
    }
}

/*
void parseFile(char *filename, int table_type) {

    FILE *fp = fopen(filename, "r");

    if (!fp) {
        print("Error in opening file\n");
        return;
    }

    int line_count = 0;

    char buff[1024];
    while (fgets(buff, 1024, fp)) {

        // read variable name

        char *firstpos = buff;
        char *start_bracket = strchr(buff, '{');
        char *end_bracket = strchr(buff, '}');

        int nonterm_len = start_bracket - firstpos - 1;

        char variable_name[nonterm_len + 1];

        strncpy(variable_name, firstpos, nonterm_len);
        variable_name[nonterm_len] = '\0';
    

        if (start_bracket != NULL && end_bracket != NULL) {

            int length = end_bracket - start_bracket - 1;
            char content[length + 1];
            strncpy(content, start_bracket + 1, length);
            content[length] = '\0'; 

            char *token = strtok(content, ",");

            if (token != NULL) {
                if (!table_type) { // for first
                    firstSet[line_count][0] = stringToEnumTerm(token);
                }
                else { // for follow
                    followSet[line_count][0] = stringToEnumTerm(token);
                }
            }
            
            int count = 1;
            while ((token = strtok(NULL, ",")) != NULL) {
                if (!table_type) { // for first
                    firstSet[line_count][count] = stringToEnum(token);
                } else { // for follow
                    followSet[line_count][count] = stringToEnum(token);
                }
                count++;
            }
        }
        line_count++;
    }
}


Terminals* First(char *nonterm) {
    return firstSet[stringToEnumNonTerm(nonterm)];
}

Terminals* Follow(char *nonterm) {
    return followSet[stringToEnumNonTerm(nonterm)];
}
*/


void printHEHE (LL eqn) {
    if (eqn == NULL)
        return;
    NODE ptr = eqn->head;

    // printf("MY NIGGA U DOPE\n");
    while (ptr != NULL) {
    // printf ("%p    ", ptr);
        for (int ind = 0 ; ind < 10 ; ind++) {
            printf("%d ", ptr->item[ind]);
        }
        printf (" | ");
        ptr = ptr->next;
    }
}

GRAMMAR parseFile (char *filename) {
    FILE *fp = fopen(filename, "r");
    if (!fp) {
        printf("Error in opening file\n");
        return NULL;
    }
    GRAMMAR G = malloc(sizeof(grammar));
    for (int i = 0  ; i < NUM_NONTERMS ; i++) {
        G->rules[i] = createNewList();
        // G->rules[i]->head;
    }
    int line_count = 0;
    char buff[1024];
    while (fgets(buff, 1024, fp) != NULL) {
        // printf ("Line Count = %d\n", line_count++);
        // printf("%s\n", buff);

        Elements tempArr[15];
        memset (tempArr, -1, sizeof(tempArr));
        // read variable name
        char delim1[] = " ";
        char delim2[] = "\n";

        char *fullLine = strtok(buff, delim2);
        char *firstptr = strtok(fullLine, delim1);
        int LHS_NonTerm = stringToEnumTerm(firstptr);
        // printf("LHS = %d\n", LHS_NonTerm);
        firstptr = strtok (NULL, delim1);
        int index = 0;
        firstptr = strtok (NULL, delim1);
        while (firstptr) {
            // printf("hehe\n");
            // printf("%s\n", firstptr);
            // printf("%s\n", firstptr);
            if (firstptr[0] == ';') {
                Elements* memArr = (Elements*) malloc (sizeof(Elements)*15);
                memcpy(memArr, tempArr, sizeof(Elements)*15);
                NODE newNode = createNewNode(memArr);
                insertNodeLast(newNode, G->rules[LHS_NonTerm]);
                index = 0;

                memset (tempArr, -1, sizeof(tempArr));
                firstptr = strtok (NULL, delim1);
                continue;
            }
            // printf("%s\n", firstptr);
            tempArr[index++] = stringToEnumTerm(firstptr);
            firstptr = strtok (NULL, delim1);
        }
        Elements* memArr = (Elements*) malloc (sizeof(int)*15);
        memcpy(memArr, tempArr, sizeof(Elements)*15);
        NODE newNode = createNewNode(memArr);
        insertNodeLast(newNode, G->rules[LHS_NonTerm]);
        // printf("%d\n", LHS_NonTerm);
        // printf ("%p\n", G->rules[LHS_NonTerm]);

        // printf ("%d -> ", LHS_NonTerm);
        // printHEHE(G->rules[LHS_NonTerm]);
        // printf("\n");
    }
    return G;
}




// FIRSTANDFOLLOW ComputeFirstAndFollowSets (grammar G) {
//     FIRSTANDFOLLOW fnf = malloc(sizeof(FirstAndFollow));
//     int firstIndex[NUM_NONTERMS] = {0};
//     int followIndex[NUM_NONTERMS] =  {0};
//     for (int i = 0 ; i < NUM_NONTERMS ; i++) {
//         fnf->firstSet[]
//     }

// }
// void computeFirst (NonTerminals lhs, LL rule) {

// }
// createParseTable(FirstAndFollow F, table T):



int e = 1;
int addElem(Elements* dest, Elements* src, int destIndex){
    int srcIndex = 0;
    while(src[srcIndex] != 200){
        if(src[srcIndex]!=110) dest[destIndex++] = src[srcIndex];
        else e = -1;
        srcIndex++;
    }
    return destIndex;
}

void findFirst(Elements n1, LL rule, FIRSTANDFOLLOW FnF){
    NODE curNode = rule->head;
    Elements* ret = (Elements*)malloc(sizeof(Elements)*40);
    // memset(ret, 200, 40*sizeof(Elements));
    int retIndex = 0;
    while(curNode!=NULL){
        Elements* curElem = curNode->item;
        int index = 0;
        while(curElem[index]!=200){
            int val = curElem[index];
            if(val >= 52){
                ret[retIndex++] = val;
                break;
            }
            else{
                Elements* src = FnF->firstSet[val];
                retIndex = addElem(ret, src, retIndex);
                if(e==-1){
                    index++;
                    if(curElem[index] == 200){
                        break;
                    }
                    else e = 1;
                }
                else{
                    break;
                }
                // fill all elements of that non terminal
            }
        }
        if(e==-1){
            ret[retIndex++] = TK_EPSILON;
            e = 1;
        }
            // index++;
        curNode = curNode->next;
        }
    ret[retIndex] = 200;
    FnF->firstSet[n1] = ret;
}


int main () {
    GRAMMAR GG = parseFile("ModifiedGrammar.txt");
    // for (int i = 0 ; i < NUM_NONTERMS ; i++) {
    //     printf ("%d\t->  ", i);
    //     // printf("My NIGAA hehe\n");
    //     // printf("%p\n", GG);
    //     printHEHE(GG->rules[i]);
    //     printf("\n");
    // }
    FIRSTANDFOLLOW FnF = (FIRSTANDFOLLOW)malloc(sizeof(struct FirstAndFollow));
    for(int i = 0; i<NUM_NONTERMS; i++){
        FnF->firstSet[i] = (Elements*)malloc(sizeof(Elements));
    }
    findFirst(9, GG->rules[9], FnF);
    findFirst(8, GG->rules[8], FnF);
    findFirst(7, GG->rules[7], FnF);
    findFirst(20, GG->rules[20], FnF);
    Elements* y = FnF->firstSet[7];
    int index = 0;
    while(y[index]!=200){
        printf("w%d\n", y[index++]);
    }
    y = FnF->firstSet[8];
    index = 0;
    while(y[index]!=200){
        printf("s%d\n", y[index++]);
    }
    y = FnF->firstSet[9];
    index = 0;
    while(y[index]!=200){
        printf("x%d\n", y[index++]);
    }
    y = FnF->firstSet[20];
    index = 0;
    while(y[index]!=200){
        printf("z%d\n", y[index++]);
    }
    return 0;
}


// int main () {
//     // FnF->firstSet = (Elements*)malloc(sizeof(Elements)*NUM_NONTERMS);

//     return 0;
// }
// int e = 1;
// int addElem(Elements* dest, Elements* src, int destIndex){
//     int srcIndex = 0;
//     while(src[srcIndex] != 200){
//         if(src[srcIndex]!=110) dest[destIndex++] = src[srcIndex];
//         else e = -1;
//         srcIndex++;
//     }
//     return destIndex;
// }

// void findFirst(Elements n1, LL rule, FIRSTANDFOLLOW FnF){
//     NODE curNode = rule->head;
//     Elements* ret = (Elements*)malloc(sizeof(Elements)*40);
//     // memset(ret, 200, 40*sizeof(Elements));
//     int retIndex = 0;
//     while(curNode!=NULL){
//         Elements* curElem = curNode->item;
//         int index = 0;
//         while(curElem[index]!=200){
//             int val = curElem[index];
//             if(val >= 52){
//                 ret[retIndex++] = val;
//                 break;
//             }
//             else{
//                 Elements* src = FnF->firstSet[val];
//                 retIndex = addElem(ret, src, retIndex);
//                 if(e==-1){
//                     index++;
//                     if(curElem[index] == 200){
//                         break;
//                     }
//                     else e = 1;
//                 }
//                 else{
//                     break;
//                 }
//                 // fill all elements of that non terminal
//             }
//         }
//         if(e==-1){
//             ret[retIndex++] = TK_EPSILON;
//             e = 1;
//         }
//             // index++;
//         curNode = curNode->next;
//         }
//     ret[retIndex] = 200;
//     FnF->firstSet[n1] = ret;
// }




// int main () {
//     GRAMMAR GG = malloc (sizeof(grammar));
//     for (int i = 0 ; i < NUM_NONTERMS ; i++)
//         GG->rules[i] = createNewList();
//     Elements* arr1 = (Elements*)malloc(sizeof(Elements)*40);
//     Elements* arr3 = (Elements*)malloc(sizeof(Elements)*40);
//     Elements* arr4 = (Elements*)malloc(sizeof(Elements)*40);
//     Elements* arr5 = (Elements*)malloc(sizeof(Elements)*40);
//     // memset(arr1, TK_WRITE, sizeof(Elements)*40);
//     printf("%d\n", arr1[3]);
//     arr1[0] = TK_AND;
//     arr1[1] = TK_ASSIGNOP;
//     arr1[2] = TK_NOT; 
//     arr1[3] = TK_LE;
//     arr1[4] = 200;
//     arr3[0] = 0;
//     arr3[1] = 200;
//     arr4[0] = TK_WHILE;
//     arr4[1] = 200;
//     arr5[0] = 110;
//     arr5[1] = 200;

//     // arr3[]
//     printf("%d\n", arr1[3]);
//     // Elements arr2[] = {TK_CALL, TK_NULL, TK_LE};
//     // Elements arr3[] = {TK_DIV, TK_ASSIGNOP, TK_NULL, TK_LE};
//     // Elements arr4[] = {TK_MINUS, TK_ASSIGNOP, TK_NULL, TK_LE};
//     // Elements arr5[] = {TK_AND, TK_MUL, TK_NULL, TK_LE};
//     insertNodeLast(createNewNode(arr1), GG->rules[0]);
//     insertNodeLast(createNewNode(arr5), GG->rules[0]);
//     // insertNodeLast(createNewNode(arr2), GG->rules[0]);
//     insertNodeLast(createNewNode(arr3), GG->rules[3]);
//     insertNodeLast(createNewNode(arr4), GG->rules[3]);
//     // insertNodeLast(createNewNode(arr4), GG->rules[6]);
//     // insertNodeLast(createNewNode(arr5), GG->rules[7]);
//     FIRSTANDFOLLOW FnF = (FIRSTANDFOLLOW)malloc(sizeof(struct FirstAndFollow));
//     for(int i = 0; i<NUM_NONTERMS; i++){
//         FnF->firstSet[i] = (Elements*)malloc(sizeof(Elements));
//     }
//     findFirst(0, GG->rules[0], FnF);
//     findFirst(3, GG->rules[3], FnF);
//     Elements* y = FnF->firstSet[0];
//     int index = 0;
//     while(y[index]!=200){
//         printf("w%d\n", y[index++]);
//     }
//     y = FnF->firstSet[3];
//     index = 0;
//     while(y[index]!=200){
//         printf("s%d\n", y[index++]);
//     }
//     // FnF->firstSet = (Elements**)malloc(sizeof(Elements*)*NUM_NONTERMS);

//     return 0;
// }