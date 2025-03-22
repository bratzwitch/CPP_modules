#include "AForm.hpp"
#include "Bureaucrat.hpp"


AForm::AForm() : name("default"), is_signed(false), sign_grade(150), exec_grade(150) {}

AForm::AForm(const std::string& name, int sign_grade, int exec_grade) 
    : name(name), is_signed(false), sign_grade(sign_grade), exec_grade(exec_grade) {
    if (sign_grade < 1 || exec_grade < 1)
        throw GradeTooHighException();
    if (sign_grade > 150 || exec_grade > 150)
        throw GradeTooLowException();
}

AForm::AForm(const AForm& other) 
    : name(other.name), is_signed(other.is_signed), sign_grade(other.sign_grade), exec_grade(other.exec_grade) {}

AForm& AForm::operator=(const AForm& other) {
    if (this != &other) {
        this->is_signed = other.is_signed;
    }
    return *this;
}

AForm::~AForm() {}

const std::string& AForm::getName() const {
    return name;
}

bool AForm::getIsSigned() const {
    return is_signed;
}

int AForm::getSignGrade() const {
    return sign_grade;
}

int AForm::getExecGrade() const {
    return exec_grade;
}

void AForm::beSigned(const Bureaucrat &bureaucrat) {
    if (bureaucrat.getGrade() > sign_grade)
        throw GradeTooLowException();
    is_signed = true;
}

const char* AForm::GradeTooHighException::what() const throw() {
    return "AForm grade too high!";
}

const char* AForm::GradeTooLowException::what() const throw() {
    return "AForm grade too low!";
}

void Bureaucrat::signForm(AForm &AForm) {
    try {
        AForm.beSigned(*this);
        std::cout << name << " signed " << AForm << std::endl;
    } catch (const AForm::GradeTooLowException& e) {
        std::cout << name << " couldnt sign " << AForm << " because " << e.what() << std::endl;
    }
}

std::ostream& operator<<(std::ostream& os, const AForm& f) {
    os << "AForm " << f.getName() 
       << " (Sign grade: " << f.getSignGrade() 
       << ", Exec grade: " << f.getExecGrade() 
       << ", Signed: " << (f.getIsSigned() ? "Yes" : "No") 
       << ")";
    return os;
}