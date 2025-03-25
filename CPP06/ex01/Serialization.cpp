#include "Serialization.hpp"

Serialization::Serialization() {}

Serialization::Serialization(const Serialization& ) {}

Serialization& Serialization::operator=(const Serialization& ) {
    return *this;
}

Serialization::~Serialization() {}

size_t Serialization::serialize(Data* ptr) {
    return reinterpret_cast<size_t>(ptr);
}

Data* Serialization::deserialize(size_t raw) {
    return reinterpret_cast<Data*>(raw);
}

