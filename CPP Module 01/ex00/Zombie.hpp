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

Zombie* newZombie(std::string name);
void randomChump(std::string name);