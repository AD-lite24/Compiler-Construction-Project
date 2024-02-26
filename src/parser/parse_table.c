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
