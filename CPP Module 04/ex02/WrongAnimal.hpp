#pragma once
#include <iostream>

class WrongAnimal {
protected:
    std::string type;
public:
    WrongAnimal();
    WrongAnimal(const WrongAnimal& other);
    WrongAnimal& operator=(const WrongAnimal& other);
    virtual ~WrongAnimal();

    std::string getType() const;
    void makeSound() const;
};

class WrongCat : public WrongAnimal {
public:
    WrongCat();
    WrongCat(const WrongCat& other);
    WrongCat& operator=(const WrongCat& other);
    ~WrongCat();
    void makeSound() const;
};

class WrongDog : public WrongAnimal {
public:
    WrongDog();
    WrongDog(const WrongDog& other);
    WrongDog& operator=(const WrongDog& other);
    ~WrongDog();
    void makeSound() const;
};