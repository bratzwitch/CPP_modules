#ifndef SERIALIZATION_HPP
#define SERIALIZATION_HPP

#include <cstddef>

struct Data;

class Serialization {
private:
    Serialization();
    Serialization(const Serialization& );
    Serialization& operator=(const Serialization& );
    ~Serialization();
public:
    static size_t serialize(Data* ptr);
    static Data* deserialize(size_t raw);
};

#endif