#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {};

ScalarConverter::ScalarConverter(const ScalarConverter& src) {
    (void)src;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& src) {
    (void)src;
    return *this;
}

ScalarConverter::~ScalarConverter() {}

void ScalarConverter::toChar(double data)
{
    std::cout << "char: ";  

    if (std::isnan(data) || std::isinf(data) || data < 0 || data > 256) {
        std::cout << "impossible" << std::endl;
        return ;
    }

    int ascii = static_cast<int>(data);
    if (ascii < 32 || ascii > 126)
        std::cout << "Non displayable" << std::endl;
    else {
        char c = ascii;
        std::cout << "'" << c <<  "'" << std::endl;
    }
}

void ScalarConverter::toInt(double data)
{
    std::cout << "int: ";

    if (std::isnan(data) || std::isinf(data) || data > INT_MAX || data < INT_MIN)
    {
        std::cout << "impossible" << std::endl;
        return ;
    }
    int real_int = static_cast<int>(data);
    std::cout << real_int << std::endl;
}

void ScalarConverter::toFloat(double data)
{
    std::cout << "float: ";

    if (std::isnan(data)) {
        std::cout << "nanf" << std::endl;
        return ;
    }
    if (std::isinf(data)) {
        if (data < 0)
            std::cout << "-inff" << std::endl;
        else
            std::cout << "inff" << std::endl;
        return;
    }

    float real_float = static_cast<float>(data);
    if (real_float == static_cast<long>(real_float))
        std::cout << real_float << ".0f" << std::endl;
    else
        std::cout << real_float << "f" << std::endl;
}

void ScalarConverter::toDobule(double data)
{
    std::cout << "double: ";

    if (std::isnan(data))
    {
        std::cout << "nan" << std::endl;
        return ;
    }
    if (std::isinf(data)) {
        if (data < 0)
            std::cout << "-inf" << std::endl;
        else
            std::cout << "inf" << std::endl;
        return;
    }
    if (data == static_cast<long>(data))
        std::cout << data << ".0" << std::endl;
    else
        std::cout << data << std::endl;
}

void ScalarConverter::convert(std::string s_data)
{
    char *c_convert;
    double data;
    
    if (s_data.length() == 1 && !std::isdigit(s_data[0])) {
        data = static_cast<double>(s_data[0]);
    } else {
    data = std::strtod(s_data.c_str(), &c_convert);
    if (s_data != "nan" && s_data != "nanf" && 
            s_data != "inf" && s_data != "inff" && 
            s_data != "-inf" && s_data != "-inff" &&
            s_data != "+inf" && s_data != "+inff" &&
            *c_convert != '\0' && std::string(c_convert) != "f") {}
    }
    toChar(data);
    toInt(data);
    toFloat(data);
    toDobule(data);
}