// HWK6_siddih8.cpp : Defines the entry point for the console application.
//

using namespace std;

#include <iostream>
#include <string>

#include "Expression.h"
#include "ArithmeticExpression.h"
#include "Addition.h"
#include "Subtraction.h"
#include "Multiplication.h"
#include "Division.h"

int main()
{
	Expression * expression;
	string expressionInput = "";

	while (true)
	{
		cout << "Enter an expression:\n";

		getline(cin, expressionInput);

		if (expressionInput == "#")
			break;

		expression = ArithmeticExpression::parse(expressionInput);

		(*expression).print();

		cout << " = " << (*expression).evaluate() << "\n\n";

		delete expression;
	}

	cout << "\n";

    return 0;
}