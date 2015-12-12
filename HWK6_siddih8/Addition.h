#ifndef ADDITION_H
#define ADDITION_H

#include "ArithmeticExpression.h"

class Addition : public ArithmeticExpression
{
public:
	Addition(string leftSide, string rightSide);

	string evaluate();
	void print();
};

#endif