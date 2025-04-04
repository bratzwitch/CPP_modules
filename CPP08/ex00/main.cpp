#include "easyfind.hpp"
#include <list>

int main()
{
    std::list<int> L;
    for(int i = 0; i < 10;i++)
        L.push_back(i);
    int i = 5;
    int res = ::easyfind(L,i);
    if(res == -1)
        std::cout << i << " not found" << std::endl;
    else
        std::cout << i << " found at " << res << " pos" << std::endl;
    return 0;
}