#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include <ctime>
#include <cstdlib>

int main() {
    std::srand(std::time(NULL));
    try {
        Bureaucrat bob("Bob", 1);

        RobotomyRequestForm form1("home");

        std::cout << form1 << std::endl;

        bob.signForm(form1);

        bob.executeForm(form1);

    } catch (std::exception &e) {
        std::cerr << "Hata oluştu: " << e.what() << std::endl;
    }
    return 0;
}