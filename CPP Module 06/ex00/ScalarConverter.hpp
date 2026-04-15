#ifndef SCALAR_CONVERTER_HPP
#define SCALAR_CONVERTER_HPP

#include <iostream>
#include <cstdlib>
#include <cmath>
#include <climits>

class ScalarConverter{
    private:
        ScalarConverter();
        ScalarConverter(const ScalarConverter& src);
        ScalarConverter& operator=(const ScalarConverter& src);
        ~ScalarConverter();

        static void toDobule(double data);
        static void toInt(double data);
        static void toFloat(double data);
        static void toChar(double data);
    public:
        static void convert(std::string s_data);
};

#endif