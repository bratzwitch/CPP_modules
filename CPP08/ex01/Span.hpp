#ifndef SPAN_HPP
#define SPAN_HPP

#include <queue>
#include <iostream>
#include <cstdlib>
#include <algorithm>

class Span
{
    private:
        std::vector<int> arr;
        unsigned int N;
        std::deque<int> myqueue;
    public:
        Span();
        Span(unsigned int N);
        Span(const Span& copy);
        Span& operator=(const Span& copy);
        ~Span();
    void addNumber(int num);
    int operator[](size_t index) const;
    void fillNum(unsigned int amount);
    int shortestSpan();
    int longestSpan();
};


#endif