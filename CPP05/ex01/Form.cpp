#include "Form.hpp"

Form::Form() : name("default"), is_signed(false), sign_grade(150), exec_grade(150) {}

Form::Form(const std::string& name, int sign_grade, int exec_grade) 
    : name(name), is_signed(false), sign_grade(sign_grade), exec_grade(exec_grade) {
    if (sign_grade < 1 || exec_grade < 1)
        throw GradeTooHighException();
    if (sign_grade > 150 || exec_grade > 150)
        throw GradeTooLowException();
}

Form::Form(const Form& other) 
    : name(other.name), is_signed(other.is_signed), sign_grade(other.sign_grade), exec_grade(other.exec_grade) {}

Form& Form::operator=(const Form& other) {
    if (this != &other) {
        this->is_signed = other.is_signed;
    }
    return *this;
}

Form::~Form() {}

const std::string& Form::getName() const {
    return name;
}

bool Form::getIsSigned() const {
    return is_signed;
}

int Form::getSignGrade() const {
    return sign_grade;
}

int Form::getExecGrade() const {
    return exec_grade;
}

void Form::beSigned(const Bureaucrat &bureaucrat) {
    if (bureaucrat.getGrade() > sign_grade)
        throw GradeTooLowException();
    is_signed = true;
}

const char* Form::GradeTooHighException::what() const throw() {
    return "Form grade too high!";
}

const char* Form::GradeTooLowException::what() const throw() {
    return "Form grade too low!";
}

void Bureaucrat::signForm(Form &form) {
    try {
        form.beSigned(*this);
        std::cout << name << " signed " << form << std::endl;
    } catch (const Form::GradeTooLowException& e) {
        std::cout << name << " couldn’t sign " << form << " because " << e.what() << std::endl;
    }
}

std::ostream& operator<<(std::ostream& os, const Form& f) {
    os << "Form " << f.getName() 
       << " (Sign grade: " << f.getSignGrade() 
       << ", Exec grade: " << f.getExecGrade() 
       << ", Signed: " << (f.getIsSigned() ? "Yes" : "No") 
       << ")";
    return os;
}