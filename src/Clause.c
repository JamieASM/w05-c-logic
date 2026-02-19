/*
 * Source file for implementation of the Clause declared in Clause.h
 */

#include "Clause.h"

// Implement all the the functions declared in the Clause.h interface
Clause new_Clause()
{
    Clause this;
    this.size = 0;
    memset(this.literals, 0, sizeof(this.literals));
    return this;
}

bool addLiteral(Clause* this, int literal)
{
    // check that we havent exceeded the maximum number of literals
    if (this->size >= MAX_LITERALS)
    {
        return false;
    }

    // otherwise add the literal
    this.literals[this->size] = literal;
    this->size++;
    return true;
}

int getLiteral(Clause* this, int index)
{
    // check that the index is within bounds
    if (index > 0 && index < this->size)
    {
        return this.literals[index];
    }

    // otherwise return some err val
    return 0;
}

int numberOfLiterals(Clause* this)
{
    return this->size;
}

bool removeLiteral(Clause* this, int literal)
{
	// could use containsLiteral but then we would have to loop twice
    bool found = false;
	int i = 0;

	// have to do a while loop since the size will be changing
	while (i < this->size) {
		if (this.literals[i] == literal) {
			found = true;

			// move all elements back by one from there
			for (int j = i; j < this->size - 1; j++) {
				this.literals[j] = this.literals[j + 1];
			}
			this->size--;
		}
		else {
			i++
		}
	}

	return found;
}

bool containsLiteral(Clause* this, int literal)
{
    bool found = false;
	for (int i = 0; i < this->size; i++) {
		if (this.literals[i] == literal) {
			found = true;
			break;
		}
	}

	return found;
}

bool isEmptyClause(Clause* this)
{
    return this->size == 0;
}

bool isUnitClause(Clause* this)
{
    return this->size == 1;
}