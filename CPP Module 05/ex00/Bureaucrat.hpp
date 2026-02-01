#ifndef BRUEAUCRAT_HPP
#define BRUEAUCRAT_HPP

#include <iostream>

class Bureaucrat
{
    private:
        std::string const name;
        int grade;
    public:
        Bureaucrat();
        Bureaucrat(std::string const & name, int grade);
        Bureaucrat(Bureaucrat const & other);
        Bureaucrat & operator=(Bureaucrat const & other);
        ~Bureaucrat();

        std::string const & getName() const;
        int getGrade() const;

        void incrementGrade();
        void decrementGrade();

        class GradeTooHighException : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };

        class GradeTooLowException : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };
};

#endif