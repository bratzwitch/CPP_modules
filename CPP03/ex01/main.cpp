#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
    ScavTrap ScavTrap("Scavvy ");
    ScavTrap.guardGate();
    ScavTrap.attack("air ");
    ScavTrap.beRepaired(1);
    ScavTrap.takeDamage(2);
    ScavTrap.beRepaired(1);
    ScavTrap.attack("air ");
    ScavTrap.attack("air ");
    ClapTrap ClapTrap("Clappy ");
    ClapTrap.attack("wall ");
    ClapTrap.takeDamage(5);
    ClapTrap.beRepaired(4);
    return 0;
}