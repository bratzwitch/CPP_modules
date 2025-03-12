#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal()
{
    this->type = "WrongCat";
    std::cout << "WrongCat arrived" << std::endl;
}

WrongCat::WrongCat(const WrongCat &copy) : WrongAnimal(copy)
{
    std::cout << "Copy WrongCat arrived" << std::endl;
    *this = copy;
}

WrongCat& WrongCat::operator=(const WrongCat& copy)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &copy)
        this->type = copy.type;
    return *this;
}

WrongCat::~WrongCat()
{
    std::cout << "WrongCat gone" << std::endl;
}

void WrongCat::makeSound() const
{
    std::cout << "Hello im behind you" << std::endl;
}