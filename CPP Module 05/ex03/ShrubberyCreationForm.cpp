#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) 
    : AForm("Shrubbery Creation", 145, 137), _target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &src) 
    : AForm(src), _target(src._target) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &rhs) {
    (void)rhs;
    return *this;
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const {

    if (!this->getIsSigned())
        throw std::runtime_error("Form not signed!");
    if (executor.getGrade() > this->getExecGrade())
        throw AForm::GradeTooLowException();

    std::ofstream outfile((_target + "_shrubbery").c_str());
    if (outfile.is_open()) {
    outfile << "               ,@@@@@@@,                  ,@@@@@@@,          " << std::endl;
    outfile << "       ,,,.   ,@@@@@@/@@,  .oo8888o.     ,@@@@@@/@@,  .oo8888o." << std::endl;
    outfile << "    ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o  ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o" << std::endl;
    outfile << "   ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88 ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88" << std::endl;
    outfile << "   %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888' %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'" << std::endl;
    outfile << "   %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'  %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'" << std::endl;
    outfile << "   `&%\\ ` /%&'    |.|        \\ '|8'    `&%\\ ` /%&'    |.|        \\ '|8'" << std::endl;
    outfile << "       |o|        | |         | |          |o|        | |         | |" << std::endl;
    outfile << "       |.|        | |         | |          |.|        | |         | |" << std::endl;
    outfile << "    \\\\/ ._\\//_/__/  ,\\_//__\\\\/.  \\_//__\\\\/ ._\\//_/__/  ,\\_//__\\\\/.  \\_//__" << std::endl;
        outfile.close();
    }
}