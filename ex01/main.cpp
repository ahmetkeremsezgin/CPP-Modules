#include <iostream>
#include <string>
#include <cstdlib>

class Contact
{
private:
    std::string firstname, lastname, nickname, phoneNumber, darkestSecret;

public:
    void set_contact(std::string f, std::string l, std::string n, std::string p, std::string d)
    {
        firstname = f;
        lastname = l;
        nickname = n;
        phoneNumber = p;
        darkestSecret = d;
    }


    std::string check_str(std::string str)
    {
    if (str.length() > 10)
        str = str.substr(0, 9) + ".";
    else if (str.length() < 10)
        str = std::string(10 - str.length(), ' ') + str;
    return str;
    }

    void print_contact(int index, int selected)
    {
        std::cout << index << "|"
              << check_str(firstname) << "|" 
              << check_str(lastname) << "|" 
              << check_str(nickname)  << "|" 
              << check_str(phoneNumber);
            if (selected)
                std::cout << "|" << check_str(darkestSecret);
            std::cout << std::endl;
    }
};

class PhoneBook
{
private:
    Contact contacts[8];
    int index;

public:
    PhoneBook() : index(0) {}

    void add_contact()
    {
        std::string f, l, n, p, d;
        std::cout << "Firstname: ";
        std::getline(std::cin, f);
        std::cout << "Lastname: ";
        std::getline(std::cin, l);
        std::cout << "Nickname: ";
        std::getline(std::cin, n);
        std::cout << "Phone: ";
        std::getline(std::cin, p);
        std::cout << "Darkest secret: ";
        std::getline(std::cin, d);

        contacts[index % 8].set_contact(f, l, n, p, d);
        index++;
        std::cout << "Contact added!" << std::endl;
    }

    void search()
    {
    std::string inputIndex;
        std::cout << "---SEARCH RESULTS---" << std::endl; 
    for (int i = 0; i < index; i++)
        contacts[i].print_contact(i, 0);
    std::cout << "View index: ";
    std::getline(std::cin, inputIndex);
    int view_index = std::atoi(inputIndex.c_str());
    contacts[view_index].print_contact(view_index, 1);
    std::cout << std::endl;
      
    }
};

int main()
{
    std::string line;
    PhoneBook phonebook;

    while (1)
    {
        std::cout << "PHONEBOOK|==>";
        std::getline(std::cin, line);
        if (line == "ADD")
            phonebook.add_contact();
        else if (line == "EXIT")
            break;
        else if (line == "SEARCH")
            phonebook.search();
        else
            std::cout << "USAGE: ADD | SEARCH | EXIT" << std::endl;
    }
}
