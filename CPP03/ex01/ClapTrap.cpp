#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name) :name(name),hp(10),ep(10),a_dmg(9)
{
    std::cout << "claptrap spawned!" << std::endl;
    
}

ClapTrap::ClapTrap(const ClapTrap &copy)
{
    std::cout << "copy claptrap spawned" << std::endl;
    *this = copy;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& copy)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &copy)
    {
        this->name = copy.name;
        this->hp = copy.hp;
        this->ep = copy.ep;
        this->a_dmg = copy.a_dmg;
    }
    return *this;
}

ClapTrap::~ClapTrap()
{
    std::cout << "claptrap gone" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if(this->hp > 0)
    {
        std::cout << this->name << " received " << amount << " damage " << std::endl;
        if((this->hp -= amount) <= 0)
            std::cout << this->name << " rip " << std::endl;
    }
    else
        std::cout << this->name << " already dead, stop punching this corpse " << std::endl;
    
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if(this->hp < 10 && this->hp > 0 && this->ep > 0)
    {
        this->ep -= 1;
        std::cout << this->name << " hp before repair is " << this->hp << std::endl;
        if((this->hp += amount) > 10)
            this->hp = 10;
        std::cout << this->name << " hp after repair is " << this->hp << std::endl;
    }
    else if(this->ep <= 0)
        std::cout << this->name << " not have stamina, sadge " << std::endl;    
    else
        std::cout << this->name << " already fully repaired " << std::endl; 
    
}

void ClapTrap::attack(const std::string& target)
{
    if(this->ep > 0 && this->hp > 0)
    {
        this->ep -= 1;
        std::cout << this->name << " dmg with " << a_dmg << " to " << target << std::endl;
    }
    else if(hp <= 0)
        std::cout << this->name << " broken D: " << std::endl;
    else
        std::cout << this->name << " not have stamina, sadge " << std::endl;
}
