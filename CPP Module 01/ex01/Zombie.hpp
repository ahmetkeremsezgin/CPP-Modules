#include <iostream>
#pragma once

class Zombie{
    private:
    std::string name;
    
    public:
    Zombie();
    void announce();
    void set(std::string name);
    ~Zombie();
};

Zombie* zombieHorde( int N, std::string name );