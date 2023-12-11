#pragma once
#include <iostream>
using namespace std;

/*
Реализация класса TStack
*/

template <class T>
class TStack
{
	T* pMem;
	int MaxSize;
	int CurrInd;
public:
	TStack(int _MaxSize = 10) {
		if (_MaxSize > 0) {
			MaxSize = _MaxSize;
			pMem = new T[MaxSize];
			CurrInd = -1;
		}
		else throw "wrong Size";
	};

	~TStack() {
		delete[] pMem;
	};

	TStack(const TStack& st) {
		MaxSize = st.MaxSize;
		CurrInd = st.CurrInd;
		pMem = new T[MaxSize];
		for (int i = 0; i <= MaxSize; i++) {
			pMem[i] = st.pMem[i];
		}
	};

	TStack& operator=(const TStack& st) {
		if (this != &st) {
			if (MaxSize != st.MaxSize) {
				delete[] pMem;
				MaxSize = st.MaxSize;
				CurrInd = st.CurrInd;
				pMem = new T[MaxSize];
			}
			for (int i = 0; i < MaxSize; i++) {
				pMem[i] = st.pMem[i];
			}
		}
		return *this;
	};

	void print() {
		for (int i = 0; i < MaxSize; i++) {
			cout << pMem[i] << endl;
		}
	};

	bool empty() {
		if (CurrInd == -1) return true;
		else return false;
	};

	bool fool() {
		if (CurrInd == MaxSize - 1) return true;
		else return false;
	};

	void push(const T& el) {
		if (CurrInd + 1 >= MaxSize) throw "Stack overflow";
		pMem[CurrInd + 1] = el;
		CurrInd++;
	};

	T pop() {
		if (CurrInd == -1) throw "Stack is empty";
		CurrInd--;
		return pMem[CurrInd + 1];
	};
	
	T top() { //"Просто посмотреть"
		if (CurrInd == -1) throw "Stack is empty";
		return pMem[CurrInd];
	};

	void clear() { CurrInd = -1; };

	bool proverka_skob(string str) {
		TStack<char> s(20);
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
		else if (res == 1) throw "Лишняя ')'";
		else throw "Лишняя '('";
	};
};

