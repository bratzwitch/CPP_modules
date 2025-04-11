#ifndef PMERGEME_TPP
#define PMERGEME_TPP

#include "PmergeMe.hpp"

template <typename Container>
PmergeMe<Container>::PmergeMe() {}

template <typename Container>
PmergeMe<Container>::~PmergeMe() {}

template <typename Container>
PmergeMe<Container>::PmergeMe(const PmergeMe& other) {
    (void)other;
}

template <typename Container>
PmergeMe<Container>& PmergeMe<Container>::operator=(const PmergeMe& other) {
    (void)other;
    return *this;
}

template <typename Container>
int PmergeMe<Container>::Jacobsthal(int num) {
    // Computes the k-th Jacobsthal number using the formula: J(k) = (2^(k+1) + (-1)^k) / 3.
    return round((pow(2, num + 1) + pow(-1, num)) / 3);
}

template <typename Container>
void PmergeMe<Container>::insert(Container &main, Container &pend, ValueType odd, Container &left, Container &vec, bool is_odd, int order) {
    Iterator end;

    if (pend.size() == 1) {
        end = std::upper_bound(main.begin(), main.end(), *pend.begin());
        main.insert(end, *pend.begin());
    } else if (pend.size() > 1) {
        size_t jc = 3;
        size_t count = 0;
        size_t idx;
        size_t decrease;
        
        while (!pend.empty()) {
            idx = Jacobsthal(jc) - Jacobsthal(jc - 1);
            if (idx > pend.size())
                idx = pend.size();

            decrease = 0;
            while (idx) {
                end = main.begin();
                if (Jacobsthal(jc + count) - decrease <= main.size())
                    end = main.begin() + Jacobsthal(jc + count) - decrease;
                else
                    end = main.end();
                end = std::upper_bound(main.begin(), end, *(pend.begin() + idx - 1));
                main.insert(end, *(pend.begin() + idx - 1));
                pend.erase(pend.begin() + idx - 1);

                idx--;
                decrease++;
                count++;
            }
            jc++;
        }
    }

    Container bin;
    
    if (is_odd) {
        end = std::upper_bound(main.begin(), main.end(), odd);
        main.insert(end, odd);
    }
    for (Iterator i = main.begin(); i != main.end(); i++) {
        Iterator it = std::find(vec.begin(), vec.end(), *i);
        bin.insert(bin.end(), it - (order - 1), it + 1);
    }
    bin.insert(bin.end(), left.begin(), left.end());
    vec = bin;
}

template <typename Container>
void PmergeMe<Container>::sort(Container &vec) {
    static int order = 1;

    int unit_size = vec.size() / order;
    if (unit_size < 2)
        return;

    bool is_odd = unit_size % 2 == 1;
    Iterator start = vec.begin();
    Iterator end = vec.begin() + ((order * unit_size) - (is_odd * order));

    for (Iterator it = start; it < end; it += (order * 2)) {
        if (*(it + (order - 1)) > *(it + ((order * 2) - 1))) {
            for (int i = 0; i < order; i++) {
                std::swap(*(it + i), *(it + i + order));
            }
        }
    }

    order *= 2
    sort(vec);
    order /= 2;

    Container main;
    Container pend;
    ValueType odd = 0;
    Container left;


    main.push_back(*(start + order - 1)); 
    main.push_back(*(start + order * 2 - 1));

    for (Iterator it = start + order * 2; it < end; it += order) {
        pend.push_back(*(it + order - 1));
        it += order;
        main.push_back(*(it + order - 1));
    }

    if (is_odd)
        odd = *(end + order - 1);

    left.insert(left.end(), end + (order * is_odd), vec.end());

    if (is_odd || !pend.empty())
        insert(main, pend, odd, left, vec, is_odd, order);
}

#endif