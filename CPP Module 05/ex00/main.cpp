#include "Bureaucrat.hpp"

int main() {
    try {
        Bureaucrat a("Ahmet", 2);
        std::cout << a << std::endl;
        a.incrementGrade();
        std::cout << "After increment: " << a << std::endl;
        a.incrementGrade();
    }
    catch (const std::exception &e) {
        std::cerr << "Test 1 Error: " << e.what() << std::endl;
    }

    std::cout << "---" << std::endl;

    try {
        Bureaucrat b("Bürokrat X", 151);
    }
    catch (const std::exception &e) {
        std::cerr << "Test 2 Error: " << e.what() << std::endl;
    }

    return 0;
}