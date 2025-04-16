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
void PmergeMe<Container>::insert(Container& main_chain, Container& pending, ValueType odd_one, Container& leftovers, Container& numbers, bool has_odd, int group_size) {
    // Time to weave pending numbers into the main chain like a sorting wizard!
    Iterator spot;

    if (pending.size() == 1) {
        // Solo dancer? Find your spot with a binary search!
        spot = std::upper_bound(main_chain.begin(), main_chain.end(), *pending.begin());
        main_chain.insert(spot, *pending.begin());
    } else if (pending.size() > 1) {
        // Group dance! Use Jacobsthal numbers to pick the order.
        size_t jacob_level = 3; // Start at Jacobsthal level 3 for flair.
        size_t dance_count = 0;
        size_t batch_size;
        size_t shift;

        while (!pending.empty()) {
            // How many dancers in this batch? Jacobsthal decides!
            batch_size = Jacobsthal(jacob_level) - Jacobsthal(jacob_level - 1);
            if (batch_size > pending.size()) {
                batch_size = pending.size(); // Don't invite more than we have!
            }

            shift = 0;
            while (batch_size) {
                // Find the perfect spot for this dancer.
                spot = main_chain.begin();
                size_t target_pos = Jacobsthal(jacob_level + dance_count) - shift;
                if (target_pos <= main_chain.size()) {
                    spot = main_chain.begin() + target_pos;
                } else {
                    spot = main_chain.end(); // Join the end of the line!
                }
                // Binary search to slide in smoothly.
                spot = std::upper_bound(main_chain.begin(), spot, *(pending.begin() + batch_size - 1));
                main_chain.insert(spot, *(pending.begin() + batch_size - 1));
                pending.erase(pending.begin() + batch_size - 1);

                batch_size--;
                shift++;
                dance_count++;
            }
            jacob_level++; // Next level, more dancers!
        }
    }

    // Time to build the final sorted lineup!
    Container sorted_lineup;

    // Got an odd number out? Slip it into place!
    if (has_odd) {
        spot = std::upper_bound(main_chain.begin(), main_chain.end(), odd_one);
        main_chain.insert(spot, odd_one);
    }

    // Reconstruct the sorted sequence with a spring in our step.
    for (Iterator i = main_chain.begin(); i != main_chain.end(); ++i) {
        Iterator match = std::find(numbers.begin(), numbers.end(), *i);
        // Grab the whole group this number represents.
        sorted_lineup.insert(sorted_lineup.end(), match - (group_size - 1), match + 1);
    }
    // Don't forget the leftovers from the party!
    sorted_lineup.insert(sorted_lineup.end(), leftovers.begin(), leftovers.end());
    numbers = sorted_lineup; // Voila, new sorted list!
}

template <typename Container>
void PmergeMe<Container>::sort(Container& numbers, int& steps) {
    // Let’s throw a sorting bash! Pair up numbers and sort them step by step.
    static int group_size = 1; // Start with pairs of 1.
    int total_groups = numbers.size() / group_size;

    // If groups are too small, the party's already sorted!
    if (total_groups < 2) {
        return;
    }

    bool has_odd = total_groups % 2 == 1; // Odd number of groups? Note it!
    Iterator start = numbers.begin();
    Iterator end = numbers.begin() + ((group_size * total_groups) - (has_odd * group_size));

    // Compare pairs and swap if they're out of order, like a dance-off!
    for (Iterator it = start; it < end; it += (group_size * 2)) {
        if (*(it + (group_size - 1)) > *(it + ((group_size * 2) - 1))) {
            for (int i = 0; i < group_size; ++i) {
                std::swap(*(it + i), *(it + i + group_size));  
            }
        }
        steps++;
    }

    // Double the group size and keep sorting recursively!
    group_size *= 2;
    sort(numbers, steps);
    group_size /= 2; // Reset for the next phase.

    // Now, let’s build the main chain and handle pending dancers!
    Container main_chain; // The sorted backbone.
    Container pending;   // Numbers waiting to join.
    ValueType odd_one = 0; // The lone number, if any.
    Container leftovers; // Stragglers that didn’t pair up.

    // Seed the main chain with the first two group leaders.
    main_chain.push_back(*(start + group_size - 1));
    main_chain.push_back(*(start + group_size * 2 - 1));

    // Split the rest into main chain and pending.
    for (Iterator it = start + group_size * 2; it < end; it += group_size) {
        pending.push_back(*(it + group_size - 1));
        it += group_size;
        main_chain.push_back(*(it + group_size - 1));
    }

    // Handle the odd one out, if it exists.
    if (has_odd) {
        odd_one = *(end + group_size - 1);
    }

    // Grab any leftovers that couldn’t form a full group.
    leftovers.insert(leftovers.end(), end + (group_size * has_odd), numbers.end());

    // Time to merge everyone into the sorted lineup!
    if (has_odd || !pending.empty()) {
        insert(main_chain, pending, odd_one, leftovers, numbers, has_odd, group_size);
    }
}

#endif