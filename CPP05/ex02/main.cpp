#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
    try {
        Bureaucrat b1("bro", 10);
        Bureaucrat b2("no bro", 15);
        Form form1("cool form", 30, 20);
        Form form2("no cool form", 60, 20);

        std::cout << form1 << std::endl;
        b1.signForm(form1);
        b2.signForm(form1);
        
        std::cout << form2 << std::endl;
        b2.signForm(form2);

    } catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    return 0;
}
