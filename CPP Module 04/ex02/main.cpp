#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include <iostream>

int main()
{
    const int size = 4;
    Animal* animals[size];

    for (int i = 0; i < size; i++)
    {
        if (i < size / 2)
            animals[i] = new Dog();
        else
            animals[i] = new Cat();
    }

    std::cout << std::endl;

    for (int i = 0; i < size; i++)
    {
        animals[i]->makeSound();
    }

    std::cout << std::endl;

    for (int i = 0; i < size; i++)
    {
        delete animals[i];
    }

 
    Dog* original_dog = new Dog();
    Dog* copy_dog = new Dog(*original_dog);

    delete original_dog;

    copy_dog->makeSound();

    delete copy_dog;
    return 0;
}