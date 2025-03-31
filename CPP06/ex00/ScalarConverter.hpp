#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <climits>
#include <cmath>

class ScalarConverter {
private:
    ScalarConverter();
    ~ScalarConverter();
    ScalarConverter(const ScalarConverter&);

public:
    ScalarConverter& operator=(const ScalarConverter&);
    static void convert(const std::string& literal);

private:
    static void printResults(char c, int i, float f, double d);
};

#endif