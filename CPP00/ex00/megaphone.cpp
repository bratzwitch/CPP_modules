#include <iostream>
#include <string.h>

void toUpper(char *c)
{
    while (*c)
    {
        *c = std::toupper(*c);
        c++;
    }
}

int main(int argc, char **argv)
{
    if(argc > 1)
    {
        int i = 1;
        while(i < argc)
        {
            toUpper(argv[i]);
            std::cout << argv[i];
            i++;
        }
        std::cout << std::endl;
    }
    else
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    return 0;
}