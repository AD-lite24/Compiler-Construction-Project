#include "../include/parser/parser.h"
#include "../include/datastructures/hashtable.h"
#include <stdio.h>
#include <stdlib.h>

Terminals stringToEnum(char * str) {
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
                    firstSet[line_count][0] = stringToEnum(token);
                }
                else { // for follow
                    followSet[line_count][0] = stringToEnum(token);
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

Terminals *First(char *nonterm) {}

Terminals *Follow(char *nonterm) {}