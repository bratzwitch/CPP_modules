#include "Dog.hpp"

Dog::Dog() : Animal()
{
    this->type = "Dog";
    std::cout << "Dog arrived" << std::endl;
    this->brain = new Brain();
}

Dog::Dog(const Dog& copy) : Animal(copy)
{
    type = copy.type;
    brain = new Brain(*copy.brain);
    std::cout << "Copy Cat arrived" << std::endl;
}

Dog& Dog::operator=(const Dog& copy)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &copy)
    {
        delete brain;
        brain = new Brain(*copy.brain);
        type = copy.type;
    }
    return *this;
}

Dog::~Dog()
{
    delete brain;
    std::cout << "Dog gone" << std::endl;
}

void Dog::createIdea(int i,const std::string &idea)
{
    if(i >= 0 && i < 100)
        brain->createIdea(i,idea);
}

std::string Dog::getIdea(int i) const
{
    if(i >= 0 && i < 100)
        return brain->getIdea(i);
    else
        return "wind in mind ";
}

void Dog::makeSound() const
{
    std::cout << "BARK BARK" << std::endl;
}