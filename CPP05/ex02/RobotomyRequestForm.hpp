#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include <cstdlib>

class RobotomyRequestForm : public AForm {
private:
    std::string target;
public:
    RobotomyRequestForm(const std::string& target);
    virtual void execute(Bureaucrat const & executor) const;
};

#endif
