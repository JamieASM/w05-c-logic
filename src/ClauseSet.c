/*
 * Source file for implementation of the ClauseSet declared in ClauseSet.h
 */

#include "ClauseSet.h"

// Implement all the the functions declared in the ClauseSet.h interface
ClauseSet new_ClauseSet()
{
    ClauseSet this;
    this.size = 0;
    memset(this.clauses, 0, sizeof(this.clauses));
    return this;
}

bool addClause(ClauseSet* this, Clause clause)
{

}

bool removeClause(ClauseSet* this, int index);

Clause* getClause(ClauseSet* this, int index);

int numberOfClauses(ClauseSet* this);

bool isEmptyClauseSet(ClauseSet* this);

bool containsEmptyClause(ClauseSet* this);

int findUnitClause(ClauseSet* this);