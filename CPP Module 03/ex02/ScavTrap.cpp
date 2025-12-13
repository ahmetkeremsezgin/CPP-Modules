#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
    hit_point = 100;
    energy_point = 50;
    attack_damage = 20;
    std::cout << "ScavTrap **" << this->name << "** created!"
              << " | HP: " << this->hit_point
              << ", EP: " << this->energy_point
              << ", AD: " << this->attack_damage
              << std::endl;
}

void ScavTrap::attack(const std::string &target) 
{
    if (this->energy_point <= 0 || this->hit_point <= 0)
    {
        std::cout << "ScavTrap **" << this->name << "** has no energy or hit points left to attack!" << std::endl;
        return;
    }
    this->energy_point--;
    std::cout << "ScavTrap **" << this->name << "** attacks **" << target << "**, causing **" << this->attack_damage << "** points of damage!"
              << " | EP left: " << this->energy_point << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other)
{
    std::cout << "ScavTrap **" << this->name << "** copied!" << std::endl;
}
ScavTrap &ScavTrap::operator=(const ScavTrap &other)
{
    if (this != &other)
    {
        ClapTrap::operator=(other);
    }
    std::cout << "ScavTrap **" << this->name << "** assigned!" << std::endl;
    return *this;
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap **" << this->name << "** destroyed!" << std::endl;
}
void ScavTrap::guardGate()
{
    std::cout << "ScavTrap **" << this->name << "** is now in Gate Keeper mode." << std::endl;
}
