#include "Animal.hpp"

Animal::Animal() : type("Animal")
{
    std::cout << "Animal arrived" << std::endl;
}

Animal::Animal(const Animal &copy)
{
    std::cout << "Copy animal arrived" << std::endl;
    *this = copy;
}

Animal& Animal::operator=(const Animal& copy)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &copy)
        this->type = copy.type;
    return *this;
}

Animal::~Animal()
{
    std::cout << "Animal gone" << std::endl;
}

std::string Animal::getType() const
{
    return type;
}

void Animal::makeSound() const
{
    std::cout << "RADIO SILENCE" << std::endl;
}