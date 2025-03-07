#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include <iostream>
#include "ClapTrap.hpp"


class ScavTrap : public ClapTrap
{
    private:
        std::string name;
        int hp;
        int ep;
        int a_dmg;
    public:
        ScavTrap(std::string name);
        ScavTrap(const ScavTrap &copy);
        ~ScavTrap();
        ScavTrap& operator=(const ScavTrap& copy);
        void attack(const std::string& target);
        void guardGate();
};

#endif