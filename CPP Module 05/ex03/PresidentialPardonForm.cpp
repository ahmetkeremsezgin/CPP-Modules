#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target) 
    : AForm("Presidential Pardon", 25, 5), _target(target) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &src) 
    : AForm(src), _target(src._target) {}

PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &rhs) {
    (void)rhs;
    return *this;
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const {
    if (!this->getIsSigned())
        throw std::runtime_error("Error: Form is not signed yet!");

    if (executor.getGrade() > this->getExecGrade())
        throw AForm::GradeTooLowException();

    std::cout << _target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}