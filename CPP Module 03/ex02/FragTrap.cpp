#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
    this->name = name;
    hit_point = 100;
    energy_point = 100;
    attack_damage = 30;
    std::cout << "FlagTrap **" << this->name << "** created!"
    << " | HP: " << this->hit_point
    << ", EP: " << this->energy_point
    << ", AD: " << this->attack_damage
    << std::endl;
};

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other)
{
    std::cout << "FlagTrap **" << this->name << "** copied!" << std::endl;
};
FragTrap &FragTrap::operator=(const FragTrap &other)
{
    if (this != &other)
    {
        this->name = other.name;
        this->hit_point = other.hit_point;
        this->energy_point = other.energy_point;
        this->attack_damage = other.attack_damage;
    }
    std::cout << "FlagTrap **" << this->name << "** assigned!" << std::endl;
    return *this;
};

FragTrap::~FragTrap()
{
    std::cout << "FlagTrap **" << this->name << "** destroyed!" << std::endl;
};

void FragTrap::highFivesGuys(void)
{
    std::cout << "FlagTrap " << name << " is requesting a positive high-five! Woohoo!" << std::endl;
};
