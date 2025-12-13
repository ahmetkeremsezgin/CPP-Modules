#pragma once
#include <iostream>

class ClapTrap
{
    private: 
    std::string name;
    int hit_point;
    int energy_point;
    int attack_damage;
    public:
    ClapTrap(std::string name);
    ClapTrap(const ClapTrap &other);
    ClapTrap &operator=(const ClapTrap &other);
    ~ClapTrap();
    void attack(const std::string &target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);
};