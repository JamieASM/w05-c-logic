/*
 * DPLL.c
 * This is the source file where you will implement DPLL
 *
 *
 */

#include <stdio.h>
#include "DPLL.h"

#include <stdlib.h>

/*
 * Below here is where you can put any static (akin to "private") helper functions not listed in the module interface
 */
ClauseSet* RemoveLiteral(ClauseSet* this, int literal)
{
	int index = 0;

	while (index < numberOfClauses(this)) {
		Clause* clause = getClause(this, index);

		if (containsLiteral(clause, literal))
		{
			// printf("contains literal %d\n", literal);
			removeClause(this, index);
			continue;
		}
		if (containsLiteral(clause, -literal))
		{
			// printf("contains neg literal %d\n", -literal);
			removeLiteral(clause, -literal);
		}

		index++;
	}

	return this;
}

/*
 * This is where you must implement all non-static (akin to "public") functions listed in the module interface
 */
bool DPLL(ClauseSet* this)
{
	if (isEmptyClauseSet(this)) return true;
	if (containsEmptyClause(this)) return false;

	// Otherwise, we will find a unit clause
	int index = findUnitClause(this);
	int literal;

	if (index != -1)
	{
		literal = getLiteral(getClause(this, index), 0);
		return DPLL(RemoveLiteral(this, literal));
	}

	ClauseSet branch1 = *this;
	ClauseSet branch2 = *this;
	literal = getLiteral(getClause(this, 0), 0);

	if (DPLL(RemoveLiteral(&branch1, literal)))
	{
		return true;
	}

	return DPLL(RemoveLiteral(&branch2, -literal));
}