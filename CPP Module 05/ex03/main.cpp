#include "Intern.hpp"
#include "Bureaucrat.hpp"

int main() {
    Intern someRandomIntern;
    Bureaucrat boss("Boss", 1);
    AForm* rrf;

    rrf = someRandomIntern.makeForm("robotomy request", "Bender");
    if (rrf) {
        boss.signForm(*rrf);
        boss.executeForm(*rrf);
        delete rrf;
    }

    AForm* unknown = someRandomIntern.makeForm("vacation request", "Hawaii");
    if (!unknown) {
        std::cout << "Form creation failed as expected." << std::endl;
    }

    return 0;
}