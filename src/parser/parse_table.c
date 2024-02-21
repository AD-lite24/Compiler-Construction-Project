#include "parser/parse_table.h"
#include "parser/parser.h"
#include <stdio.h>
#include <stdlib.h>

ProdRule **createParseTable(FirstAndFollow F, ProdRule **parseTable) {
    FILE *fp = fopen("ModifiedGrammar.txt", "r");
    char buff[100];

    if (!fp) {
        printf("Error opening file");
        return 1;
    }

    while (fgets(buff, sizeof(buff), fp) != NULL) {

        buff[strcspn(buff, "\n")] = '\0';

        char *token;
        char *dash_position = strchr(buff, '-');

        *dash_position = '\0';
        char *first_part = buff;
        char *second_part = dash_position + 1;

        NonTerminals x = stringToEnumNonTerm(first_part); // non terminal LHS

        char *token = strtok(second_part, ";");

        while (token != NULL) {

            ProdRule p1;
            p1.LHS = x;
            trim(token);

            char *token1 = strtok(token, " ");
            int count = 0;
            Terminals * x1;
            while (token1 != NULL) {
                Elements y = stringToEnum(token1);  
                p1.RHS[count++] = y;
                
                if (y !=EPSILON)
                    x1 = computeFirstSpecial(p1, grammar G);
                else
                    x1 = computeFollowSpecial(p1, grammar G);
                token1 = strtok(NULL, " ");
            }
            token = strtok(NULL, ";");

            for (int i = 0; i < sizeof(x1)/sizeof(Terminals); i++) {
                parseTable[x][x1[i]] = p1;
            }


        }
    }

    return parseTable;
}
