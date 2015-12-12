#include "Subtraction.h"

#include <iostream>
using namespace std;

string Subtraction::evaluate()
{
	return string();
}

void Subtraction::print()
{
	// Print expression with brackets and calling corresponding print functions
	cout << "(";
	(*left).print();
	cout << "-";
	(*right).print();
	cout << ")";
}
