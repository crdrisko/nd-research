// Copyright (c) 2018 Ivor Horton and Peter Van Weert. Some rights reserved.
// Licensed under the Freeware License. See the LICENSE file in the project root for more information.
//
// Name: Ex8_13.cpp
// Author: crdrisko
// Date: 10/11/2020-08:31:14
// Description: Returning a pointer

#include <array>   // for std::size()
#include <iomanip>
#include <iostream>
#include <string_view>

void show_data(const double data[],
    std::size_t count      = 1,
    std::string_view title = "Data Values",
    std::size_t width      = 10,
    std::size_t perLine    = 5);

const double* largest(const double data[], std::size_t count);
const double* smallest(const double data[], std::size_t count);
double* shift_range(double data[], std::size_t count, double delta);
double* scale_range(double data[], std::size_t count, double divisor);
double* normalize_range(double data[], std::size_t count);

int main()
{
    double samples[] {11.0, 23.0, 13.0, 4.0, 57.0, 36.0, 317.0, 88.0, 9.0, 100.0, 121.0, 12.0};

    const std::size_t count {std::size(samples)};         // Number of samples
    show_data(samples, count, "Original Values");         // Output original values
    normalize_range(samples, count);                      // Normalize the values
    show_data(samples, count, "Normalized Values", 12);   // Output normalized values
}

// Outputs an array of double values
void show_data(const double data[], std::size_t count, std::string_view title, std::size_t width, std::size_t perLine)
{
    std::cout << title << std::endl;   // Display the title

    // Output the data values
    for (std::size_t i {}; i < count; ++i)
    {
        std::cout << std::setw(width) << data[i];   // Display a data item
        if ((i + 1) % perLine == 0)                 // Newline after perLine values
            std::cout << '\n';
    }
    std::cout << std::endl;
}

// Finds the largest of an array of double values
const double* largest(const double data[], std::size_t count)
{
    if (!count)
        return nullptr;   // There is no largest in an empty array

    std::size_t index_max {};
    for (std::size_t i {1}; i < count; ++i)
        if (data[index_max] < data[i])
            index_max = i;

    return &data[index_max];
}

// Finds the smallest of an array of double values
const double* smallest(const double data[], std::size_t count)
{
    if (!count)
        return nullptr;   // There is no largest in an empty array

    std::size_t index_min {};
    for (std::size_t i {1}; i < count; ++i)
        if (data[index_min] > data[i])
            index_min = i;

    return &data[index_min];
}

// Modify a range of value by delta
double* shift_range(double data[], std::size_t count, double delta)
{
    for (std::size_t i {}; i < count; ++i)
        data[i] += delta;
    return data;
}

// Scale an array of values by divisor
double* scale_range(double data[], std::size_t count, double divisor)
{
    if (!divisor)
        return data;   // Do nothing for a zero divisor

    for (std::size_t i {}; i < count; ++i)
        data[i] /= divisor;
    return data;
}

// Normalize an array of values to the range 0 to 1
double* normalize_range(double data[], std::size_t count)
{
    return scale_range(shift_range(data, count, -(*smallest(data, count))), count, *largest(data, count));
}
