/*
* Name:				Hasan Siddiqui, Talha Ali, Asalat Kamal
* MacID:			siddih8, alit3, kamala6
* Student Number:	1450148, 1419194, 1417446
* Description: 		Operators' parent class implementation, most functions including constructors and destructors defined here,
					though int value data member is used instead of child expressions in some functions because no operator is defined.
*/

#include "ArithmeticExpression.h"
#include "Addition.h"
#include "Subtraction.h"
#include "Multiplication.h"
#include "Division.h"

#include <iostream>

using namespace std;

// Create an expression consisting of a left and right operand
ArithmeticExpression::ArithmeticExpression(string leftSide, string rightSide)
{
	left = parse(leftSide);
	right = parse(rightSide);
}

// Create an expression consisting solely of a number
ArithmeticExpression::ArithmeticExpression(int number)
{
	value = number;
	left = NULL;
	right = NULL;
}

// Destroys expression object and member expression objects
ArithmeticExpression::~ArithmeticExpression()
{
	delete left;
	delete right;
}

// Returns value of expression, assuming just a number since no operator specified
string ArithmeticExpression::evaluate()
{
	return to_string(value);
}

// Prints expression, assuming just a number since no operator specified
void ArithmeticExpression::print()
{
	// If number is negative, print with brackets, otherwise print normally
	if (value < 0)
		cout << "(" << value << ")";
	else
		cout << value;
}

// Convert given number in string format to float
float ArithmeticExpression::convert(string number)
{
	return stof(number);
}


void ArithmeticExpression::increment()
{
	if (left == NULL)
		value++;
	else
	{
		(*left).increment();
		(*right).increment();
	}
}

// Parse a given string expression and return corresponding expression tree
Expression * ArithmeticExpression::parse(string expression)
{

	// Define variables for location of operators in expression
	int addIndex = -1, subIndex = -1, multIndex = -1, divIndex = -1;
	int leftBracket = -1, rightBracket = -1;

	// Begin from start of string
	for (int i = 0; i < expression.length(); i++)
	{
		// If left bracket is encountered
		if (expression.at(i) == '(')
		{
			// Store location of left bracket
			leftBracket = i;

			int bracketLevel = 1;

			// Increment i until matching right bracket is found
			while (bracketLevel > 0)
			{
				i++;

				if (expression.at(i) == ')')
					bracketLevel--;
				else if (expression.at(i) == '(')
					bracketLevel++;
			}

			// Store location of right bracket
			rightBracket = i;
		}

		// Set indexes to last occurence of corresponding operator
		if (expression.at(i) == '+')
			addIndex = i;
		else if (expression.at(i) == '-')
			subIndex = i;
		else if (expression.at(i) == '*')
			multIndex = i;
		else if (expression.at(i) == '/')
			divIndex = i;
	}

	// Create strings for left and right operand
	string leftSide, rightSide;

	// Checks if operator is found in correct order of operations, and creates corresponding object
	if (addIndex != -1)
	{
		// Gets left side and right side of expression by splitting expression string at index of operator
		leftSide = expression.substr(0, addIndex);
		rightSide = expression.substr(addIndex + 1, expression.length() - addIndex - 1);

		// Return new Addition object
		return new Addition(leftSide, rightSide);
	}
	else if (subIndex != -1)
	{
		// Gets left side and right side of expression by splitting expression string at index of operator
		leftSide = expression.substr(0, subIndex);
		rightSide = expression.substr(subIndex + 1, expression.length() - subIndex - 1);

		// If left side contains an expression
		if (leftSide.find_first_not_of(' ') != string::npos)
			// Return new Subtraction object
			return new Subtraction(leftSide, rightSide);
		
		// Otherwise it is just a negative number
	}
	else if (multIndex != -1)
	{
		// Gets left side and right side of expression by splitting expression string at index of operator
		leftSide = expression.substr(0, multIndex);
		rightSide = expression.substr(multIndex + 1, expression.length() - multIndex - 1);

		// Return new Multiplication object
		return new Multiplication(leftSide, rightSide);
	}
	else if (divIndex != -1)
	{
		// Gets left side and right side of expression by splitting expression string at index of operator
		leftSide = expression.substr(0, divIndex);
		rightSide = expression.substr(divIndex + 1, expression.length() - divIndex - 1);

		// Return new Division object
		return new Division(leftSide, rightSide);
	}

	// If brackets were found
	if (leftBracket != -1)
		// No operators were found outside brackets
		// Parse contents inside brackets
		return parse(expression.substr(leftBracket + 1, rightBracket - leftBracket - 1));

	// No valid operations were found, therefore expression is a number
	return new ArithmeticExpression(stoi(expression));
}