#ifndef ITER_HPP
#define ITER_HPP

template <typename T> void iter(T* array, unsigned int length,void (*f)(const T&))
{
    for (unsigned int i = 0; i < length; i++) {
        f(array[i]);
    }
}
template <typename T> void iter(T* array, unsigned int length,void (*f)(T&))
{
    for (unsigned int i = 0; i < length; i++) {
        f(array[i]);
    }
}

#endif