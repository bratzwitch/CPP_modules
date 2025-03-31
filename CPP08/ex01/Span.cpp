#include "Span.hpp"


Span::Span() : N(100) {
    *arr = arr[100];
}

Span::Span(unsigned int N) : N(N){
    *arr = arr[N];
}

Span::~Span() {}

Span& Span::operator=(const Span &copy)
{
    if(this != &copy)
    {
        N = copy.N;
        for(int i = 0;i < N;i++)
            arr[i] = copy.arr[i];
    }
    return *this;
}

Span::Span(const Span& copy)
{
    if(N > 0)
    {
        for(int i = 0;i < N;i++)
            arr[N] = copy.arr[N];
    }
}

void Span::addNumber(int num)
{
    int i = 0;
    while(i < N)
    {
        if(num != arr[i] && arr[i] == '\0')
            arr[i] = num;
    }
}