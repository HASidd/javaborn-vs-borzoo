#ifndef ARITHMETIC_H
/*
* Name:				Hasan Siddiqui, Talha Ali, Asalat Kamal
* MacID:			siddih8, alit3, kamala6
* Student Number:	1450148, 1419194, 1426466
* Description: 		bleh
*/

#define ARITHMETIC_H

#include "Expression.h"

class ArithmeticExpression : public Expression
{
protected:
	Expression *left;
	Expression *right;

public:
	ArithmeticExpression(string leftSide, string rightSide);
	ArithmeticExpression(int number);
	~ArithmeticExpression();
	static Expression * parse(string expression);

	string evaluate();
	void print();
	float convert(string s);
};

#endif