#include "easyfind.hpp"

int main()
{
    int num[9] = {5, 11 , 3 , 7 , 9 , 15 , 18, 90 , 70};
    int i = 70;
    int res = ::easyfind(num, i);
    if(res == -1)
        std::cout << i << " not found" << std::endl;
    else
        std::cout << i << " found at " << res + 1 << " pos" << std::endl;
    return 0;
}