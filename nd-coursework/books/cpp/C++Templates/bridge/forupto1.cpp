// Copyright (c) 2017 by Addison-Wesley, David Vandevoorde, Nicolai M. Josuttis, and Douglas Gregor. All rights reserved.
// See the LICENSE file in the project root for more information.
//
// Name: forupto1.cpp
// Author: crdrisko
// Date: 07/27/2020-12:59:34
// Description: Enumerating integer values from 0 up to some value and providing each value to the given function object

#include <iostream>
#include <vector>

template<typename F>
void forUpTo(int n, F f)
{
    for (int i = 0; i != n; ++i)
        f(i);   // call passed function f for i
}

void printInt(int i) { std::cout << i << ' '; }

int main()
{
    std::vector<int> values;

    // insert values from 0 to 4:
    forUpTo(5, [&values](int i) { values.push_back(i); });

    // print elements
    forUpTo(5, printInt);   // prints 0 1 2 3 4
    std::cout << '\n';
}
