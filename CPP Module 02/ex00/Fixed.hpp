#pragma once
#include <iostream>

class Fixed {
    private:
        int number;
        static const int base = 8;
    public:
        Fixed();
        Fixed(const Fixed &parent);
        int getRawBits() const;
        void setRawBits(int const raw);
        Fixed& operator=(const Fixed &parent);
        ~Fixed();
};