/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunczer <agunczer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 17:43:18 by agunczer          #+#    #+#             */
/*   Updated: 2022/03/24 19:28:47 by agunczer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern() {
	this->forms[0].name = "PresidentialPardonForm";
	this->forms[0].execGrade = 5;
	this->forms[0].signGrade = 25;
	
	this->forms[1].name = "RobotomyRequestForm";
	this->forms[1].execGrade = 45;
	this->forms[1].signGrade = 72;

	this->forms[2].name = "ShrubberyCreationForm";
	this->forms[2].execGrade = 137;
	this->forms[2].signGrade = 125;
}

Intern::~Intern() {
	
}

Intern::Intern( const Intern& obj ) {
	this->forms[0].name = obj.forms[0].name;
	this->forms[0].execGrade = obj.forms[0].execGrade;
	this->forms[0].signGrade = obj.forms[0].signGrade;
	
	this->forms[1].name = obj.forms[1].name;
	this->forms[1].execGrade = obj.forms[1].execGrade;
	this->forms[1].signGrade = obj.forms[1].signGrade;

	this->forms[2].name = obj.forms[2].name;
	this->forms[2].execGrade = obj.forms[2].execGrade;
	this->forms[2].signGrade = obj.forms[2].signGrade;
}

Intern& Intern::operator=( const Intern& obj ) {
	this->forms[0].name = obj.forms[0].name;
	this->forms[0].execGrade = obj.forms[0].execGrade;
	this->forms[0].signGrade = obj.forms[0].signGrade;
	
	this->forms[1].name = obj.forms[1].name;
	this->forms[1].execGrade = obj.forms[1].execGrade;
	this->forms[1].signGrade = obj.forms[1].signGrade;

	this->forms[2].name = obj.forms[2].name;
	this->forms[2].execGrade = obj.forms[2].execGrade;
	this->forms[2].signGrade = obj.forms[2].signGrade;

	return *this;
}

Form* Intern::makeForm( std::string name, std::string target ) {
	int i;
	Form *form;

	for (i = 0; i < 3; i++) {
		std::cout << this->forms[i].name << std::endl;
		if (this->forms[i].name.compare(name) == 0)
			break;
	}
	std::cout << i << std::endl;
	switch (i) {
		case 0: form = new PresidentialPardonForm(target); break;
		case 1: form = new RobotomyRequestForm(target); break;
		case 2: form = new ShrubberyCreationForm(target); break;
		default: form = NULL;
	}

	return form;
}
