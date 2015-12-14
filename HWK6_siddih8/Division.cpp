/*
* Name:				Hasan Siddiqui, Talha Ali, Asalat Kamal
* MacID:			siddih8, alit3, kamala6
* Student Number:	1450148, 1419194, 1417446
* Description: 		Implementation for Division class functions, overrides ArithmeticExpression
					print() and evaluate() functions to use child expressions.
*/

#include "Division.h"

#include <iostream>
using namespace std;

// Evaluate current expression recursively down the expression tree, returning string representation of result
string Division::evaluate()
{
	float result;

	// Evaluate expression
	result = convert((*left).evaluate()) / convert((*right).evaluate());

	// Return string representation
	return to_string(result);
}

// Print expression
void Division::print()
{
	// Print expression with brackets and calling corresponding print functions
	cout << "(";
	(*left).print();
	cout << " / ";
	(*right).print();
	cout << ")";
}
