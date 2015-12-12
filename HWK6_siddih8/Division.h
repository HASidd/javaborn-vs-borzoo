#ifndef DIVISION_H
#define DIVISION_H

#include "ArithmeticExpression.h"

class Division : public ArithmeticExpression
{
	using ArithmeticExpression::ArithmeticExpression;
public:
	string evaluate();
	void print();
};

#endif