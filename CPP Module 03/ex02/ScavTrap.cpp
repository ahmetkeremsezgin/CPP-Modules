#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
    hit_point = 100;
    energy_point = 50;
    attack_damage = 20;
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap **" << this->name << "** destroyed!" << std::endl;
}
void ScavTrap::guardGate()
{
    std::cout << "ScavTrap **" << this->name << "** is now in Gate Keeper mode." << std::endl;
}
