#include "AForm.hpp"

AForm::AForm(const std::string name, int signGrade, int execGrade) 
    : _name(name), _signed(false), _signGrade(signGrade), _execGrade(execGrade) {
    
    if (this->_signGrade < 1 || this->_execGrade < 1)
        throw AForm::GradeTooHighException();
    if (this->_signGrade > 150 || this->_execGrade > 150)
        throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm &src) 
    : _name(src._name), _signed(src._signed), _signGrade(src._signGrade), _execGrade(src._execGrade) {
}

AForm &AForm::operator=(const AForm &rhs) {
    if (this != &rhs) {
        this->_signed = rhs._signed;
    }
    return *this;
}

AForm::~AForm() {}

std::string AForm::getName() const {
    return this->_name;
}

bool AForm::getIsSigned() const {
    return this->_signed;
}

int AForm::getSignGrade() const {
    return this->_signGrade;
}

int AForm::getExecGrade() const {
    return this->_execGrade;
}

void AForm::beSigned(const Bureaucrat &b) {
    if (b.getGrade() <= this->_signGrade) {
        this->_signed = true;
    } else {
        throw AForm::GradeTooLowException();
    }
}

std::ostream &operator<<(std::ostream &out, const AForm &f) {
    out << "Form Name: " << f.getName() 
        << " | Signed: " << (f.getIsSigned() ? "Yes" : "No")
        << " | Sign Grade Required: " << f.getSignGrade()
        << " | Exec Grade Required: " << f.getExecGrade();
    return out;
}