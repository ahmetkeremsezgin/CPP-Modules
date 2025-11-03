#pragma once
#include <iostream>

class Fixed {
    private:
        int number;
        static const int base = 8;
    public:
        Fixed();
        Fixed(const int value);
        Fixed(const float value);
        Fixed(const Fixed &parent);
        float toFloat() const;
        int toInt() const;
        int getRawBits() const;
        void setRawBits(int const raw);
        Fixed& operator=(const Fixed &parent);
        ~Fixed();
};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed);