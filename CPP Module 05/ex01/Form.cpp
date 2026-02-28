#include "Form.hpp"

Form::Form(const std::string name, int signGrade, int execGrade) 
    : _name(name), _signed(false), _signGrade(signGrade), _execGrade(execGrade) {
    
    if (this->_signGrade < 1 || this->_execGrade < 1)
        throw Form::GradeTooHighException();
    if (this->_signGrade > 150 || this->_execGrade > 150)
        throw Form::GradeTooLowException();
}

Form::Form(const Form &src) 
    : _name(src._name), _signed(src._signed), _signGrade(src._signGrade), _execGrade(src._execGrade) {
}

Form &Form::operator=(const Form &rhs) {
    if (this != &rhs) {
        this->_signed = rhs._signed;
    }
    return *this;
}

Form::~Form() {}

std::string Form::getName() const {
    return this->_name;
}

bool Form::getIsSigned() const {
    return this->_signed;
}

int Form::getSignGrade() const {
    return this->_signGrade;
}

int Form::getExecGrade() const {
    return this->_execGrade;
}

void Form::beSigned(const Bureaucrat &b) {
    if (b.getGrade() <= this->_signGrade) {
        this->_signed = true;
    } else {
        throw Form::GradeTooLowException();
    }
}

std::ostream &operator<<(std::ostream &out, const Form &f) {
    out << "Form Name: " << f.getName() 
        << " | Signed: " << (f.getIsSigned() ? "Yes" : "No")
        << " | Sign Grade Required: " << f.getSignGrade()
        << " | Exec Grade Required: " << f.getExecGrade();
    return out;
}