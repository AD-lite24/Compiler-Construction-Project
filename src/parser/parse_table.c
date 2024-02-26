#include "parser/parse_table.h"


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
ProdRule *** createParseTable(FIRSTANDFOLLOW F, GRAMMAR grammar_glob) {
    ProdRule ** ParseTable = malloc(NUM_NONTERMS*sizeof(ProdRule *));
    for (int i = 0;i<NUM_NONTERMS;i++) {
        ProdRule * ParseTableRow = malloc(NUM_TERMS*sizeof(ProdRule));

        // To mark a null entry in the table
        for (int j = 0; j < NUM_TERMS; j++) ParseTableRow[j].LHS = -1;
        ParseTable[i] = ParseTableRow;
    }
    for (int i = 0; i < sizeof(grammar_glob) / sizeof(LL_LL); i++) {
        NODE_LL rule = grammar_glob->rules[i]->head;
        Elements * x;
        while (rule != NULL) {
            ProdRule prod_rule = convertLLtoProd(i, rule);
            if (checkEpsilonInFirst(rule->item) == 1) {
                x = computeFollowSpecial(prod_rule,F);
            } else {
                x = computeFirstSpecial(i,rule->item,F);
            }
            for (int j = 0; j < sizeof(x) / sizeof(Elements); j++) {
                printf("%d\n, ", x[j]);
                
                int temp = x[j] - NUM_NONTERMS;
                if (temp < 0) {
                    printf("meh\n");
                    // break;
                };
                if (temp != -53) ParseTable[i][temp] = prod_rule;
            }
            rule = rule->next;
        }
    }
    return &ParseTable;
}

void parseInputSourceCode(char *TestCaseFile, ProdRule **ParseTable) {

}
