#include "Bureaucrat.hpp"

int main()
{
    try
    {
        Bureaucrat bro("bro", 2);
        std::cout << bro << std::endl;
        bro.incrementGrade();
        std::cout << bro << std::endl;
        bro.incrementGrade();
        std::cout << bro << std::endl;
        bro.decrementGrade();
        std::cout << bro << std::endl;
        // for(int i = 0; i < 150; i++)
        // {
        //     bro.decrementGrade();
        //     std::cout << bro << std::endl;
        // }
        std::cout << bro << std::endl;

    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    
}