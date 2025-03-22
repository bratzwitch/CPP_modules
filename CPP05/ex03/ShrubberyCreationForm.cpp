#include "ShrubberyCreationForm.hpp"
#include <iostream>
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) 
    : AForm("Shrubbery Creation", 145, 137), target(target) {}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const {
    if (!getIsSigned()) {
        throw AForm::GradeTooLowException();
    }
    if (executor.getGrade() > getExecGrade()) {
        throw AForm::GradeTooLowException();
    }

    std::ofstream file((target + "_shrubbery").c_str());
    if (file.is_open()) {
        file << "     ^\n";
        file << "    ^^^\n";
        file << "   ^^^^^\n";
        file << "  ^^^^^^^\n";
        file << " ^^^^^^^^^^\n";
        file << "^^^^^^^O^^^^^^\n";
        std::cout << "Shrubbery creation complete for " << target << "!" << std::endl;
    } else {
        std::cout << "Failed to create shrubbery at " << target << std::endl;
    }
}
