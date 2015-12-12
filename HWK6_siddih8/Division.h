#ifndef DIVISION_H
#define DIVISION_H

#include "ArithmeticExpression.h"

class Division : public ArithmeticExpression
{
public:
	string evaluate();
	void print();
};

#endif