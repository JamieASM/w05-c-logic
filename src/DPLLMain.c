/*
 * DPLLMain.c
 *
 * This file is for the main function
 */

#include <stdlib.h>
#include <stdio.h>

#include "DPLL.h"
#include "DIMACS.h"

/*
 * This is the main entry point to your program where you will set things up to call your DPLL function on a set of clauses in a DIMACS file.
 * Note: as mentioned in the handout, your main function should take the filename of the DIMACS file as the first command-line argument in argv below.
 */
int main(int argc, char *argv[]) {
    // check for no args
    if (argc == 1)
    {
        printf("No arguments provided\nCorrect usage: './DPLLMain {filename}'");
        exit(1);
    }

    // process the file argument
    DIMACS dimacs = DIMACS_open(argv[1]);

    // check that the file has been able to open
    if (!dimacs.stream)
    {
        printf("Failed to read the file provided. Check that '%s' exists.\nCorrect usage: './DPLLMain {filename}'", argv[1]);
        exit(1);
    }

    // read the clauses
    ClauseSet clauseSet = new_ClauseSet();

    if (!DIMACS_readClauses(&dimacs, &clauseSet))
    {
        printf("Input Error\n");
        exit(1);
    }

    // close down DIMACS
    DIMACS_close(&dimacs);

    // now we actually do the DPLL Algorithm
    if (DPLL(&clauseSet))
    {
        printf("true\n");
    }
    else
    {
        printf("false\n");
    }

    return 0;
}


