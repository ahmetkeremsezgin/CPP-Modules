#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const std::string name, int grade) : _name(name) {
    if (grade < 1)
        throw Bureaucrat::GradeTooHighException();
    if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
    this->_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &src) : _name(src._name), _grade(src._grade) {}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &rhs) {
    if (this != &rhs) {
        this->_grade = rhs._grade;
    }
    return *this;
}

Bureaucrat::~Bureaucrat() {}

std::string Bureaucrat::getName() const { return _name; }
int Bureaucrat::getGrade() const { return _grade; }

void Bureaucrat::incrementGrade() {
    if (_grade - 1 < 1)
        throw Bureaucrat::GradeTooHighException();
    _grade--;
}

void Bureaucrat::decrementGrade() {
    if (_grade + 1 > 150)
        throw Bureaucrat::GradeTooLowException();
    _grade++;
}

void Bureaucrat::signForm(AForm &f) {
    try {
        f.beSigned(*this);
        std::cout << this->_name << " signed " << f.getName() << std::endl;
    }
    catch (std::exception &e) {
        std::cout << this->_name << " couldn't sign " << f.getName() 
                  << " because " << e.what() << std::endl;
    }
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &obj) {
    out << obj.getName() << ", bureaucrat grade " << obj.getGrade() << ".";
    return out;
}