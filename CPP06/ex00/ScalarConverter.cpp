#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::~ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter &){}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter&)
{
    return *this;
}

void ScalarConverter::convert(const std::string& num) {
    if (num.empty()) {
        std::cerr << "Error: Empty input" << std::endl;
        return;
    }
    if (num == "nan" || num == "nanf") {
        printResults('?', 0, NAN, NAN);
        return;
    }
    if (num == "-inf" || num == "-inff") {
        printResults('?', 0, -INFINITY, -INFINITY);
        return;
    }
    if (num == "+inf" || num == "+inff") {
        printResults('?', 0, INFINITY, INFINITY);
        return;
    }
    try {
        char* end;
        float f = strtof(num.c_str(), &end);
        if (*end == '\0')
            printResults(static_cast<char>(f), static_cast<int>(f), f, static_cast<double>(f));
        return;
    } catch (...) {}
    
    try {
        char* end;
        double d = strtod(num.c_str(), &end);
        if (*end == '\0')
            printResults(static_cast<char>(d), static_cast<int>(d), static_cast<float>(d), d);
        return;
    } catch (...) {}

    try {
        char* end;
        long temp = strtol(num.c_str(), &end, 1);
        if (*end == '\0' && temp >= INT_MIN && temp <= INT_MAX) {
            int i = static_cast<int>(temp);
            printResults(static_cast<char>(i), i, static_cast<float>(i), static_cast<double>(i));
            return;
        }
        return;
    } catch (...) {}

    std::cerr << "no good" << std::endl;
}

void ScalarConverter::printResults(char c, int i, float f, double d) {
    if (std::isprint(c))
        std::cout << "char: '" << c << "'" << std::endl;
    else
        std::cout << "char: nah bro i cant" << std::endl;
    
    std::cout << "int: " << i << std::endl;
    std::cout << "float: " << f << "f" << std::endl;
    std::cout << "double: " << d << std::endl;
}