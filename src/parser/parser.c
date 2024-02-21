#include "../include/parser/parser.h"
#include "../include/datastructures/hashtable.h"
#include <stdio.h>
#include <stdlib.h>

Terminals stringToEnumTerm(char * str) {
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
    else if (strcmp(str,"EPSILON") == 0) {
        return EPSILON;
    }
    else if (strcmp(str,"DOLLAR") == 0) {
        return DOLLAR;
    }
}

NonTerminals stringToEnumNonTerm(char * str) {
    if (strcmp(str,"program") == 0) {
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
    else if (strcmp(str,"datatype") == 0) {
        return datatype;
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
    else if (strcmp(str,"assignmentStmt") == 0) {
        return assignmentStmt;
    }
    else if (strcmp(str,"singleOrRecId") == 0) {
        return singleOrRecId;
    }
    else if (strcmp(str,"singleOrRecIdLF") == 0) {
        return singleOrRecIdLF;
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
    else if (strcmp(str,"conditionalStmtLF") == 0) {
        return conditionalStmtLF;
    }
    else if (strcmp(str,"ioStmt") == 0) {
        return ioStmt;
    }
    else if (strcmp(str,"arithmeticExpression") == 0) {
        return arithmeticExpression;
    }
    else if (strcmp(str,"plusMinusLF") == 0) {
        return plusMinusLF;
    }
    else if (strcmp(str,"multDivExpr") == 0) {
        return multDivExpr;
    }
    else if (strcmp(str,"multDivLR") == 0) {
        return multDivLR;
    }
    else if (strcmp(str,"multDivLF") == 0) {
        return multDivLF;
    }
    else if (strcmp(str,"outerMost") == 0) {
        return outerMost;
    }
    else if (strcmp(str,"booleanExpression") == 0) {
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