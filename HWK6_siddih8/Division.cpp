#include "Division.h"

#include <iostream>
using namespace std;

string Division::evaluate()
{
	return string();
}

void Division::print()
{
	// Print expression with brackets and calling corresponding print functions
	cout << "(";
	(*left).print();
	cout << "/";
	(*right).print();
	cout << ")";
}
