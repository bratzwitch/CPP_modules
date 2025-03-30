#ifndef ARRAY_TPP
#define ARRAY_TPP

#include <cstddef>

template <typename T>
Array<T>::Array() : data(NULL), len(0) {}

template <typename T>
Array<T>::Array(unsigned int n) : data(new T[n]), len(n) {}

template <typename T>
Array<T>::Array(const Array& copy) : data(NULL), len(copy.len) {
    if (len > 0) {
        data = new T[len];
        for (unsigned int i = 0; i < len; i++) {
            data[i] = copy.data[i];
        }
    }
}

template <typename T>
Array<T>& Array<T>::operator=(const Array& copy) {
    if (this != &copy) {
        delete[] data;
        len = copy.len;
        data = (len > 0) ? new T[len] : NULL;
        for (unsigned int i = 0; i < len; i++) {
            data[i] = copy.data[i];
        }
    }
    return *this;
}

template <typename T>
Array<T>::~Array() {
    delete[] data;
}

template <typename T>
T& Array<T>::operator[](unsigned int index) {
    if (index >= len) {
        throw std::exception();
    }
    return data[index];
}

template <typename T>
const T& Array<T>::operator[](unsigned int index) const {
    if (index >= len) {
        throw std::exception();
    }
    return data[index];
}

template <typename T>
unsigned int Array<T>::size() const {
    return len;
}

#endif