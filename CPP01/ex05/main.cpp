#include "Harl.hpp"

// void complain( std::string level );

int main()
{
    Harl trig;
    std::string error1 = "ERROR";
    std::string error2 = "WARNING";
    std::string error3 = "INFO";
    std::string error4 = "DEBUG";
    trig.complain(error1);
    trig.complain(error2);
    trig.complain(error3);
    trig.complain(error4);
    return 0;
}