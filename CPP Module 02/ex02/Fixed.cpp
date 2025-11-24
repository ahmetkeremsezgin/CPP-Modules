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

bool Fixed::operator>(const Fixed &other) const {
    return this->number > other.number;
}

bool Fixed::operator<(const Fixed &other) const {
    return this->number < other.number;
}

bool Fixed::operator>=(const Fixed &other) const {
    return this->number >= other.number;
}

bool Fixed::operator<=(const Fixed &other) const {
    return this->number <= other.number;
}

bool Fixed::operator==(const Fixed &other) const {
    return this->number == other.number;
}

bool Fixed::operator!=(const Fixed &other) const {
    return this->number != other.number;
}

Fixed Fixed::operator+(const Fixed &other) const {
    Fixed res;
    res.setRawBits(this->number + other.number);
    return res;
}

Fixed Fixed::operator-(const Fixed &other) const {
    Fixed res;
    res.setRawBits(this->number - other.number);
    return res;
}

Fixed Fixed::operator*(const Fixed &other) const {
    Fixed res;

    long tmp = (long)this->number * (long)other.number;
    res.setRawBits(tmp >> base);

    return res;
}

Fixed Fixed::operator/(const Fixed &other) const {
    Fixed res;

    long tmp = ((long)this->number << base) / other.number;
    res.setRawBits(tmp);

    return res;
}


Fixed& Fixed::operator++()
{
    this->number += 1;
    return *this;
}

Fixed Fixed::operator++(int)
{
    Fixed temp(*this);
    this->number += 1;
    return temp;
}

Fixed& Fixed::operator--()
{
    this->number -= 1;
    return *this;
}


Fixed Fixed::operator--(int)
{
    Fixed temp(*this);
    this->number -= 1;
    return temp;
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

Fixed& Fixed::min(Fixed& a, Fixed& b)
{
    return (a < b) ? a : b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b)
{
    return (a > b) ? a : b;
}

// Const references
const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
    return (a < b) ? a : b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
    return (a > b) ? a : b;
}
