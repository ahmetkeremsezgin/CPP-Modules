#include "Base.hpp"
#include "Tmp.hpp"
#include <cstdlib>
#include <ctime>

Base::~Base() {}

Base* Base::generate() {
    int winner = std::rand() % 3;
    switch (winner)
    {
    case 0:
        return new A();
    case 1:
        return new B();
    case 2:
        return new C();
    }
    return NULL;
}

void Base::identify(Base *p) {
    if (dynamic_cast<A*>(p)) {
        std::cout << "A" << std::endl;
    } 
    else if (dynamic_cast<B*>(p)) {
        std::cout << "B" << std::endl;
    } 
    else if (dynamic_cast<C*>(p)) {
        std::cout << "C" << std::endl;
    } 
    else {
        std::cout << "Unknown type" << std::endl;
    }
}

void Base::identify(Base& p) {
    try {
        A &a = dynamic_cast<A&>(p);
        (void)a;
        std::cout << "R: A" << std::endl;
        return;
    } catch (const std::exception& e) {}

    try {
        B &b = dynamic_cast<B&>(p);
        (void)b;
        std::cout << "R: B" << std::endl;
        return;
    } catch (const std::exception& e) {}

    try {
        C &c = dynamic_cast<C&>(p);
        (void)c;
        std::cout << "R: C" << std::endl;
        return;
    } catch (const std::exception& e) {}
}