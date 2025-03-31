#include "Intern.hpp"
#include <iostream>

Intern::Intern() {
}

Intern::~Intern() {
}

Intern::Intern(const Intern& copy) {
    (void)copy;
}

Intern& Intern::operator=(const Intern& copy) {
    (void)copy;
    return *this;
}

AForm* Intern::makeForm(const std::string& formName, const std::string& target) {
    AForm* form = NULL;

    if (formName == "shrubbery creation") {
        form = new ShrubberyCreationForm(target);
    }
    else if (formName == "robotomy request") {
        form = new RobotomyRequestForm(target);
    }
    else if (formName == "presidential pardon") {
        form = new PresidentialPardonForm(target);
    }
    
    if (form) {
        std::cout << "Intern creates " << formName << std::endl;
    } else {
        std::cout << "Error: Form '" << formName << "' doesn't exist." << std::endl;
    }

    return form;
}
