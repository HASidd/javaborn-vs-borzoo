/*
* Name:				Hasan Siddiqui, Talha Ali, Asalat Kamal
* MacID:			siddih8, alit3, kamala6
* Student Number:	1450148, 1419194, 1426466
* Description: 		bleh
*/

#ifndef EXPRESSION_H
#define EXPRESSION_H

#include <string>

using namespace std;

class Expression
{
protected:
	int value;						// Value of expression, used for expressions formed by just a number
public:
	virtual ~Expression();			// Virtual destructor for expression

	virtual string evaluate() = 0;	// Evaluate expression tree and return result in string format
	virtual void print() = 0;		// Print expression
	virtual void increment() = 0;	// Increment all numbers in expression
};

#endif