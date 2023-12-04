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
	double CalcPostfix();
	void ToPostfix();
};

int TCalculator::prior(char op) {
	if (op == '(' || op == ')') return 0;
	else if (op == '+' || op == '-') return 1;
	else if (op == '*' || op == '/') return 2;
	else if (op == '^') return 3;
	else throw "Wrong operation";
}

double TCalculator::CalcPostfix() {//Œ¡–¿¡Œ“¿“‹ »— Àﬁ◊≈Õ»ﬂ 2 3   2 3 ++. ¬Ó‰Â Ò‰ÂÎ‡Î
	ch.clear();
	oper.clear();
	for (int i = 0; i < postfix.length(); ++i) {
		if (postfix[i] >= '0' && postfix[i] <= '9') ch.push(postfix[i] - '0');
		else if ((postfix[i] == '+') || (postfix[i] == '-') || (postfix[i] == '*') || (postfix[i] == '/') || (postfix[i] == '^')) {
			double x1, x2, y;
			x2 = ch.pop(); x1 = ch.pop();
			if (postfix[i] == '+') y = x1 + x2;
			else if (postfix[i] == '-') y = x1 - x2;
			else if (postfix[i] == '*') y = x1 * x2;
			else if (postfix[i] == '/') y = x1 / x2;
			else if (postfix[i] == '^') y = pow(x1, x2);
			ch.push(y);
		}
	}
	double y = ch.pop();
	if (ch.empty()) return y;
}
