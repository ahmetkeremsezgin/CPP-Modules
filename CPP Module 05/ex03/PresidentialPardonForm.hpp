#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"


class PresidentialPardonForm : public AForm {
private:
    const std::string _target;
    PresidentialPardonForm(); 

public:
    PresidentialPardonForm(const std::string target);
    PresidentialPardonForm(const PresidentialPardonForm &src);
    virtual ~PresidentialPardonForm(); 

    PresidentialPardonForm &operator=(const PresidentialPardonForm &rhs);

    void execute(Bureaucrat const & executor) const;
};

#endif