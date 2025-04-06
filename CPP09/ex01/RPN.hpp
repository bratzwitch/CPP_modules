#ifndef RPN_HPP
#define RPN_HPP

#include <stack>
#include <iostream>
#include <iostream>
#include <sstream>

class RPN {
public:
    RPN();
    ~RPN();
    RPN(const RPN& other);
    RPN& operator=(const RPN& other);

    int calculate(const std::string& expression);

private:
    std::stack<int> stack;

    bool isOperator(char c) const;
    int performOperation(int a, int b, char op) const;
};

#endif