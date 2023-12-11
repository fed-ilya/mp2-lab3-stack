// mp2-lab3-stack.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "TStack.h"
#include "TCalculator.h"

using namespace std;

int main()
{
    TStack<int> st;
    string str;
    cin >> str;
    TCalculator Cal;
    cout << Cal.get_infix() << " " << Cal.get_postfix();
}
