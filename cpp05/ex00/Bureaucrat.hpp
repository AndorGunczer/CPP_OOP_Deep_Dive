# ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string>
# include <iostream>

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
                    return ("Beaurocrat grade is too high");
                }
        };

        class GradeTooLowException: public std::exception {
            public:
                virtual const char * what() const throw() {
                    return ("Beaurocrat grade is too low");
                }
        };

        const std::string& getName() const;
        const int& getGrade() const;

};

std::ostream& operator<< (std::ostream& os, const Bureaucrat& obj);

# endif