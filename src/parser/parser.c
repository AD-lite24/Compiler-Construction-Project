#include "../include/parser/parser.h"
#include "../include/datastructures/hashtable.h"
#include <stdio.h>
#include <stdlib.h>

void parseFile(char *filename, int table_type) {

    FILE *fp = fopen(filename, "r");

    if (!fp) {
        print("Error in opening file\n");
        return;
    }

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

        if (!table_type) {
            
        }

        else {

        }
    

        if (start_bracket != NULL && end_bracket != NULL) {

            int length = end_bracket - start_bracket - 1;
            char content[length + 1];
            strncpy(content, start_bracket + 1, length);
            content[length] = '\0'; 

            // Tokenize the content
            char *token = strtok(content, ",");

            // Extract and print input_par
            if (token != NULL) {
                printf("input_par: %s\n", token);
            }

            // Print remaining tokens (if any)
            while ((token = strtok(NULL, ",")) != NULL) {
                printf("%s\n", token);
            }
        }
    }
}

Terminals *First(char *nonterm) {}

Terminals *Follow(char *nonterm) {}