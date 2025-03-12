#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
    this->name = "random fragtrap";
    this->hp = 100;
    this->ep = 100;
    this->a_dmg = 30;
    std::cout << "random fragtrap spawned!" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
    this->hp = 100;
    this->ep = 100;
    this->a_dmg = 30;
    std::cout << "fragtrap spawned!\n" << std::endl;
}

FragTrap::FragTrap(const FragTrap &copy) : ClapTrap(copy)
{
    std::cout << "copy FragTrap spawned\n" << std::endl;
    *this = copy;
}

FragTrap &FragTrap::operator=(const FragTrap& copy)
{
    std::cout << "Copy assignment operator called\n" << std::endl;
    if (this != &copy)
    {
        this->name = copy.name;
        this->hp = copy.hp;
        this->ep = copy.ep;
        this->a_dmg = copy.a_dmg;
    }
    return *this;
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap gone\n" << std::endl;
}

void FragTrap::highFivesGuys(void)
{
    std::cout << "HIGH FIVE!!!!" << std::endl;
}