#include "Multiplication.h"

#include <iostream>
using namespace std;

string Multiplication::evaluate()
{
	return string();
}

void Multiplication::print()
{
	// Print expression with brackets and calling corresponding print functions
	cout << "(";
	(*left).print();
	cout << "*";
	(*right).print();
	cout << ")";
}
