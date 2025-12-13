#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
    name = name;
    hit_point = 100;
    energy_point = 100;
    attack_damage = 30;
    std::cout << "FlagTrap **" << this->name << "** created!"
    << " | HP: " << this->hit_point
    << ", EP: " << this->energy_point
    << ", AD: " << this->attack_damage
    << std::endl;
};

FragTrap::~FragTrap()
{
    std::cout << "FlagTrap **" << this->name << "** destroyed!" << std::endl;
};

void FragTrap::highFivesGuys(void)
{
    std::cout << "FlagTrap " << name << " is requesting a positive high-five! Woohoo!" << std::endl;
};
