#include "ClapTrap.hpp"

int main()
{
    // ClapTrap ClapTrap;
    ClapTrap ClapTrap("bro");
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