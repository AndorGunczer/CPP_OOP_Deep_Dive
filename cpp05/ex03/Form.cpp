#include "Form.hpp"

// Form::Form(void) : _name("unnamed"), _signed(false), _signGrade(150), _execGrade(150)
// {
// 	std::cout << "Unnamed form has been created" << std::endl;
// }

Form::Form(std::string name, const int signGrade, const int execGrade) : _name(name), _target(""), _signGrade(signGrade), _execGrade(execGrade)
{
	_signed = false;
	if (_signGrade > 150 || _execGrade > 150)
		throw GradeTooLowException();
	else if (_signGrade < 1 || _execGrade < 1)
		throw GradeTooHighException();
	std::cout << "Form " << _name << " has been created" << std::endl;
}

Form::~Form(void)
{
}

Form::Form(const Form &copy) : _name(copy._name), _signGrade(copy._signGrade), _execGrade(copy._execGrade)
{
	// *this = copy;
    return ;
}

Form	&Form::operator= (const Form &copy)
{
	_signed = copy._signed;
	return (*this);
}

std::string Form::getName() const { return _name ; }
int Form::getGradeSign() const { return _signGrade; }
int Form::getGradeExecute() const { return _execGrade; }
bool Form::getSigned() const { return _signed; }

std::ostream &operator<<(std::ostream &os, const Form &form) {
	os << "Form " << form.getName() << " needs the grade " << form.getGradeExecute() << " to execute and the grade " << form.getGradeSign() << " to be signed";
	if (form.getSigned() == true)
		std::cout << ". The form is signed" << std::endl;
	else
		std::cout << ". The form isn't signed" << std::endl;
	return os;
}

void Form::beSigned(Bureaucrat bureaucrat) {
    if ( bureaucrat.grade < this->_signGrade )
	{
        this->_signed = true;
		std::cout << this->_name << " has been signed" << std::endl;
	}
	else
        throw GradeTooLowException();
}

bool Form::execute(Bureaucrat const & executor) const {
	if (this->_execGrade > executor.grade) {
		action();
		return true;
	}
	else {
		throw GradeTooLowException();
		return false;
	}
}

std::string Form::getTarget() const { return this->_target; }

void Form::setTarget( std::string target ) { this->_target = target; }
