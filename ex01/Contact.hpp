#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>
#include <iostream>

class Contact
{
private:
    std::string firstname, lastname, nickname, phoneNumber, darkestSecret;

public:
    void set_contact(std::string f, std::string l, std::string n, std::string p, std::string d);
    void print_contact(int index, int full);
    std::string check_str(std::string str);
};

#endif
