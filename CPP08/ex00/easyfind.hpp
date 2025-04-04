#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <algorithm>


template <typename T> 
int easyfind(T t, int i)
{
    typename T::iterator it = std::find(t.begin(), t.end(), i);
    if (it != t.end())
        return std::distance(t.begin(), it);
    return -1;
}

#endif