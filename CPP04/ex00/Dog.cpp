#include "Dog.hpp"

Dog::Dog() : Animal()
{
    this->type = "Dog";
    std::cout << "Dog arrived" << std::endl;
}

Dog::Dog(const Dog &copy) : Animal(copy)
{
    std::cout << "Copy Dog arrived" << std::endl;
    *this = copy;
}

Dog& Dog::operator=(const Dog& copy)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &copy)
        this->type = copy.type;
    return *this;
}

Dog::~Dog()
{
    std::cout << "Dog gone" << std::endl;
}

void Dog::makeSound() const
{
    std::cout << "BARK BARK" << std::endl;
}