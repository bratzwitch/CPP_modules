#include "Gen.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>
#include <ctime>

Base* generate() {
    static bool trigger = false;
    if (!trigger) {
        srand(static_cast<unsigned int>(time(NULL)));
        trigger = true;
    }
    int choice = rand() % 3;
    if (choice == 0) {
        return new A();
    } else if (choice == 1) {
        return new B();
    } else {
        return new C();
    }
}