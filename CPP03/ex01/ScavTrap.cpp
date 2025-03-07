#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name) : ClapTrap(name), hp(100),ep(50),a_dmg(20)
{
    std::cout << "ScavTrap spawned!\n" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &copy) : ClapTrap(copy), name(copy.name), hp(copy.hp), ep(copy.ep), a_dmg(copy.a_dmg)
{
    std::cout << "copy ScavTrap spawned\n" << std::endl;
    *this = copy;
}

ScavTrap &ScavTrap::operator=(const ScavTrap& copy)
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

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap gone\n" << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
    if(this->ep > 0 && this->hp > 0)
    {
        this->ep -= 1;
        std::cout << this->name << " insane dmg with " << a_dmg << " to " << target << std::endl;
    }
    else if(hp <= 0)
        std::cout << this->name << " broken frfr D: " << std::endl;
    else
        std::cout << this->name << " not have stamina((((( " << std::endl;
}

void ScavTrap::guardGate()
{
    std::cout << "im guard now!\n" <<std::endl;
}