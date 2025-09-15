#include <iostream>
#include "Zombie.hpp"

int main()
{
    Zombie* a = zombieHorde(5, "Ahmet");
    a[0].announce();
    a[1].announce();
    a[2].announce();
    a[3].announce();
    a[4].announce();
    delete a[0];
    return (0);
}