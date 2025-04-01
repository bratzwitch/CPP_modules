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
    if (this != &copy) {
        arr.clear();
        N = copy.N;
        arr.reserve(N);
        for (unsigned int i = 0; i < copy.arr.size(); i++) {
            arr.push_back(copy.arr[i]);
        }
    }
    return *this;
}

Span::Span(const Span& copy) : N(copy.N)
{
    arr.reserve(N);
    for (unsigned int i = 0; i < copy.arr.size(); i++) {
        arr.push_back(copy.arr[i]);
    }
}

void Span::addNumber(int num) {
    if (arr.size() >= N) {
        std::cout << "array full" << std::endl;
        return;
    }
    arr.push_back(num);
}

int Span::shortestSpan() {
    if (arr.size() < 2) {
        throw std::invalid_argument("no span found, need at least 2 numbers");
    }
    std::vector<int> sorted = arr;
    std::sort(sorted.begin(), sorted.end());
    int min = sorted[1] - sorted[0];
    for (unsigned int i = 1; i < sorted.size() - 1; i++)
    {
        int diff = sorted[i + 1] - sorted[i];
        if (diff < min)
            min = diff;
    }
    return min;
}

int Span::longestSpan() {
    if (arr.size() < 2) {
        throw std::invalid_argument("no span found, need at least 2 numbers");
    }
    int min = arr[0];
    int max = arr[0];
    for (unsigned int i = 1; i < arr.size(); i++) {
        if (arr[i] < min)
            min = arr[i];
        if (arr[i] > max)
            max = arr[i];
    }
    return max - min;
}

int Span::operator[](size_t index) const {
    if (index >= arr.size()) {
        throw std::out_of_range("run!!");
        return -1;
    }
    return arr[index];
}

void Span::fillNum(unsigned int amount)
{
    for(unsigned int i = 0; i < amount;i++)
    {
        if(amount > N)
            throw std::out_of_range("too much numbers to fill. bye");
        if (arr.size() >= N) {
            std::cout << "array full" << std::endl;
            return;
        }
        int num = rand();
        arr.push_back(num);
    }   
}