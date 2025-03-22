#include "RobotomyRequestForm.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm(const std::string& target) 
    : AForm("Robotomy Request", 72, 45), target(target) {}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const {
    if (!getIsSigned()) {
        throw AForm::GradeTooLowException();
    }
    if (executor.getGrade() > getExecGrade()) {
        throw AForm::GradeTooLowException();
    }

    std::cout << "Drilling noises..." << std::endl;

    srand(time(NULL));
    if (rand() % 2) {
        std::cout << target << " has been robotomized successfully!" << std::endl;
    } else {
        std::cout << "Robotomy of " << target << " failed." << std::endl;
    }
}
