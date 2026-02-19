/*
 * Source file for implementation of the ClauseSet declared in ClauseSet.h
 */

#include "ClauseSet.h"
#include "Clause.c"

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
    // exceeded max size?
    if (this->size >= MAX_CLAUSES)
    {
        return false;
    }

    // otherwise add the clause
    this.clauses[this->size] = clause;
    this->size++;
    return true;
}

bool removeClause(ClauseSet* this, int index)
{
    // check the index exists within the bounds
    if (index >= this->size)
    {
        return false;
    }

    // remove the clause and move all preceeding clauses back by one
    for (int j = index; j < this->size - 1; j++) {
        this.clauses[j] = this.clauses[j + 1];
    }

    return true;
}

Clause* getClause(ClauseSet* this, int index)
{
    if (index >= this->size)
    {
        return NULL;
    }

    return this.clauses[index];
}

int numberOfClauses(ClauseSet* this)
{
    return this->size;
}

bool isEmptyClauseSet(ClauseSet* this)
{
    return this->size == 0;
}

bool containsEmptyClause(ClauseSet* this)
{
    for (int i = 0; i < this->size; i++)
    {
        if (this->clauses[i].isEmptyClause())
        {
            return true;
        }
    }

    return false;
}

int findUnitClause(ClauseSet* this)
{
    for (int i = 0; i < this->size; i++)
    {
        if (this->clauses[i].isUnitClause())
        {
            return i;
        }
    }

    return -1;
};