#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("WrongAnimal")
{
    std::cout << "WrongAnimal arrived" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &copy)
{
    std::cout << "Copy WrongAnimal arrived" << std::endl;
    *this = copy;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& copy)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &copy)
        this->type = copy.type;
    return *this;
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "WrongAnimal gone" << std::endl;
}

std::string WrongAnimal::getType() const
{
    return type;
}

void WrongAnimal::makeSound() const
{
        std::cout << "SILENCE BEHIND YOU" << std::endl;
}