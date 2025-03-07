#include "ClapTrap.hpp"

int main()
{
    std::string name = "bro";
    ClapTrap ClapTrap(name);
    ClapTrap.attack(" air ");
    ClapTrap.attack(" air ");
    ClapTrap.attack(" air ");
    ClapTrap.attack(" air ");
    ClapTrap.attack(" air ");
    ClapTrap.attack(" air ");
    ClapTrap.attack(" air ");
    ClapTrap.attack(" air ");
    ClapTrap.attack(" air ");
    ClapTrap.attack(" air ");
    ClapTrap.attack(" air ");
    ClapTrap.attack(" air ");
    ClapTrap.beRepaired(2);
    ClapTrap.takeDamage(5);
    ClapTrap.beRepaired(6);
    ClapTrap.takeDamage(11);
    ClapTrap.takeDamage(11);
    
    return 0;
}