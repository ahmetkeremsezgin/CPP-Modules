#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
private:
    const std::string _name;
    bool              _signed;
    const int         _signGrade;
    const int         _execGrade;

public:
    Form(const std::string name, int signGrade, int execGrade);
    Form(const Form &src);
    Form &operator=(const Form &rhs);
    ~Form();

    std::string getName() const;
    bool        getIsSigned() const;
    int         getSignGrade() const;
    int         getExecGrade() const;

    void beSigned(const Bureaucrat &b);

    class GradeTooHighException : public std::exception {
    public:
        virtual const char* what() const throw() {
            return "Form grade is too high!";
        }
    };

    class GradeTooLowException : public std::exception {
    public:
        virtual const char* what() const throw() {
            return "Form grade is too low!";
        }
    };
};

std::ostream &operator<<(std::ostream &out, const Form &f);

#endif