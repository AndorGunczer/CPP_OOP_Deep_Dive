#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

int main(void)
{
	// PresidentialPardonForm form = PresidentialPardonForm("GNL.txt");
	// RobotomyRequestForm formR = RobotomyRequestForm("lalei");
	// ShrubberyCreationForm formS = ShrubberyCreationForm("lalei");
	// Bureaucrat andor = Bureaucrat("Andor", 1);

	// std::cout << form.getName() << " " << form.getGradeSign() << " " << form.getGradeExecute() << " " << form.getTarget() << std::endl;
	// try { 
	// 	andor.executeForm(form);
	// }
	// catch (std::exception& e) {
	// 	std::cout << e.what() << std::endl;
	// }

	// try { 
	// 	andor.executeForm(formR);
	// }
	// catch (std::exception& e) {
	// 	std::cout << e.what() << std::endl;
	// }

	// try { 
	// 	andor.executeForm(formS);
	// }
	// catch (std::exception& e) {
	// 	std::cout << e.what() << std::endl;
	// }

	Intern newIntern = Intern();
	Form *andor = newIntern.makeForm("PresidentialPardonForm", "Andor");
	if (andor == NULL) {
		std::cout << "NULL" << std::endl;
		return (1);
	} else {
		std::cout << andor->getGradeExecute() << std::endl;
	}
	return (0);
}