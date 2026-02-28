#include "Bureaucrat.hpp"
#include "AForm.hpp"

int main() {
    try {
        Bureaucrat boss("Müdür", 1);
        Bureaucrat intern("Stajyer", 150);
        AForm contract("Önemli Sözleşme", 50, 50);

        std::cout << contract << std::endl;

        intern.signForm(contract);
        boss.signForm(contract);

        std::cout << contract << std::endl;
    } 
    catch (std::exception &e) {
        std::cout << "Kritik Hata: " << e.what() << std::endl;
    }
    return 0;
}