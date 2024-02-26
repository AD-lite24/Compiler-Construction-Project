#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void trim(char *str) {
    int start = 0;
    int end = strlen(str) - 1;

    while (str[start] == ' ')
        start++;
    while (end > start && str[end] == ' ')
        end--;

    memmove(str, str + start, end - start + 1);

    // // Null-terminate the trimmed string
    str[end - start + 1] = '\0';
}

int main() {
    char str[] = "  Test for - strtok ; unsure ; about ; while loops   ";
    trim(str);

    char *dash_position = strchr(str, '-');

    *dash_position = '\0';
    char *first_part = str;
    char *second_part = dash_position + 1;
    printf("%s\n",first_part);
    printf("%s\n",second_part);


    char *token = strtok(second_part, ";");
    
    while (token != NULL) {
        // For each substring obtained by splitting with ';'
        printf("Substring: %s\n", token);
        trim(token);
        // Split this substring by ' '
        char *subtoken = strtok(token, " ");
        
        // while (subtoken != NULL) {
        //     printf("  Word: %s\n", subtoken);
        //     subtoken = strtok(NULL, " ");
        // }
        
        // Get the next substring split by ';'
        token = strtok(NULL, ";");
    }
    return 0;
}