#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
    try {
        Bureaucrat b1("bro", 5);
        Bureaucrat b2("no bro", 50);
        Bureaucrat b3("no bro frfrfr", 150);
        
        ShrubberyCreationForm form1("Bath");
        RobotomyRequestForm form2("Lobotomy");
        PresidentialPardonForm form3("Trashcan");

        std::cout << "Form 1: Shrubbery Creation Form\n";
        std::cout << form1 << std::endl;
        b1.signForm(form1);
        b1.executeForm(form1);
        b2.executeForm(form1);

        std::cout << "\nForm 2: Robotomy Request Form\n";
        std::cout << form2 << std::endl;
        b1.signForm(form2);
        b1.executeForm(form2);
        b3.executeForm(form2);

        std::cout << "\nForm 3: Presidential Pardon Form\n";
        std::cout << form3 << std::endl;
        b2.signForm(form3);
        b1.executeForm(form3);
        b3.executeForm(form3);

    } catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    
    return 0;
}
