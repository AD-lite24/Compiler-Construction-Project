#include "parser/parse_table.h"


// ProdRule **createParseTable(FirstAndFollow F, ProdRule **parseTable) {
//     FILE *fp = fopen("ModifiedGrammar.txt", "r");
//     char buff[100];

//     if (!fp) {
//         printf("Error opening file");
//         return 1;
//     }

//     while (fgets(buff, sizeof(buff), fp) != NULL) {

//         buff[strcspn(buff, "\n")] = '\0';

//         char *token;
//         char *dash_position = strchr(buff, '-');

//         *dash_position = '\0';
//         char *first_part = buff;
//         char *second_part = dash_position + 1;

//         Elements x = stringToEnum(first_part); // non terminal LHS

//         char *token = strtok(second_part, ";");

//         while (token != NULL) {

//             ProdRule p1;
//             p1.LHS = x;
//             trim(token);

//             char *token1 = strtok(token, " ");
//             int count = 0;
//             Elements * x1;
//             while (token1 != NULL) {
//                 Elements y = stringToEnum(token1);
//                 p1.RHS[count++] = y;

//                 if (y != TK_EPSILON)
//                     x1 = computeFirstSpecial(p1);
//                 else
//                     x1 = computeFollowSpecial(p1);
//                 token1 = strtok(NULL, " ");
//             }
//             token = strtok(NULL, ";");

//             for (int i = 0; i < sizeof(x1)/sizeof(Elements); i++) {
//                 parseTable[x][x1[i]] = p1;
//             }
//         }
//     }

//     return parseTable;
// }

ProdRule convertLLtoProd(int i, NODE_LL rule) {
    ProdRule ans;
    ans.LHS = i;
    NODE_ELE ptr = rule->item->head;
    int index = 0;
    while (ptr != NULL) {
        ans.RHS[index++] = ptr->item;
        ptr = ptr->next;
    }
    return ans;
}

ProdRule **createParseTable(FIRSTANDFOLLOW F, ProdRule **ParseTable) {
    for (int i = 0; i < sizeof(grammar_glob) / sizeof(LL_LL); i++) {
        NODE_LL rule = grammar_glob->rules[i]->head;
        Elements *x;
        while (rule != NULL) {
            ProdRule prod_rule = convertLLtoProd(i, rule);
            if (checkEpsilonInFirst(rule->item) == 1) {
                x = computeFollowSpecial(prod_rule,F);
            } else {
                x = computeFirstSpecial(i,rule->item,F);
            }
            for (int j = 0; j < sizeof(x) / sizeof(Elements); j++) {
                ParseTable[i][x[j] - NUM_NONTERMS] = prod_rule;
            }
            rule = rule->next;
        }
    }
    return ParseTable;
}

void parseInputSourceCode(char *TestCaseFile, ProdRule **ParseTable) {

}
