#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
Реализация класса TStack
*/

template<class T>
struct TNode {
	T val;
	TNode* pNext;
};

template <class T>
class TLStack
{
	TNode<T>* pFirst;
public:
	TLStack() {
		pFirst = NULL;
	};

	~TLStack() {
		while (!empty()) pop();
	};

	TLStack(const TLStack<T>& st) {
		TNode<T>* tmp = new TNode<T>;
		tmp = st.pFirst;
		while (tmp != NULL) {
			pFirst = tmp;
			tmp = tmp->pNext;
		}
	};

	TLStack& operator=(const TLStack& st) {
		clear();
		TNode<T>* tmp = new TNode<T>;
		tmp = st.pFirst;
		vector<T> mas;
		while (tmp != NULL){
			mas.push_back(tmp->val);
			tmp = tmp->pNext;
		}
		reverse(mas.begin(), mas.end());
		for (int i = 0; i < mas.size(); i++) {
			push(mas[i]);
		}
		return *this;
	};

	int count() {
		TNode<T>* p = pFirst;
		int k = 0;
		while (p != nullptr) {
			p = p->pNext;
			k++;
		}
		return k;
	};

	bool empty() {
		return pFirst == NULL;
	};

	void push(const T& el) {
		TNode<T>* tmp = new TNode<T>;
		tmp->val = el;
		tmp->pNext = pFirst;
		pFirst = tmp;
	};

	T pop() {
		if (empty()) throw "Stack is empty";
		TNode<T>* p = pFirst;
		pFirst = pFirst->pNext;
		T el = p->val;
		delete p;
		return el;
	};

	T top() { //"Просто посмотреть"
		if (empty()) throw "Stack is empty";
		return pFirst->val;
	};

	void clear() {
		TNode<T>* tmp = pFirst;
		while (pFirst != NULL)
		{
			pFirst = pFirst->pNext;
			delete tmp;
			tmp = pFirst;
		}
	};
};

