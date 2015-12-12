#include "ArithmeticExpression.h"
#include "Addition.h"
#include "Subtraction.h"
#include "Multiplication.h"
#include "Division.h"

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

// Parse a given string expression
ArithmeticExpression::Expression* parse(string expression)
{
	try
	{
		// Base case: Check if given string is a number, creating a corresponding expression if so
		return new ArithmeticExpression(stof(expression));
	}
	catch (const invalid_argument& e)	// Otherwise parse expression
	{

	}

	return parse("0");
}