# include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("noname"), grade(150) {}

Bureaucrat::Bureaucrat( std::string name, int grade ) : name(name) {
    try {
        if (grade > 150)
            throw Bureaucrat::GradeTooLowException();
        else if (grade < 1)
            throw Bureaucrat::GradeTooHighException();
    } catch (Bureaucrat::GradeTooHighException& e) {
        std::cout << this->name << "'s grade is too high!" << std::endl;
        return ;
    } catch (Bureaucrat::GradeTooLowException& e) {
        std::cout << this->name << "'s grade is too high!" << std::endl;
        return ;
    };

    this->grade = grade;
    std::cout << "Bureaucrat Default Constructor has been called" << std::endl;
}

Bureaucrat::~Bureaucrat() {

}

Bureaucrat::Bureaucrat( const Bureaucrat& obj ) : name(obj.name), grade(obj.grade) {
    std::cout << "Bureaucrat Copy Constructor has been called" << std::endl;
}

Bureaucrat& Bureaucrat::operator=( const Bureaucrat& obj ) {
    this->grade = obj.grade;
    std::cout << "Overload Assignment Operator has been called" << std::endl;

    return (*this);
}

const std::string& Bureaucrat::getName() const { return this->name; }
const int& Bureaucrat::getGrade() const { return this->grade; };

std::ostream& operator<< (std::ostream& os, const Bureaucrat& obj) {
    os << obj.name << " bureaucrat grade " << obj.grade << std::endl;
    return (os);
}

void Bureaucrat::signForm(Form form) { 
	if (form.getSigned() == true)
		std::cout << getName() << "signed " << form.getGradeSign() <<  std::endl;
	else
		std::cout << getName() << "couldn’t sign " << form.getGradeSign() << "because he is lazy" << std::endl;
	return ;
}

void Bureaucrat::executeForm(Form const & form) {
	if (form.execute(*this))
		std::cout << this->name << " executed " << form.getName() << std::endl;
}