#include "PhoneBook.hpp"
#include <iostream>

int main()
{
    std::string line;
    PhoneBook phonebook;

    while (true)
    {
        std::cout << "PHONEBOOK|==> ";
        std::getline(std::cin, line);

        if (std::cin.eof())
            break;

        if (line == "ADD")
            phonebook.add_contact();
        else if (line == "SEARCH")
            phonebook.search();
        else if (line == "EXIT")
            break;
        else if (!line.empty())
            std::cout << "USAGE: ADD | SEARCH | EXIT" << std::endl;
    }

    return 0;
}
