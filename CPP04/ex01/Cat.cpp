#include "Cat.hpp"

Cat::Cat() : Animal()
{
    type = "Cat";
    std::cout << "Cat arrived" << std::endl;
    brain = new Brain();
}

Cat::Cat(const Cat &copy) : Animal(copy)
{
    type = copy.type;
    brain = new Brain(*copy.brain);
    std::cout << "Copy Cat arrived" << std::endl;
}

Cat& Cat::operator=(const Cat& copy)
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

Cat::~Cat()
{
    delete brain;
    std::cout << "Cat gone" << std::endl;
}

void Cat::createIdea(int i,const std::string &idea)
{
    if(i >= 0 && i < 100)
        brain->createIdea(i,idea);       
}

std::string Cat::getIdea(int i) const
{
    if(i >= 0 && i < 100)
        return brain->getIdea(i);
    else
        return "wind in mind";
}