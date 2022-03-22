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
                std::cout << "Grade is too high!" << std::endl;
                exit(1);
            }
        };

        class GradeTooLowException: public std::exception {
            virtual const char * what() const throw() {
                std::cout << "Grade is too low!" << std::endl;
                exit(1);
            }
        };

    public:
    	Form(void);
		Form(std::string name, const int signGrade, const int execGrade);
		~Form(void);
		Form(const Form &copy);
        Form	&operator= (const Form &copy);
        std::string getName() const;
		int getGradeSign() const;
		int getGradeExecute() const;
		bool getSigned() const;
		void beSigned(Bureaucrat bureaucrat);
};

std::ostream& operator<< (std::ostream& os, const Form& form);
// std::ostream& operator<< (std::ostream& os, const Bureaucrat& obj);

# endif