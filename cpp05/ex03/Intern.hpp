/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunczer <agunczer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 17:43:15 by agunczer          #+#    #+#             */
/*   Updated: 2022/03/24 19:17:20 by agunczer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef INTERN_HPP
# define INTERN_HPP

# include <string>
# include <iostream>
# include "PresidentialPardonForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "ShrubberyCreationForm.hpp"

struct s_Node {
	std::string name;
	int			execGrade;
	int			signGrade;
};

class Intern {
	public:
		s_Node forms[3];

	Intern();
	~Intern();
	Intern( const Intern& obj );
	Intern& operator=( const Intern& obj );

	Form* makeForm( std::string name, std::string target );
};

# endif