#include "Harl.hpp"

void Harl::debug( void )
{
    std::cout << "[ DEBUG ]" << std::endl;
    std::cout << "Debug stuff! LESSSGO" << std::endl;
}

void Harl::info( void )
{
    std::cout << "[ INFO ]" << std::endl;
    std::cout << "Info stuff! LESSSGO" << std::endl;
}

void Harl::warning( void )
{
    std::cout << "[ WARNING ]" << std::endl;
    std::cout << "WARNING! Imagine" << std::endl;
}

void Harl::error( void )
{
    std::cout << "[ ERROR ]" << std::endl;
    std::cout << "ERROR! HELL NAH" << std::endl;
}

int Harl::complain( std::string level )
{
    void (Harl::*ptr[4])(void) = {&Harl::debug,&Harl::info,&Harl::warning,&Harl::error};
    std::string	trigger[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    for(int i = 0; i < 4; i++)
    {
        while(trigger[i] == level)
        {
            (this->*ptr[i])();
            return i;
        }
    }
    return -1;
}