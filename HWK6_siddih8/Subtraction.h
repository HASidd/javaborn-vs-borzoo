/*
* Name:				Hasan Siddiqui, Talha Ali, Asalat Kamal
* MacID:			siddih8, alit3, kamala6
* Student Number:	1450148, 1419194, 1417446
* Description: 		Declaration for Subtraction class, overrides ArithmeticExpression
					print() and evaluate() functions to use child expressions.
*/

#ifndef SUBTRACTION_H
#define SUBTRACTION_H

#include "ArithmeticExpression.h"

class Subtraction : public ArithmeticExpression
{
public:
	// Inherit ArithmeticExpression constructor
	Subtraction(string s, string a) :ArithmeticExpression(s, a) {};

	string evaluate();
	void print();
};

#endif