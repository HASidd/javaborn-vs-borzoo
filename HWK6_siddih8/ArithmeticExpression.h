#ifndef ARITHMETIC_H
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