#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name) : ClapTrap(name), hp(100),ep(100),a_dmg(30)
{
    std::cout << "fragtrap spawned!\n" << std::endl;
}

FragTrap::FragTrap(const FragTrap &copy) : ClapTrap(copy), name(copy.name), hp(copy.hp), ep(copy.ep), a_dmg(copy.a_dmg)
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