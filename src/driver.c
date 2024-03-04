// #include "../include/lexer/lexer.h"
// #include "../include/lexer/lexerDef.h"
#include "../include/parser/parser.h"
// #include "../include/tokens/tokens.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


GRAMMAR grammar_glob;
ProdRule ParseTable[NUM_NONTERMS][NUM_TERMS+1];


int main() {
    int choice = -1;
    grammar_glob = (GRAMMAR)malloc(sizeof(grammar));
    parseFile("src/parser/ModifiedGrammar.txt");
    FIRSTANDFOLLOW fnfset = ComputeFirstAndFollowSets(grammar_glob);
    // while (1) {
        // printf("Please enter your choice:");
        // scanf("%d", &choice);
        choice = 3;
        if (choice == 0) {
            // break;
        }
        if (choice == 1) {
            FILE *fp1 = (FILE *)malloc(sizeof(FILE));
            fp1 = fopen("given_test_cases/test_cases/t1.txt", "r");

            FILE *fp2 = (FILE *)malloc(sizeof(FILE));
            fp2 = fopen("given_test_cases/test_output/WithoutCommentst1.txt",
                        "w+");

            removeComments(fp1, fp2);
            fclose(fp1);
            fclose(fp2);
        }
        if (choice == 2) {
            initLexer("given_test_cases/test_cases/t1.txt");
            printTokens();
        }
        if (choice == 3) {

            initLexer("given_test_cases/test_cases/t5.txt");
            initialiseParseTable();
            createParseTable(fnfset);
            synchPopulateParseTable(fnfset);
            TREE_NODE one = parseInputSourceCode();
            printParseTree(one, "given_test_cases/test_output/f_five.txt ");
        }

        if (choice == 4) {
            clock_t start_time, end_time;
            double total_CPU_time, total_CPU_time_in_seconds;
            start_time = clock();
            // invoke your lexer and parser here
            initLexer("given_test_cases/test_cases/t5.txt");
            initialiseParseTable();
            createParseTable(fnfset);
            synchPopulateParseTable(fnfset);
            TREE_NODE one = parseInputSourceCode();
            printParseTree(one, "given_test_cases/test_output/f_six.txt ");
            end_time = clock();
            total_CPU_time = (double)(end_time - start_time);
            total_CPU_time_in_seconds = total_CPU_time / CLOCKS_PER_SEC;
            // Print both total_CPU_time and total_CPU_time_in_seconds
            printf("Total CPU time: %lf", total_CPU_time);
            printf("Total CPU time in second: %lf", total_CPU_time_in_seconds);
        }
    // }
}