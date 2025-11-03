#include "Fixed.hpp"
#include <cmath>
Fixed::Fixed() : number(0) {
    std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;    
}

Fixed::Fixed(const int value) {
    std::cout << "Int constructor called" << std::endl;
    this->number = value << base;
}

Fixed::Fixed(const float value) {
    std::cout << "Float constructor called" << std::endl;
    this->number = roundf(value * (1 << base));
}

Fixed::Fixed(const Fixed &parent) {
    std::cout << "Copy constructor called" << std::endl;
    this->number = parent.number;
}

Fixed &Fixed::operator=(const Fixed &parent) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &parent)
        this->number = parent.number;
    return *this;
}

int Fixed::getRawBits() const {
    return this->number;
}

void Fixed::setRawBits(int const raw) {
    this->number = raw;
}

float Fixed::toFloat(void) const {
    return static_cast<float>(this->number) / (1 << base);
}

int Fixed::toInt(void) const {
    return this->number >> base;
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed) {
    out << fixed.toFloat();
    return out;
}
