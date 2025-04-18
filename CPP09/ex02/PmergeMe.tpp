#ifndef PMERGEME_TPP
#define PMERGEME_TPP

#include "PmergeMe.hpp"
#include <cmath>
#include <algorithm>

template <typename Container>
PmergeMe<Container>::PmergeMe() {}

template <typename Container>
PmergeMe<Container>::~PmergeMe() {}

template <typename Container>
PmergeMe<Container>::PmergeMe(const PmergeMe& copy) {
    (void)copy;
}

template <typename Container>
PmergeMe<Container>& PmergeMe<Container>::operator=(const PmergeMe& copy) {
    (void)copy;
    return *this;
}

template <typename Container>
int PmergeMe<Container>::Jacobsthal(int k) {
    // formula: J(k) = (2^(k+1) + (-1)^k) / 3.
    return round((pow(2, k + 1) + pow(-1, k)) / 3);
}

template <typename Container>
void PmergeMe<Container>::insert(Container& main_chain, Container& pending, ValueType odd_one, Container& leftovers, Container& numbers, bool has_odd, int group_size, int& steps) {
    Iterator spot;

    if (pending.size() == 1) {
        spot = std::upper_bound(main_chain.begin(), main_chain.end(), *pending.begin());
        main_chain.insert(spot, *pending.begin());
        steps++;
    } else if (pending.size() > 1) {
        size_t jacob_level = 3; // Jacobsthal 3
        size_t dance_count = 0;
        size_t batch_size;
        size_t shift;

        while (!pending.empty()) {
            batch_size = Jacobsthal(jacob_level) - Jacobsthal(jacob_level - 1);
            if (batch_size > pending.size()) {
                batch_size = pending.size();
            }
            shift = 0;
            while (batch_size) {
                // perfect spot
                spot = main_chain.begin();
                size_t target_pos = Jacobsthal(jacob_level + dance_count) - shift;
                if (target_pos <= main_chain.size()) {
                    spot = main_chain.begin() + target_pos;
                } else {
                    spot = main_chain.end();
                }
                // binary search
                spot = std::upper_bound(main_chain.begin(), spot, *(pending.begin() + batch_size - 1));
                main_chain.insert(spot, *(pending.begin() + batch_size - 1));
                pending.erase(pending.begin() + batch_size - 1);
                batch_size--;
                shift++;
                dance_count++;
            }
            jacob_level++;
        }
    }
    Container sorted_lineup;
    if (has_odd) {
        spot = std::upper_bound(main_chain.begin(), main_chain.end(), odd_one);
        main_chain.insert(spot, odd_one);
    }
    for (Iterator i = main_chain.begin(); i != main_chain.end(); ++i) {
        Iterator match = std::find(numbers.begin(), numbers.end(), *i);
        sorted_lineup.insert(sorted_lineup.end(), match - (group_size - 1), match + 1);
    }
    sorted_lineup.insert(sorted_lineup.end(), leftovers.begin(), leftovers.end());
    numbers = sorted_lineup;
}

template <typename Container>
void PmergeMe<Container>::sort(Container& numbers, int& steps) {
    static int group_size = 1;
    int total_groups = numbers.size() / group_size;

    if (total_groups < 2) {
        return;
    }

    bool has_odd = total_groups % 2 == 1;
    Iterator start = numbers.begin();
    Iterator end = numbers.begin() + ((group_size * total_groups) - (has_odd * group_size));

    // compare groups based on last num
    for (Iterator it = start; it < end; it += (group_size * 2)) {
        if (*(it + (group_size - 1)) > *(it + ((group_size * 2) - 1))) {
            for (int i = 0; i < group_size; ++i) {
                std::swap(*(it + i), *(it + i + group_size));  
            }
        }
        steps++;
        
    }
    group_size *= 2;
    sort(numbers, steps);
    group_size /= 2;

    Container main_chain; // sorted backbone.
    Container pending;
    ValueType odd_one = 0; // lone number
    Container leftovers;

    main_chain.push_back(*(start + group_size - 1));
    main_chain.push_back(*(start + group_size * 2 - 1));
    for (Iterator it = start + group_size * 2; it < end; it += group_size) {
        pending.push_back(*(it + group_size - 1));
        it += group_size;
        main_chain.push_back(*(it + group_size - 1));
    }
    if (has_odd) {
        odd_one = *(end + group_size - 1);
    }
    leftovers.insert(leftovers.end(), end + (group_size * has_odd), numbers.end());
    if (has_odd || !pending.empty()) {
        insert(main_chain, pending, odd_one, leftovers, numbers, has_odd, group_size, steps);
    }
}

#endif