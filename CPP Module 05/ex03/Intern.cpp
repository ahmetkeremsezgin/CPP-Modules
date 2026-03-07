#include "Intern.hpp"

Intern::Intern() {}

Intern::Intern(const Intern &src) { (void)src; }

Intern::~Intern() {}

Intern &Intern::operator=(const Intern &rhs) {
    (void)rhs;
    return *this;
}

AForm *Intern::makeForm(const std::string name, const std::string target) {
    std::string formNames[] = {
        "shrubbery creation",
        "robotomy request",
        "presidential pardon"
    };

    for (int i = 0; i < 3; i++) {
        if (name == formNames[i]) {
            std::cout << "Intern creates " << name << std::endl;
            switch (i) {
                case 0: return new ShrubberyCreationForm(target);
                case 1: return new RobotomyRequestForm(target);
                case 2: return new PresidentialPardonForm(target);
            }
        }
    }
        std::cout << "Error: Intern cannot create " << name << " because it doesn't exist." << std::endl;
    return NULL;
}