#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

int main(void)
{
	PresidentialPardonForm form = PresidentialPardonForm("GNL.txt");
	RobotomyRequestForm formR =RobotomyRequestForm("lalei");
	Bureaucrat andor = Bureaucrat("Andor", 1);

	std::cout << form.getName() << " " << form.getGradeSign() << " " << form.getGradeExecute() << " " << form.getTarget() << std::endl;
	try { 
		andor.executeForm(formR);
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	return (0);
}