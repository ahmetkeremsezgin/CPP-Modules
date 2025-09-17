#include <iostream>
#pragma once

class Weapon
{
    private: 
    std::string type;
    
    public:
    Weapon(const std::string& type);
    void setType(const std::string& new_type);
    const std::string& getType();
};