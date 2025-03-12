#include "Animal.hpp"

Animal::Animal() : type("Animal")
{
    std::cout << "Animal arrived" << std::endl;
}

Animal::Animal(const Animal &copy) : type(copy.type)
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
    if(type == "Dog")
        std::cout << "BARK BARK" << std::endl;
    else if(type == "Cat")
        std::cout << "Meow Meow" << std::endl;
    else
        std::cout << "RADIO SILENCE" << std::endl;
}
