#ifndef ADDITION_H
#define ADDITION_H

#include "ArithmeticExpression.h"

class Addition : public ArithmeticExpression
{
	using ArithmeticExpression::ArithmeticExpression;
public:
	string evaluate();
	void print();
};

#endif