#ifndef ARITHMETIC_H
#define ARITHMETIC_H

class ArithmeticExpression : public Expression
{
	Expression *left;
	Expression *right;

public:
	string evaluate();
	void print();
	float convert(string s);
};

#endif