#include "Span.hpp"


Span::Span() : N(100) {
    arr.reserve(N);
}

Span::Span(unsigned int N) : N(N){
    arr.reserve(N);
}

Span::~Span() {}

Span& Span::operator=(const Span &copy)
{
    if(this != &copy)
    {
        N = copy.N;
        for(unsigned int i = 0;i < N;i++)
            arr[i] = copy.arr[i];
    }
    return *this;
}

Span::Span(const Span& copy)
{
    if(N > 0)
    {
        for(unsigned int i = 0;i < N;i++)
            arr[N] = copy.arr[N];
    }
}

void Span::addNumber(int num) {
    if (arr.size() >= N) {
        std::cout << "array full" << std::endl;
        return;
    }
    arr.push_back(num);
}

int Span::operator[](size_t index) const {
    if (index >= arr.size()) {
        throw std::out_of_range("run!!");
    }
    return arr[index];
}