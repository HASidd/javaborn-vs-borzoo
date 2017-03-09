/*
* Name:				Hasan Siddiqui, Talha Ali, Asalat Kamal
* MacID:			siddih8, alit3, kamala6
* Student Number:	1450148, 1419194, 1417446
* Description: 		Manages user input and sanity checks, and manages Expression type objects.
*/

using namespace std;

#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <algorithm>

#include "Expression.h"
#include "ArithmeticExpression.h"
#include "Addition.h"
#include "Subtraction.h"
#include "Multiplication.h"
#include "Division.h"

// The main class is used as the main process for the program, it will handle the different inputs of the program and output the corresponding errors.
// The class will also handle any IsValid logic as it will make it easier to locate errors within the string. 
bool isValid(string input);

int main()
{
	// Create Expression pointer and string to hold input
	Expression * expression = NULL;
	string expressionInput = "";
	float result;

	// Loop until break is called
	while (true)
	{
		// Prompt user for expression
		cout << "Enter an expression:\n";
		getline(cin, expressionInput);

		// If exit character # is entered, break loop
		if (expressionInput == "#")
		{
			// Delete expression tree if it exists
			delete expression;
			break;
		}

		// If increment character is entered and previous expression exists
		if (expressionInput == "@" && expression != NULL)
		{
			// Increment previous expression tree
			(*expression).increment();

			// Print new expression out
			(*expression).print();
			
			// Evaluate expression tree
			result = stof((*expression).evaluate());

			// Print result
			cout << fixed;
			cout << setprecision(2);
			cout << " = " << result << "\n\n";
		}
		else if (isValid(expressionInput))	// If input is a valid expression
		{
			// Delete previous expression tree
			delete expression;

			// Remove spaces from input
			expressionInput.erase(remove_if(expressionInput.begin(), expressionInput.end(), isspace), expressionInput.end());

			// Create expression tree from input
			expression = ArithmeticExpression::parse(expressionInput);

			// Print expression back out
			(*expression).print();

			// Evaluate expression tree
			result = stof((*expression).evaluate());

			// Print result
			cout << fixed;
			cout << setprecision(2);
			cout << " = " << result << "\n\n";
		}
		else
		{
			cout << "Expression is not well formed.\n\n";
		}
	}

    return 0;
}

// Check if given expression is well-formed, by well formed this means that it doesn't have any invalid characters and to see if the
// exoression being evaluated is correct
bool isValid(string input)
{
	//Below are the constant allocation for logic analysis
	const string OPERATOR = "+-*/";				
	const string NUMBER = "1234567890()";		
	const string LEFTOPERAND = "1234567890)";	
	const string RIGHTOPERAND = "1234567890(";	
	const string VALID_CHARACTERS = "1234567890+-*/() ";	

	string left, right;							// Strings to hold left and right side of operator
	char currentChar;							// Current character being checked
	int leftBrackets = 0, rightBrackets = 0;	// Left and right bracket counters

	// Check for invalid characters
	if (input.find_first_not_of(VALID_CHARACTERS) != string::npos)
		return false;

	// Check if input is blank
	if (input.find_first_not_of(' ') == string::npos)
		return false;

	// Loop through input characters, and begins the main process of the function
	for (int i = 0; i < input.size(); i++)
	{
		currentChar = input.at(i);

		// Count number of open brackets
		if (input.at(i) == '(')
			leftBrackets++;

		// Count number of close brackets
		if (input.at(i) == ')')
		{
			rightBrackets++;

			// If unpaired right bracket is found, return false
			if (rightBrackets > leftBrackets)
				return false;

			// Get first non-space character to left of close bracket
			currentChar = input.at(input.find_last_not_of(' ', i - 1));

			// If no number found in brackets
			if (currentChar == '(')
				return false;
		}


		// If current character is in OPERATORS
		if (OPERATOR.find(currentChar) != string::npos)
		{
			// Get strings to left and right of operator
			left = input.substr(0, i);
			right = input.substr(i + 1, input.length() - i - 1);

			// Get first non-space character to left of operator
			if (left.find_last_not_of(' ') == string::npos)
				return false;
			else if (currentChar != '-')	// If operator is not subtraction
			{
				// Get first non-space character to left of operator
				currentChar = left.at(left.find_last_not_of(' '));

				// If character is invalid
				if (LEFTOPERAND.find(currentChar) == string::npos)
					return false;
			}
			else	// If operator is subtraction, include '(' in valid characters
			{
				// Get first non-space character to left of operator
				currentChar = left.at(left.find_last_not_of(' '));

				// If character is invalid
				if (NUMBER.find(currentChar) == string::npos)
					return false;
			}

			// Get first non-space character to right of operator
			if (right.find_first_not_of(' ') == string::npos)
				return false;
			else
				currentChar = right.at(right.find_first_not_of(' '));

			// If character is invalid
			if (RIGHTOPERAND.find(currentChar) == string::npos)
				return false;
		}
	}

	// Split string at spaces
	istringstream spaceCheck(input);
	string token = ")", lastToken = "(";

	// Loop while input stream continues to see If two numbers are found next to each other return false
	while (spaceCheck >> token)
	{
		if (LEFTOPERAND.find(lastToken.at(lastToken.length()-1)) != string::npos
			&& RIGHTOPERAND.find(token.at(0)) != string::npos)
		{
			return false;
		}

		lastToken = token;
	}

	// Check if number of open and close brackets match
	if (leftBrackets != rightBrackets)
		return false;

	return true;
}