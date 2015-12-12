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
ArithmeticExpression::ArithmeticExpression(float number)
{
	value = number;
	left = NULL;
	right = NULL;
}

string ArithmeticExpression::evaluate()
{
	
}

void ArithmeticExpression::print()
{
	cout << value;
}

float ArithmeticExpression::convert(string s)
{
	return 0.0f;
}

// Parse a given string expression
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
			// Store location
			leftBracket = i;

			// Start from end of expression
			i = expression.length() - 1;

			// Change i to location of matching right bracket, skipping contents of brackets
			while (expression.at(i) != ')')
				i--;

			// Store location
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

	if (addIndex != -1)
	{
		leftSide = expression.substr(0, addIndex);
		rightSide = expression.substr(addIndex + 1, expression.length() - addIndex - 1);
		return new Addition(leftSide, rightSide);
	}
	else if (subIndex != -1)
	{
		leftSide = expression.substr(0, subIndex);
		rightSide = expression.substr(subIndex + 1, expression.length() - subIndex - 1);
		return new Subtraction(leftSide, rightSide);
	}
	else if (multIndex != -1)
	{
		leftSide = expression.substr(0, multIndex);
		rightSide = expression.substr(multIndex + 1, expression.length() - multIndex - 1);
		return new Multiplication(leftSide, rightSide);
	}
	else if (divIndex != -1)
	{
		leftSide = expression.substr(0, divIndex);
		rightSide = expression.substr(divIndex + 1, expression.length() - divIndex - 1);
		return new Division(leftSide, rightSide);
	}

	// If brackets were found
	if (leftBracket != -1)
		// No operators were found outside brackets
		// Parse contents inside brackets
		return parse(expression.substr(leftBracket + 1, rightBracket - leftBracket - 1));

	// No operators were found, therefore expression is a number
	return new ArithmeticExpression(stof(expression));
}