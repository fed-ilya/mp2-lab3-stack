#pragma once
#include <string>
#include "TStack.h"
using namespace std;

class TCalculator
{
	TStack<double> ch;
	TStack<char> oper;
	string infix, postfix;
	int prior(char op);
public:
	TCalculator();
	~TCalculator();
	double CalcPostfix();
	void ToPostfix();
	double Calc();
};
