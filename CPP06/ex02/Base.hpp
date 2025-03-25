#ifndef BASE_HPP
#define BASE_HPP

#include <string>

class Base {
public:
    virtual ~Base() {}
    virtual std::string getType() const = 0;
};

#endif