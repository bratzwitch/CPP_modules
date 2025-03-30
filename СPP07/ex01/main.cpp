#include "iter.hpp"
#include <iostream>

template <typename T> void print(T& value) {
    std::cout << value << std::endl;
}

void doubleIt(int& n) {
    n *= 2;
}

int main() {
    int numbers[] = {1, 2, 3};
    iter(numbers, 3, print<int>);
    iter(numbers, 3, doubleIt);
    iter(numbers, 3, print<int>);
    char letters[] = {'a', 'b', 'c'};
    iter(letters, 3, print<char>);
    return 0;
}