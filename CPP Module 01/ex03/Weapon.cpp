#include "Weapon.hpp"

Weapon::Weapon(const std::string& type) : type(type) {}

void Weapon::setType(const std::string& new_type)
{
    type = new_type;
}
const std::string& Weapon::getType() {
    return type;
}