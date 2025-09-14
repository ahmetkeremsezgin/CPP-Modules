#include <iostream>
#include "Zombie.hpp"

int main()
{
    Zombie* a = zombieHorde(5, "Ahmet");
    a[0].announce();
    return (0);
}