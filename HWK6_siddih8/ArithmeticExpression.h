#ifndef ARITHMETIC_H
/*
* Name:				Hasan Siddiqui, Talha Ali, Asalat Kamal
* MacID:			siddih8, alit3, kamala6
* Student Number:	1450148, 1419194, 1417446
* Description: 		Operators' parent class declaration, most functions and	child expressions for tree are declared here,
					though child expressions aren't used in some functions because no operator is defined.
*/

#define ARITHMETIC_H

#include "Expression.h"

class ArithmeticExpression : public Expression
{
protected:
	// Pointers for left and right operand expressions
	Expression *left;
	Expression *right;

public:
	ArithmeticExpression(string leftSide, string rightSide);	// Constructor for ArithmeticExpression from a left and right operand
	ArithmeticExpression(int number);							// Constructor for ArithmeticExpression from a single value
	~ArithmeticExpression();									// Destructor for ArithmeticExpression, calls deletion of subtrees

	static Expression * parse(string expression);	// Parses an expression in string format and returns a corresponding expression tree
	string evaluate();								// Evaluate expression tree and return result in string format
	void print();									// Print expression
	float convert(string s);						// Get float from string representation of number
	void increment();								// Increment each number in expression tree
};

#endif