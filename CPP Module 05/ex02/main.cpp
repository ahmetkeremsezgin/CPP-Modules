#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"

int main() {
    try {
        // 1. Bir bürokrat oluşturuyoruz (İsim: Bob, Derece: 1)
        Bureaucrat bob("Bob", 1);

        // 2. Formu oluşturuyoruz ve "target" olarak "home" veriyoruz.
        // Bu işlem sonucunda "home_shrubbery" dosyası oluşturulacak.
        ShrubberyCreationForm form1("home");

        std::cout << form1 << std::endl; // Form bilgilerini yazdır

        // 3. Bürokrat formu imzalamaya çalışıyor
        bob.signForm(form1);

        // 4. Bürokrat formu çalıştırmaya (execute) çalışıyor
        bob.executeForm(form1);

    } catch (std::exception &e) {
        std::cerr << "Hata oluştu: " << e.what() << std::endl;
    }

    return 0;
}