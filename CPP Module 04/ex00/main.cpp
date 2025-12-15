#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include <iostream>

int main()
{
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();

    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;

    i->makeSound(); // Cat sesi çıkarmalı (Meow)
    j->makeSound(); // Dog sesi çıkarmalı (Woof)
    meta->makeSound(); // Animal sesi çıkarmalı

    // Memory temizliği
    delete meta;
    delete j;
    delete i;

    std::cout << "--------------------------------" << std::endl;

    // WrongAnimal Testi (Ödevin istediği kısım)
    const WrongAnimal* wrongMeta = new WrongAnimal();
    const WrongAnimal* wrongI = new WrongCat();

    std::cout << wrongI->getType() << " " << std::endl;
    
    // BURASI ÖNEMLİ:
    wrongI->makeSound(); // WrongCat DEĞİL, WrongAnimal sesi çıkarmalı!
    wrongMeta->makeSound();

    delete wrongMeta;
    delete wrongI;

    return 0;
}