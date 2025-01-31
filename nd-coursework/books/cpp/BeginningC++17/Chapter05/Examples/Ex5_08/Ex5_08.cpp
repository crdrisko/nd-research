// Copyright (c) 2018 Ivor Horton and Peter Van Weert. Some rights reserved.
// Licensed under the Freeware License. See the LICENSE file in the project root for more information.
//
// Name: Ex5_08.cpp
// Author: crdrisko
// Date: 04/27/2020-13:42:42
// Description: Using the continue statement to display ASCII character codes

#include <cctype>
#include <iomanip>
#include <iostream>
#include <limits>

int main()
{
    // Output the column headings
    std::cout << std::setw(11) << "Character " << std::setw(13) << "Hexadecimal " << std::setw(9) << "Decimal " << std::endl;
    std::cout << std::uppercase;   // Uppercase hex digits

    // Output characters and corresponding codes
    unsigned char ch {};
    do
    {
        if (!std::isprint(ch))                                           // If it's not printable
            continue;                                                    // ... skip this iteration
        std::cout << std::setw(6) << ch                                  // Character
                  << std::hex << std::setw(12) << static_cast<int>(ch)   // Hexadecimal
                  << std::dec << std::setw(10) << static_cast<int>(ch)   // Decimal
                  << std::endl;
    } while (ch++ < std::numeric_limits<unsigned char>::max());
}
