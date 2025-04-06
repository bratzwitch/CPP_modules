#include "RPN.hpp"


RPN::RPN() {}

RPN::~RPN() {}

RPN::RPN(const RPN& other) : stack(other.stack) {}

RPN& RPN::operator=(const RPN& other) {
    if (this != &other) {
        stack = other.stack;
    }
    return *this;
}

bool RPN::isOperator(char c) const {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

int RPN::performOperation(int a, int b, char op) const {
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/':
            if (b == 0) {
                throw std::runtime_error("division by zero");
            }
            return a / b;
        default:
            throw std::runtime_error("invalid operator");
    }
}

int RPN::calculate(const std::string& expression) {
    std::stringstream ss(expression);
    std::string token;

    while (ss >> token) {
        if (token.length() == 1 && isOperator(token[0])) {
            if (stack.size() < 2) {
                throw std::runtime_error("Invalid expression: too few operands");
            }
            int b = stack.top(); stack.pop();
            int a = stack.top(); stack.pop();
            int result = performOperation(a, b, token[0]);
            stack.push(result);
        } else if (token.length() == 1 && token[0] >= '0' && token[0] <= '9') {
            stack.push(token[0] - '0');
        } else {
            throw std::runtime_error("Invalid token in expression");
        }
    }

    if (stack.size() != 1) {
        throw std::runtime_error("Invalid expression: too many operands");
    }

    return stack.top();
}

