#ifndef SERIALIZATION_HPP
#define SERIALIZATION_HPP

#include <cstddef>
#include <iostream>
#include <stdint.h>

struct Data;

class Serialization {
private:
    Serialization();
    Serialization(const Serialization& );
    Serialization& operator=(const Serialization& );
    ~Serialization();
public:
    static uintptr_t serialize(Data* ptr);
    static Data* deserialize(uintptr_t raw);
};

#endif