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

        bool operator>(const Fixed &other) const;
        bool operator<(const Fixed &other) const;
        bool operator>=(const Fixed &other) const;
        bool operator<=(const Fixed &other) const;
        bool operator==(const Fixed &other) const;
        bool operator!=(const Fixed &other) const;
        
        Fixed operator+(const Fixed &other) const;
        Fixed operator-(const Fixed &other) const;
        Fixed operator*(const Fixed &other) const;
        Fixed operator/(const Fixed &other) const;


        Fixed& operator++();
        Fixed operator++(int);
        Fixed& operator--();
        Fixed operator--(int);
        
        static Fixed&        min(Fixed& a, Fixed& b);
        static const Fixed&  min(const Fixed& a, const Fixed& b);
        static Fixed&        max(Fixed& a, Fixed& b);
        static const Fixed&  max(const Fixed& a, const Fixed& b);
    
        ~Fixed();
};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed);