#include "Serialization.hpp"
#include "Data.hpp"


int main() {
    Data data;
    data.member = 42;

    uintptr_t serialized = Serialization::serialize(&data);
    Data* deserialized = Serialization::deserialize(serialized);

    if (deserialized == &data) {
        std::cout << "good" << std::endl;
    } else {
        std::cout << "no good" << std::endl;
    }

    return 0;
}