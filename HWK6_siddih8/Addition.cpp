#include "Addition.h"

#include <iostream>
using namespace std;

string Addition::evaluate()
{
	return string();
}

void Addition::print()
{
	// Print expression with brackets and calling corresponding print functions
	cout << "(";
	(*left).print();
	cout << "+";
	(*right).print();
	cout << ")";
}
