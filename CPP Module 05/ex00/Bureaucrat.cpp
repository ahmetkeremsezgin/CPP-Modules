#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string name) : name(name), grade(150){};

Bureaucrat::Bureaucrat(std::string const & name, int grade) : name(name)
{
    if (grade < 1)
        throw GradeTooHighException();
    else if (grade > 150)
        throw GradeTooLowException();
    this->grade = grade;
}

Bureaucrat::Bureaucrat(Bureaucrat const & other) : name(other.name), grade(other.grade){};

Bureaucrat & Bureaucrat::operator=(Bureaucrat const & other)
{
    if (this != &other)
        this->grade = other.grade;
    return *this;
}

Bureaucrat::~Bureaucrat(){};

