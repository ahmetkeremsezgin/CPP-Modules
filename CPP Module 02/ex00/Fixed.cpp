#include "Fixed.hpp"

Fixed::Fixed() : number(0) {
    std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;    
}

int Fixed::getRawBits() const {
    std::cout << "getRawBits member function called" << std::endl;
    return this->number;
}

void Fixed::setRawBits(int const raw) {
    std::cout << "setRawBits member function called" << std::endl;
    this->number = raw;
}

Fixed& Fixed::operator=(const Fixed &parent) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &parent) {
        this->number = parent.getRawBits();
    }
    return *this;
}

Fixed::Fixed(const Fixed &parent) {
    std::cout << "Copy constructor called" << std::endl;

    this->number = parent.getRawBits();
}
