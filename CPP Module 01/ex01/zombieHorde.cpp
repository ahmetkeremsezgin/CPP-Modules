#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
    int i = 0;
    Zombie* zombies = new Zombie[N](name);
    while (i < N)
    {
        zombies[i] = Zombie(name);
        i++;
    }
    return (zombies);
}