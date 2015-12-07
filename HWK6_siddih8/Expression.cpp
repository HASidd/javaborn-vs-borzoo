#include <string>

using namespace std;

class Expression
{
	virtual string evaluate();	// evaluate expression and return string
								// representation of the result

	virtual void print();		// prints expression
};