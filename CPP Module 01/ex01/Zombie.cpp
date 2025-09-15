#include <iostream>
#include "Zombie.hpp"

Zombie::Zombie() : name("John Doe") {}

Zombie::~Zombie(){
    std::cout << name <<": is destroyed" << std::endl;
}

void Zombie::set(std::string new_name){
    name = new_name;
}

void Zombie::announce()
{
    std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
