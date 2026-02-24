# define BUREAUCRAT_HPP
# ifdef BUREAUCRAT_HPP

#include <iostream>

class Bureaucrat
{
    private:
    const std::string name; 
    int _grade;

    public:
    Bureaucrat() {};
    class GradeTooLowException : public std::exception {
        public:
            virtual const char* what() const throw() {
                return "Grade too low";
            }
    };

};

#endif

try {
    throw 1;
} catch (int a) {
    std::cout << a << std::endl;
}