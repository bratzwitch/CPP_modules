#include "identify.hpp"
#include "Base.hpp"
#include <iostream>

void identify(Base* p) {
    if (p != NULL) {
        std::cout << p->getType() << std::endl;
    } else {
        std::cout << "NULL" << std::endl;
    }
}

void identify(Base& p) {
    std::cout << p.getType() << std::endl;
}