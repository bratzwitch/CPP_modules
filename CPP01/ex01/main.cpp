#include "Zombie.hpp"

int main()
{
    int N = 15;
    Zombie* horde = zombieHorde(N,"a");
    for(int i = 0;i < N;i++)
        horde[i].announce();
    delete [] horde;
    return 0;
}