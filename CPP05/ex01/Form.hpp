#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"

class Form
{
    private:
        const std::string name;
        bool is_signed;
        const int sign_grade;
        const int exec_grade;
    public:
        Form();
        Form(const std::string& name, int sign_grade, int exec_grade);
        Form(const Form& other);
        Form& operator=(const Form& other);
        ~Form();
        const std::string& getName() const;
        bool getIsSigned() const;
        int getSignGrade() const;
        int getExecGrade() const;
        void beSigned(const Bureaucrat &bureaucrat);
        class GradeTooHighException : public std::exception {
            public:
                const char* what() const throw();
        };
        class GradeTooLowException : public std::exception {
            public:
                const char* what() const throw();
        };
};

std::ostream& operator<<(std::ostream& os, const Form& f);

#endif