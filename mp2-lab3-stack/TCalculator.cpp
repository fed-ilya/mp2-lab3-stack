#include "TCalculator.h"
#include "TStack.h"

TCalculator::TCalculator(string str){
	infix = str;
	ToPostfix();
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
			char el = oper.top(); //top- ‡ ÌÂ pop
			//postfix += ' ';
			while (prior(el) >= prior(str[i])) { // >=
				el = oper.pop();
				postfix += el;
				el = oper.top();
			}
			oper.push(str[i]);
		}
		else if (str[i] == '.') {
			if ((str[i - 1] < '0') || (str[i - 1] > '9')) { postfix += '0'; postfix += str[i]; }
			else postfix += str[i];
		}
	}
}

double TCalculator::Calc() {
	oper.clear(); ch.clear();
	string str = '(' + infix + ')';
	str = infix_0(str);
	//string str = '(' + postfix + ')';
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
			i = i + pos - 1; //-1 ËÁ-Á‡ i++ ‚ ˆËÍÎÂ
		}
		if ((str[i] == '+') || (str[i] == '-') || (str[i] == '*') || (str[i] == '/') || (str[i] == '^')) {
			char el = oper.pop(); //ÏÓÊÂÚ ch
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

string TCalculator::infix_0(string str) {
	string res = "";
	for (int i = 0; i < str.size(); ++i) {
		if (str[i] == '.' && !isdigit(str[i-1])) res += '0';
		res += str[i];
	}
	return res;
}

bool TCalculator::proverka_skob(string str) {
	TStack<char> s(30);
	int res = 0;
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == '(') s.push(str[i]);
		else {
			if (str[i] == ')') {
				if (!s.empty()) s.pop();
				else res = 1;
			}
		}
	}
	if (!s.empty()) res = 2;
	if (res == 0) return true;
	else return false;
	/*
	else if (res == 1) throw "ÀË¯Ìˇˇ ')'";
	else throw "ÀË¯Ìˇˇ '('";
	*/
};