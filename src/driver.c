#include "lexer.h"
#include "parser.h"
#include <pthread.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

GRAMMAR grammar_glob;
ProdRule ParseTable[NUM_NONTERMS][NUM_TERMS + 1];

// void *animation_thread(void *arg) {
//     while (1) {
//         printf("\033[0;33m"); // Start color change (0;33m corresponds to
//         orange) printf("\rPlease enter your choice: /"); printf("\033[0m");
//         fflush(stdout);
//         usleep(200000);
//         printf("\033[0;34m");
//         printf("\rPlease enter your choice: -");
//         printf("\033[0m");
//         fflush(stdout);
//         usleep(200000);
//         printf("\033[0;33m"); // Start color change (0;33m corresponds to
//         orange) printf("\rPlease enter your choice: \\"); printf("\033[0m");
//         fflush(stdout);
//         usleep(200000);
//         printf("\033[0;34m");
//         printf("\rPlease enter your choice: |");
//         printf("\033[0m");
//         fflush(stdout);
//         usleep(200000);
//     }
// }

int main() {

    int choice = -1;
    grammar_glob = malloc(sizeof(grammar));
    parseFile("../grammar.txt");
    FIRSTANDFOLLOW fnfset = ComputeFirstAndFollowSets();
    while (1) {
    // pthread_t tid;

    // if (pthread_create(&tid, NULL, animation_thread, NULL) != 0) {
    //     perror("pthread_create");
    //     return EXIT_FAILURE;
    // }

        printf("Please enter your choice:");
        scanf("%d", &choice);
    // pthread_cancel(tid);
    // pthread_join(tid, NULL);
        if (choice == 0) {
            break;
        }
        if (choice == 1) {
            FILE *fp1 = (FILE *)malloc(sizeof(FILE));
            fp1 = fopen("t3.txt", "r");

            FILE *fp2 = (FILE *)malloc(sizeof(FILE));
            fp2 = fopen("WithoutCommentst3.txt", "w+");

            removeComments(fp1, fp2);
            fclose(fp1);
            fclose(fp2);
        }
        if (choice == 2) {
            initLexer("t3.txt");
            printTokens();
        }

        if (choice == 3) {
            initLexer("t3.txt");
            initialiseParseTable();
            createParseTable(fnfset);
            synchPopulateParseTable(fnfset);
            TREE_NODE one = parseInputSourceCode();
            printParseTree(one, "t3_output.txt");
        }

        if (choice == 4) {
            clock_t start_time, end_time;
            double total_CPU_time, total_CPU_time_in_seconds;
            start_time = clock();
            // invoke your lexer and parser here
            initLexer("t3.txt");
            initialiseParseTable();
            createParseTable(fnfset);
            synchPopulateParseTable(fnfset);
            TREE_NODE one = parseInputSourceCode();
            printParseTree(one, "t3_output.txt");
            end_time = clock();
            total_CPU_time = (double)(end_time - start_time);
            total_CPU_time_in_seconds = total_CPU_time / CLOCKS_PER_SEC;
            // Print both total_CPU_time and total_CPU_time_in_seconds
            printf("Total CPU time: %lf \n", total_CPU_time);
            printf("Total CPU time in second: %lf \n", total_CPU_time_in_seconds);
        }
    }
    return 1;
}