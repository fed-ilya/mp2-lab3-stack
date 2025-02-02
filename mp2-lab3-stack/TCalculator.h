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
	TCalculator(string str = "1 + 2");
	void set_infix(string str);
	string get_infix();
	string get_postfix();
	string infix_0(string str);
	double CalcPostfix();
	void ToPostfix();
	double Calc();
	bool proverka_skob(string str);
};
