# ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string>
# include <iostream>
# include "Form.hpp"

class Form;

class Bureaucrat {
    public:
        const std::string   name;
        int                 grade;

        Bureaucrat();
        Bureaucrat( std::string name, int grade );
        ~Bureaucrat();
        Bureaucrat( const Bureaucrat& obj );
        Bureaucrat& operator=( const Bureaucrat& obj );

        class GradeTooHighException: public std::exception {
            public:
                virtual const char * what() const throw() {
                    return ("Bureaucrat grade is too high");
                }
        };

        class GradeTooLowException: public std::exception {
            public:
                virtual const char * what() const throw() {
                    return ("Bureaucrat grade is too low");
                }
        };

        const std::string& getName() const;
        const int& getGrade() const;
        void signForm(Form form);
		void executeForm(Form const & form);
};

std::ostream& operator<< (std::ostream& os, const Bureaucrat& obj);

# endif