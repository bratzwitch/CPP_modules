#include "gen.hpp"
#include "identify.hpp"
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>

int main() {

    Base* a = new A();
    Base* b = new B();
    Base* c = new C();
    std::cout << "\nusual\n" << std::endl;
    identify(a);
    identify(b);
    identify(c);
    std::cout << "\nref\n" << std::endl;
    identify(*a);
    identify(*b);
    identify(*c);
    delete a;
    delete b;
    delete c;
    std::cout << "\ngenerate(de)\n" << std::endl;
    Base* obj = generate();
    Base* obj2 = generate();
    Base* obj3 = generate();
    Base* obj4 = generate();
    identify(obj);
    identify(*obj);
    identify(obj2);
    identify(*obj2);
    identify(obj3);
    identify(*obj3);
    identify(obj4);
    identify(*obj4);
    delete obj;
    delete obj2;
    delete obj3;
    delete obj4;

    return 0;
}