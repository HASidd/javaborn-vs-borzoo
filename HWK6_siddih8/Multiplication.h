/*
* Name:				Hasan Siddiqui, Talha Ali, Asalat Kamal
* MacID:			siddih8, alit3, kamala6
* Student Number:	1450148, 1419194, 1426466
* Description: 		bleh
*/

#ifndef MULTIPLICATION_H
#define MULTIPLICATION_H

#include "ArithmeticExpression.h"

class Multiplication : public ArithmeticExpression
{
	// Inherit ArithmeticExpression constructors
	using ArithmeticExpression::ArithmeticExpression;
public:
	string evaluate();
	void print();
};

#endif