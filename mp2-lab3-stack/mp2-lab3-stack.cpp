// mp2-lab3-stack.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "TStack.h"
#include "TCalculator.h"

using namespace std;

int main()
{
    TLStack<int> st;
    string str;
    cin >> str;
    TCalculator Cal(str);
    cout << Cal.get_infix() << " " << Cal.get_postfix() << endl;
    cout << Cal.Calc();
}
