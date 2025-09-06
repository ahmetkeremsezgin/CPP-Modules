#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook
{
private:
    Contact contacts[8];
    int index;

    std::string get_input(const std::string& prompt);

public:
    PhoneBook();
    void add_contact();
    void search();
};

#endif
