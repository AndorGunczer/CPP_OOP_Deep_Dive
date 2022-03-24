# ifndef FORM_HPP
# define FORM_HPP

# include <string>
# include <iostream>
# include <fstream>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
    private:
        std::string _name;
		std::string _target;
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
		virtual void action() const = 0;
		std::string getTarget() const;
		void setTarget( std::string target );
};

std::ostream& operator<< (std::ostream& os, const Form& form);
// std::ostream& operator<< (std::ostream& os, const Bureaucrat& obj);

# endif