#include "PhoneBook.hpp"
#include <iostream>
#include <cstdlib>

PhoneBook::PhoneBook() : index(0) {}

bool is_printable_string(const std::string str)
{
    for (size_t i = 0; i < str.length(); i++)
    {
        if (str[i] < 32 || str[i] > 126)
            return false;
    }
    return true;
}

std::string PhoneBook::get_input(const std::string prompt)
{
    std::string input;
    while (true)
    {
        std::cout << prompt;
        std::getline(std::cin, input);

        if (std::cin.eof())
            exit(0);

        if (input.empty())
        {
            std::cout << "This field cannot be empty. Please enter again.\n";
            continue;
        }

        if (!is_printable_string(input))
        {
            std::cout << "Invalid characters detected. Only printable ASCII characters are allowed.\n";
            continue;
        }

        break;
    }
    return input;
}

void PhoneBook::add_contact()
{
    std::string f = get_input("Firstname: ");
    std::string l = get_input("Lastname: ");
    std::string n = get_input("Nickname: ");
    std::string p = get_input("Phone: ");
    std::string d = get_input("Darkest secret: ");

    bool allFilled = !f.empty() && !l.empty() && !n.empty() && !p.empty() && !d.empty();
    if (!allFilled)
    {
        std::cout << "All fields must be filled. Contact not added." << std::endl;
        return;
    }

    contacts[index % 8].set_contact(f, l, n, p, d);
    index++;
    std::cout << "Contact added!" << std::endl;
}

void PhoneBook::search()
{
    if (index == 0)
    {
        std::cout << "No contacts in phonebook." << std::endl;
        return;
    }

    std::cout << "     Index|First Name| Last Name|  Nickname" << std::endl;
    for (int i = 0; i < index && i < 8; i++)
        contacts[i].print_contact(i, 0);

    std::string inputIndex;
    std::cout << "Enter index of contact to view: ";
    std::getline(std::cin, inputIndex);

    if (std::cin.eof())
        exit(0);

    if (inputIndex.empty() || inputIndex.find_first_not_of("0123456789") != std::string::npos)
    {
        std::cout << "Invalid index format." << std::endl;
        return;
    }

    int view_index = std::atoi(inputIndex.c_str());

    if (view_index < 0 || view_index >= index || view_index >= 8)
    {
        std::cout << "Index out of range." << std::endl;
        return;
    }

    contacts[view_index].print_contact(view_index, 1);
}
