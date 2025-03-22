#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {

    Intern intern;
    Bureaucrat bureaucrat("Zaphod", 1);


    AForm* rrf = intern.makeForm("robotomy request", "Bender");
    if (rrf) {
        std::cout << *rrf << std::endl;
        bureaucrat.signForm(*rrf);
        bureaucrat.executeForm(*rrf);
        delete rrf;
    }
    AForm* shrubbery = intern.makeForm("shrubbery creation", "home");
    if (shrubbery) {
        std::cout << *shrubbery << std::endl;
        bureaucrat.signForm(*shrubbery);
        bureaucrat.executeForm(*shrubbery);
        delete shrubbery;
    }
    return 0;
}


