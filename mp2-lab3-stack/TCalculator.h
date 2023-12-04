#pragma once
#include <string>
using namespace std;

class TCalculator
{
	string infix, postfix;
	int prior(char op);
public:
	TCalculator();

};

int prior(char op) {
	
}
