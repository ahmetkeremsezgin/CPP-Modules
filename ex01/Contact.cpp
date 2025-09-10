#include "Contact.hpp"

void Contact::set_contact(std::string f, std::string l, std::string n, std::string p, std::string d)
{
    firstname = f;
    lastname = l;
    nickname = n;
    phoneNumber = p;
    darkestSecret = d;
}

std::string Contact::check_str(std::string str)
{
    if (str.length() > 10)
        return str.substr(0, 9) + ".";
    return std::string(10 - str.length(), ' ') + str;
}

void Contact::print_contact(int index, int full)
{
    if (full)
    {
        std::cout << "First Name:     " << firstname << std::endl;
        std::cout << "Last Name:      " << lastname << std::endl;
        std::cout << "Nickname:       " << nickname << std::endl;
        std::cout << "Phone Number:   " << phoneNumber << std::endl;
        std::cout << "Darkest Secret: " << darkestSecret << std::endl;
    }
    else
    {
        std::cout << "         " << index << "|"
                  << check_str(firstname) << "|"
                  << check_str(lastname) << "|"
                  << check_str(nickname) << std::endl;
    }
}
