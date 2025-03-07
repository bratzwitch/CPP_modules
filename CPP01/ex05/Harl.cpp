#include "Harl.hpp"

void Harl::debug( void )
{
    std::cout << "Debug stuff! LESSSGO" << std::endl;
}

void Harl::info( void )
{
    std::cout << "Info stuff! LESSSGO" << std::endl;
}

void Harl::warning( void )
{
    std::cout << "WARNING! Imagine" << std::endl;
}

void Harl::error( void )
{
    std::cout << "ERROR! HELL NAH" << std::endl;
}

void Harl::complain( std::string level )
{
    void (Harl::*ptr[4])(void) = {&Harl::debug,&Harl::info,&Harl::warning,&Harl::error};
    std::string	trigger[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    for(int i = 0; i < 4; i++)
    {
        while(trigger[i] == level)
        {
            (this->*ptr[i])();
            break;
        }
    }
}