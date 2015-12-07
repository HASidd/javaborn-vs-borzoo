#include <string>
#include "Expression.h"

using namespace std;

class ArithmeticExpression : public Expression
{
	Expression *left;
	Expression *right;
	virtual string evaluate();	// evaluate expression and return string
								// representation of the result

	virtual void print();		// prints expression
};