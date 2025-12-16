#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include <iostream>

int main()
{
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    delete j;
    delete i;

    int size = 4;
    Animal* animals[size];

    for (int k = 0; k < size; k++)
    {
        if (k < size / 2)
            animals[k] = new Dog();
        else
            animals[k] = new Cat();
    }

    std::cout << "Deleting array..." << std::endl;
    for (int k = 0; k < size; k++)
    {
        delete animals[k];
    }

    Dog basic;
    Dog tmp = basic; 
    
    return 0;
}