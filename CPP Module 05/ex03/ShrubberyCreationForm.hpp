#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"


class ShrubberyCreationForm : public AForm {
private:
    const std::string _target;
    ShrubberyCreationForm(); 

public:
    ShrubberyCreationForm(const std::string target);
    ShrubberyCreationForm(const ShrubberyCreationForm &src);
    virtual ~ShrubberyCreationForm(); 

    ShrubberyCreationForm &operator=(const ShrubberyCreationForm &rhs);

    void execute(Bureaucrat const & executor) const;
};

#endif