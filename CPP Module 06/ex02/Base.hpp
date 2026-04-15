#ifndef BASE_HPP
#define BASE_HPP

#include <cstdlib>
#include <ctime>
#include <iostream>

class Base {
    public:
        virtual  ~Base();
        static Base *generate(void);
        void identify(Base* p);
        void identify(Base& p);
};

#endif