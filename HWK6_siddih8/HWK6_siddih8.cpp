/*
* Name:				Hasan Siddiqui, Talha Ali, Asalat Kamal
* MacID:			siddih8, alit3, kamala6
* Student Number:	1450148, 1419194, 1426466
* Description: 		bleh
*/

using namespace std;

#include <iostream>
#include <string>

#include "Expression.h"
#include "ArithmeticExpression.h"
#include "Addition.h"
#include "Subtraction.h"
#include "Multiplication.h"
#include "Division.h"

struct operators {
	char plus = '+';
	char minus = '-';
	char divide = '/';
	char multiply = '*';
};

bool isValid(string input, operators a);

int main()
{
	// Create Expression pointer and string to hold input
	Expression * expression;
	string expressionInput = "";

	// Loop until break is called
	while (true)
	{
		// Prompt user for expression
		cout << "Enter an expression:\n";
		getline(cin, expressionInput);

		// If exit character # is entered, break loop
		if (expressionInput == "#")
			break;

		// Create operators struct for checking validity of input
		operators a;

		// If input is a valid expression
		if (isValid(expressionInput, a))
		{
			// Create expression tree from input
			expression = ArithmeticExpression::parse(expressionInput);

			// Print expression back out
			(*expression).print();

			// Print result
			cout << " = " << (*expression).evaluate() << "\n\n";

			// Delete expression tree
			delete expression;
		}
	}

    return 0;
}

bool isValid(string input, operators a)
{
	bool openbracket = false;
	bool closebracket = false;
	bool found = false;

	for (int i = 0; i < input.size(); i++)
	{
		if (input.at(i) == a.plus || input.at(i) == a.minus || input.at(i) == a.divide || input.at(i) == a.multiply)
		{
			found = true;
		}
	}

	if (found == false)
	{
		cout << "Input is not an expression:";
		return false;
	}

	for (int i = 1; i < input.size(); i++)
	{
		if (input.at(i) == a.plus || input.at(i) == a.minus || input.at(i) == a.divide || input.at(i) == a.multiply)
		{
			if (input.at(i - 1) == a.plus || input.at(i - 1) == a.minus || input.at(i - 1) == a.divide || input.at(i - 1) == a.multiply)
			{
				return false;
			}
		}
	}

	for (int i = 0; i < input.size(); i++)
	{
		if (input.at(i) > 'A' && input.at(i) < 'z')
			return false;
	}

	int openbracketcounter = 0;
	int closebracketcounter = 0;

	for (int i = 0; i < input.size(); i++)
	{
		if (input.at(i) == '(')
			openbracketcounter++;

		if (input.at(i) == ')')
			closebracketcounter++;
	}

	if (openbracketcounter != closebracketcounter)
		return false;

	if (input.at(0) == ')')
		return false;

	return true;
}