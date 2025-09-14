#include <iostream>
#pragma once

class Zombie{
    private:
    std::string name;
    
    public:
    Zombie(std::string name);
    void announce();
    ~Zombie();
};

Zombie* zombieHorde( int N, std::string name );