// Copyright (c) 2018 Ivor Horton and Peter Van Weert. Some rights reserved.
// Licensed under the Freeware License. See the LICENSE file in the project root for more information.
//
// Name: Ex6_07.cpp
// Author: crdrisko
// Date: 05/01/2020-16:20:48
// Description: Using smart pointers

#include <cctype>   // For std::toupper()
#include <iomanip>
#include <iostream>
#include <memory>   // For smart pointers
#include <vector>   // For vector container

int main()
{
    std::vector<std::shared_ptr<std::vector<double>>> records;   // Temperature records by days
    std::size_t day {1};                                         // Day number

    while (true)   // Collect temperatures by day
    {
        // Vector to store current day's temperatures created in the free store
        auto day_records {std::make_shared<std::vector<double>>()};
        records.push_back(day_records);   // Save pointer in records vector

        std::cout << "Enter the temperatures for day " << day++ << " separated by spaces. Enter 1000 to end:\n";

        while (true)
        {                  // Get temperatures for current day
            double t {};   // A temperature
            std::cin >> t;
            if (t == 1000.0)
                break;

            day_records->push_back(t);
        }

        std::cout << "Enter another day's temperatures (Y or N)? ";
        char answer {};
        std::cin >> answer;
        if (std::toupper(answer) != 'Y')
            break;
    }

    day = 1;

    std::cout << std::fixed << std::setprecision(2) << std::endl;
    for (auto record : records)
    {
        double total {};
        std::size_t count {};

        std::cout << "\nTemperatures for day " << day++ << ":\n";
        for (auto temp : *record)
        {
            total += temp;
            std::cout << std::setw(6) << temp;
            if (++count % 5 == 0)
                std::cout << std::endl;
        }

        std::cout << "\nAverage temperature: " << total / count << std::endl;
    }
}
