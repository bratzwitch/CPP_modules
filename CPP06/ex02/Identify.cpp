#include "Identify.hpp"
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>

void identify(Base* p) {
    if (p != NULL) {
        std::cout << p->getType() << std::endl;
    } else {
        std::cout << "NULL" << std::endl;
    }
}

void identify(Base& p) {
    try{
        if(dynamic_cast<A*>(&p))
        {
            std::cout << "A" << std::endl; 
            return;
        }
    }
    catch(...) {}
    try{
        if(dynamic_cast<B*>(&p))
        {
            std::cout << "B" << std::endl; 
            return;
        }
    }
    catch(...) {}
    try{
        if(dynamic_cast<C*>(&p))
        {
            std::cout << "C" << std::endl; 
            return;
        }
    }
    catch(...){}
}