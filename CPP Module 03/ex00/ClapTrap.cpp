#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name) : name(name), hit_point(10), energy_point(10), attack_damage(0)
{
    std::cout << "ClapTrap **" << this->name << "** created!"
              << " | HP: " << this->hit_point
              << ", EP: " << this->energy_point
              << ", AD: " << this->attack_damage
              << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
    if (this != &other)
    {
        this->name = other.name;
        this->hit_point = other.hit_point;
        this->energy_point = other.energy_point;
        this->attack_damage = other.attack_damage;
    }
    std::cout << "ClapTrap **" << this->name << "** assigned!" << std::endl;
    return *this;
}

ClapTrap::ClapTrap(const ClapTrap &other)
{
    this->name = other.name;
    this->hit_point = other.hit_point;
    this->energy_point = other.energy_point;
    this->attack_damage = other.attack_damage;
    std::cout << "ClapTrap **" << this->name << "** copied!" << std::endl;
}

void ClapTrap::attack(const std::string &target)
{
    if (this->energy_point <= 0 || this->hit_point <= 0)
    {
        std::cout << "ClapTrap **" << this->name << "** has no energy or hit points left to attack!" << std::endl;
        return;
    }
    this->energy_point--;
    std::cout << "ClapTrap **" << this->name << "** attacks **" << target << "**, causing **" << this->attack_damage << "** points of damage!"
              << " | EP left: " << this->energy_point << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    this->hit_point -= amount;
    if (this->hit_point < 0)
        this->hit_point = 0;
    std::cout << "ClapTrap **" << this->name << "** takes **" << amount << "** points of damage!"
              << " | HP left: " << this->hit_point << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (this->energy_point <= 0 || this->hit_point <= 0)
    {
        std::cout << "ClapTrap **" << this->name << "** has no energy or hit points left to repair!" << std::endl;
        return;
    }
    this->hit_point += amount;
    this->energy_point--;
    std::cout << "ClapTrap **" << this->name << "** is repaired by **" << amount << "** points!"
              << " | HP: " << this->hit_point << ", EP left: " << this->energy_point << std::endl;
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap **" << this->name << "** destroyed!" << std::endl;
}