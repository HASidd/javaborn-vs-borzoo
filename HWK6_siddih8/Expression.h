#ifndef EXPRESSION_H
#define EXPRESSION_H

class Expression
{
	float value;
public:
	virtual string evaluate();	// evaluate expression and return string
								// representation of the result

	virtual void print();		// prints expression
};

#endif