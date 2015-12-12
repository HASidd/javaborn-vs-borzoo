#ifndef SUBTRACTION_H
#define SUBTRACTION_H

#include "ArithmeticExpression.h"

class Subtraction : public ArithmeticExpression
{
	using ArithmeticExpression::ArithmeticExpression;
public:
	string evaluate();
	void print();
};

#endif