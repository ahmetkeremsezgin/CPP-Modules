#include <iostream>
#include "Weapon.hpp"
#pragma once

class HumanA{
    private:
    std::string name;
    Weapon& weapon;

    public:
    HumanA(const std::string name, Weapon& weapon);
    void attack();
};