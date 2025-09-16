#include <iostream>

int main()
{
    std::string variable = "HI THIS IS BRAIN";
    std::string *stringPTR = &variable;
    std::string &stringREF = variable;
    
    std::cout << "The memory address variable: " << &variable << std::endl; 
    std::cout << "The memory address stringPTR: " << &stringPTR << std::endl; 
    std::cout << "The memory address stringREF: " << &stringREF << std::endl; 
}