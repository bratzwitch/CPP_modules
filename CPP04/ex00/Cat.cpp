#include "Cat.hpp"

Cat::Cat() : Animal()
{
    this->type = "Cat";
    std::cout << "Cat arrived" << std::endl;
}

Cat::Cat(const Cat &copy) : Animal(copy)
{
    std::cout << "Copy Cat arrived" << std::endl;
    *this = copy;
}

Cat& Cat::operator=(const Cat& copy)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &copy)
        this->type = copy.type;
    return *this;
}

Cat::~Cat()
{
    std::cout << "Cat gone" << std::endl;
}

void Cat::makeSound() const
{
    std::cout << "MEOW MEOW" << std::endl;
}