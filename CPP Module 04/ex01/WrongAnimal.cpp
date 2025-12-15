#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("WrongAnimal") {
    std::cout << "WrongAnimal default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& other) : type(other.type) {
    std::cout << "WrongAnimal copy constructor called" << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other) {
    std::cout << "WrongAnimal assignment operator called" << std::endl;
    if (this != &other) {
        type = other.type;
    }
    return *this;
}

void WrongAnimal::makeSound() const {
    std::cout << "Some generic wrong animal sound" << std::endl;
}

std::string WrongAnimal::getType() const {
    return type;
}

WrongAnimal::~WrongAnimal() {
    std::cout << "WrongAnimal destructor called" << std::endl;
}

WrongCat::WrongCat() {
    type = "WrongCat";
    std::cout << "WrongCat default constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat& other) : WrongAnimal(other) {
    std::cout << "WrongCat copy constructor called" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& other) {
    std::cout << "WrongCat assignment operator called" << std::endl;
    if (this != &other) {
        WrongAnimal::operator=(other);
    }
    return *this;
}

WrongCat::~WrongCat() {
    std::cout << "WrongCat destructor called" << std::endl;
}

void WrongCat::makeSound() const {
    std::cout << "Wrong Meow!" << std::endl;
}

WrongDog::WrongDog() {
    type = "WrongDog";
    std::cout << "WrongDog default constructor called" << std::endl;
}

WrongDog::WrongDog(const WrongDog& other) : WrongAnimal(other) {
    std::cout << "WrongDog copy constructor called" << std::endl;
}

WrongDog& WrongDog::operator=(const WrongDog& other) {
    std::cout << "WrongDog assignment operator called" << std::endl;
    if (this != &other) {
        WrongAnimal::operator=(other);
    }
    return *this;
}

WrongDog::~WrongDog() {
    std::cout << "WrongDog destructor called" << std::endl;
}

void WrongDog::makeSound() const {
    std::cout << "Wrong Woof!" << std::endl;
}
