#ifndef MULTIPLICATION_H
#define MULTIPLICATION_H

#include "ArithmeticExpression.h"

class Multiplication : public ArithmeticExpression
{
	using ArithmeticExpression::ArithmeticExpression;
public:
	string evaluate();
	void print();
};

#endif