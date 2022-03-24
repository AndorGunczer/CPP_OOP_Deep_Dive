# ifndef FORM_HPP
# define FORM_HPP

# include <string>
# include <iostream>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
    private:
        std::string _name;
        bool _signed;
        const int _signGrade;
        const int _execGrade;

        class GradeTooHighException: public std::exception {
            virtual const char * what() const throw() {
                return ("Grade is too high!");
            }
        };

        class GradeTooLowException: public std::exception {
            virtual const char * what() const throw() {
                return ("Grade is too low!");
            }
        };

	protected:
		// Form(void);

    public:
		Form(std::string name, const int signGrade, const int execGrade);
		~Form(void);
		Form(const Form &copy);
        Form	&operator= (const Form &copy);
        std::string getName() const;
		int getGradeSign() const;
		int getGradeExecute() const;
		bool getSigned() const;
		void beSigned(Bureaucrat bureaucrat);
		bool execute(Bureaucrat const & executor) const;
};

std::ostream& operator<< (std::ostream& os, const Form& form);
// std::ostream& operator<< (std::ostream& os, const Bureaucrat& obj);

# endif