/*
* Name:				Hasan Siddiqui, Talha Ali, Asalat Kamal
* MacID:			siddih8, alit3, kamala6
* Student Number:	1450148, 1419194, 1426466
* Description: 		bleh
*/

#include "Division.h"

#include <iostream>
using namespace std;

string Division::evaluate()
{
	float result;

	result = convert((*left).evaluate()) / convert((*right).evaluate());

	return to_string(result);
}

void Division::print()
{
	// Print expression with brackets and calling corresponding print functions
	cout << "(";
	(*left).print();
	cout << " / ";
	(*right).print();
	cout << ")";
}
