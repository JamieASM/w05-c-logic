/*
 * DPLLMain.c
 *
 * This file is for the main function
 */

#include <stdlib.h>

#include "DPLL.h"
#include "DIMACS.h"

/*
 * This is the main entry point to your program where you will set things up to call your DPLL function on a set of clauses in a DIMACS file.
 * Note: as mentioned in the handout, your main function should take the filename of the DIMACS file as the first command-line argument in argv below.
 */
int main(int argc, char *argv[]) {
    // process the file argument
    DIMACS dimacs = DIMACS_open(argv[1]);

    // read the clauses
    ClauseSet clauseSet = new_ClauseSet();

    if (!DIMACS_readClauses(&dimacs, &clauseSet))
    {
        printf("Failed to read clauses\n");
        exit(1);
    }

    // close down DIMACS
    DIMACS_close(&dimacs);

    return 0;
}


