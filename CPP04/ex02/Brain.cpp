#include "Brain.hpp"

Brain::Brain()
{
    std::cout << "Brain arrived" << std::endl;
}

Brain::Brain(const Brain &copy)
{
    std::cout << "Copy Brain arrived" << std::endl;
    *this = copy;
}

Brain& Brain::operator=(const Brain& copy)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &copy)
    {
        for(int i = 0;i < 100;i++)
            this->ideas[i] = copy.ideas[i];
    }
    return *this;
}

void Brain::createIdea(int i,const std::string &idea)
{
    if(i >= 0 && i < 100)
        ideas[i] = idea;
}
std::string Brain::getIdea(int i) const
{
    if(i >= 0 && i < 100)
        return ideas[i];
    else
        return "wind in brain";
}

Brain::~Brain()
{
    std::cout << "Brain gone" << std::endl;
}