#ifndef EXPRESSION_H
#define EXPRESSION_H

#include <string>

using namespace std;

class Expression
{
protected:
	float value;
public:
	virtual string evaluate();	// evaluate expression and return string
								// representation of the result

	virtual void print();		// prints expression
};

#endif