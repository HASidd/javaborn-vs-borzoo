#include "Subtraction.h"

#include <iostream>
using namespace std;

string Subtraction::evaluate()
{
	float result;

	result = convert((*left).evaluate()) - convert((*right).evaluate());

	return to_string(result);
}

void Subtraction::print()
{
	// Print expression with brackets and calling corresponding print functions
	cout << "(";
	(*left).print();
	cout << " - ";
	(*right).print();
	cout << ")";
}
