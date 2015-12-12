/*
* Name:				Hasan Siddiqui, Talha Ali, Asalat Kamal
* MacID:			siddih8, alit3, kamala6
* Student Number:	1450148, 1419194, 1426466
* Description: 		bleh
*/

#ifndef EXPRESSION_H
#define EXPRESSION_H

#include <string>

using namespace std;

class Expression
{
protected:
	int value;
public:
	virtual ~Expression();
	virtual string evaluate() = 0;	// evaluate expression and return string
									// representation of the result

	virtual void print() = 0;		// prints expression
	virtual void increment() = 0;	// increment all numbers in expression
};

#endif