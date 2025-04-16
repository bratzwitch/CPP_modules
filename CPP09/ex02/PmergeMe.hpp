#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <ctime>
#include <vector>
#include <deque>
#include <cstdlib>
#include <cmath>
#include <algorithm>

template <typename Container>
class PmergeMe {
    private:
        int Jacobsthal(int num);
    public:
        PmergeMe();
        ~PmergeMe();
        PmergeMe(const PmergeMe& copy);
        PmergeMe& operator=(const PmergeMe& copy);

    typedef typename Container::value_type ValueType;
    typedef typename Container::iterator Iterator;
    void sort(Container& vec, int& steps);
    void process(const std::string& input, Container& result, double& time);
    void insert(Container& main, Container& pend, ValueType odd, Container& left, Container& vec, bool is_odd, int order);
};

#include "PmergeMe.tpp"

#endif