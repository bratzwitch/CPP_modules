#include "Zombie.hpp"

int main()
{
    Zombie* heapZombie = newZombie("Chelik");
    heapZombie->announce();
    delete heapZombie;
    randomChump("NPC");
    return 0;
}