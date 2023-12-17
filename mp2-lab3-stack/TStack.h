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
				pMem = new T[MaxSize];
			}
			CurrInd = st.CurrInd;
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

	bool full() {
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
};

