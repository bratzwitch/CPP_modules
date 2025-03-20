#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
    try {
        Bureaucrat b1("Alice", 50);
        Bureaucrat b2("Bob", 100);
        Form form1("Form1", 30, 40);
        Form form2("Form2", 60, 80);

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
