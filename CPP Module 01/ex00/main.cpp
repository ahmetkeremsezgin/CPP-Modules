#include <iostream>
#include "Zombie.hpp"

int main()
{
    Zombie* b = newZombie("b");
    b->announce();
    delete b;
    randomChump("Ahmet");
    return (0);
}