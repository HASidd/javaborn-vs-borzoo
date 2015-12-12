#include "Addition.h"

Addition::Addition(string leftSide, string rightSide)
{
	
	*left = parse(leftSide);
	*right = parse(rightSide);
}