#include <iostream>

int main()
{
    std::string line;
    while (1)
    {
        std::cout << "|==>";
        std::getline(std::cin, line);
        if (line == "ADD")
        else if (line == "SEARCH")
        else if (line == "EXIT")
        else
            
        std::cout << line << std::endl;
    }
}