#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"
#include <iostream>


class FragTrap : public ClapTrap
{
    public:
        FragTrap();
        FragTrap(std::string name);
        FragTrap(const FragTrap &copy);
        ~FragTrap();
        FragTrap& operator=(const FragTrap& copy);
        void highFivesGuys(void);
};

#endif