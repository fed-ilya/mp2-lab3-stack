#include "TCalculator.h"

TCalculator::TCalculator(string str){
	infix = str;
	ToPostfix();
	postfix = "";
}

TCalculator::~TCalculator() {
	cout << "321";
}

void TCalculator::set_infix(string str) {
	infix = str;
}

string TCalculator::get_infix() {
	return infix;
}

string TCalculator::get_postfix() {
	return postfix;
}

int TCalculator::prior(char op) {
	if (op == '(' || op == ')') return 0;
	else if (op == '+' || op == '-') return 1;
	else if (op == '*' || op == '/') return 2;
	else if (op == '^') return 3;
	else throw "Wrong operation";
}

double TCalculator::CalcPostfix() {//ÎÁÐÀÁÎÒÀÒÜ ÈÑÊËÞ×ÅÍÈß 2 3   2 3 ++. Âðîäå ñäåëàë
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
	else throw "Wrong stroka";
}

void TCalculator::ToPostfix() {
	ch.clear();
	oper.clear();
	string str = "(" + infix + ")";
	for (int i = 0; i < str.length(); ++i) {
		if (str[i] == '(') oper.push('(');
		else if ((str[i] >= '0') && (str[i] <= '9')) postfix += str[i];
		else if (str[i] == ')') {
			char el = oper.pop();
			while (el != '(') {
				postfix += el;
				el = oper.pop();
			}
		}
		else if ((str[i] == '+') || (str[i] == '-') || (str[i] == '*') || (str[i] == '/') || (str[i] == '^')) {
			char el = oper.top(); //top- à íå pop
			while (prior(el) >= prior(str[i])) {
				postfix += el;
				el = oper.pop();
			}
		}
	}
}

double TCalculator::Calc() {
	oper.clear(); ch.clear();
	string str = '(' + infix + ')';
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == '(') oper.push(str[i]);
		else if (str[i] == ')') {
			char el = oper.pop();
			while (el != '(') {
				double x2 = ch.pop();
				double x1 = ch.pop();
				double y = 0.0;
				if (el == '+') y = x1 + x2;
				else if (el == '-') y = x1 - x2;
				else if (el == '*') y = x1 * x2;
				else if (el == '/') y = x1 / x2;
				else if (el == '^') y = pow(x1, x2);
				ch.push(y); el = oper.pop();
			}
		}
		if (isdigit(str[i])) {
			size_t pos;
			double x;
			x = stod(&str[i], &pos);
			ch.push(x);
			i = i + pos - 1; //-1 èç-çà i++ â öèêëå
		}
		if ((str[i] == '+') || (str[i] == '-') || (str[i] == '*') || (str[i] == '/') || (str[i] == '^')) {
			char el = oper.pop(); //ìîæåò ch
			while (prior(el) >= prior(str[i])) {
				double y;
				double x2 = ch.pop(); double x1 = ch.pop();
				if (el == '+') y = x1 + x2;
				else if (el == '-') y = x1 - x2;
				else if (el == '*') y = x1 * x2;
				else if (el == '/') y = x1 / x2;
				else if (el == '^') y = pow(x1, x2);
				ch.push(y); el = oper.pop();
			}
			oper.push(el);
			oper.push(str[i]);
		}
	}
	return ch.pop();
}