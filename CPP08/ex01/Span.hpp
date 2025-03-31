#ifndef SPAN_HPP
#define SPAN_HPP

class Span
{
    private:
        int *arr;
        unsigned int N;
    public:
        Span();
        Span(unsigned int N);
        Span(const Span& copy);
        Span& operator=(const Span& copy);
        ~Span();
    void addNumber(int num);
    void fillNum(int start, int end);
    int shortestSpan();
    int longestSpan();
};


#endif