#include <iostream>
#include "Base.hpp"

int main()
{
    std::srand(std::time(NULL));
    for (size_t i = 0; i < 3; i++)
    {
        Base *a = Base::generate();
        a->identify(a);
        a->identify(*a);
        delete a;
    }
}