// Name: Exercise3_06.cpp - Version 1.0.0
// Author: cdrisko
// Date: 04/23/2020-14:55:57
// Description: Swap two values without defining a third placeholder value

#include <iostream>

int main()
{
    long a {}, b {};
    std::cout << "Enter two integers separated by spaces: ";
    std::cin  >> a >> b;

    a ^= b;
    b ^= a;
    a ^= b;

    std::cout << "In reverse order that is: " << a << " " << b << std::endl;
}
