#include "Harl.hpp"

int Harl::getLevel(std::string level)
{
    std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};

    for (int i = 0; i < 4; i++)
    {
        if (level == levels[i])
            return i;
    }
    return -1;
}

int main(int argc, char *argv[])
{
    Harl harl;
    std::string trigger = argv[1];
    int level = harl.getLevel(argv[1]);
    // int i = 0;
    if(argc == 2)
    {
        // while(level >= i)
        // {
            switch(level)
        {
            case 0:
                harl.complain("DEBUG");
                //fallthrough
            case 1:
                harl.complain("INFO");
                //fallthrough
            case 2:
                harl.complain("WARNING");
                //fallthrough
            case 3:
                harl.complain("ERROR");
                break;
            default:
                std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
        }
        // level--;
        // }
    }
    else 
        std::cout << "I need something to complain" << std::endl;
    return 0;
}