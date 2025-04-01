#include "Span.hpp"

int main()
{
    Span span = Span(5);
    span.addNumber(1);
    span.addNumber(15);
    span.addNumber(50);
    span.addNumber(4);
    std::cout << span[0] << std::endl;
    std::cout << span[1] << std::endl;
    std::cout << span[2] << std::endl;
    std::cout << span[3] << std::endl;
    std::cout << span[4] << std::endl;
    return 0;
}