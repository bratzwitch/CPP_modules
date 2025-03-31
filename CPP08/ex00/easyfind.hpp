#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <algorithm>


template <typename T, int N> 
int easyfind(T(&arr)[N], int i)
{
    T* it = std::find(arr, arr + N, i);
    if (it != arr + N)
        return std::distance(arr, it);
    return -1;
}

#endif