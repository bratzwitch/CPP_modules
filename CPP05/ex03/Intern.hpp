#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class AForm;

class Intern {
    public:
        Intern();
        Intern(const Intern &copy);
        ~Intern();
        Intern& operator=(const Intern& copy);
        AForm* makeForm(const std::string& formName, const std::string& target);
};

#endif
