/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunczer <agunczer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 10:13:53 by agunczer          #+#    #+#             */
/*   Updated: 2022/03/24 10:43:10 by agunczer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm( std::string target ) : Form("PresidentialPardonForm", 145, 137) {
	this->_target = target;
}

PresidentialPardonForm::~PresidentialPardonForm() {
	
}

PresidentialPardonForm::PresidentialPardonForm( const PresidentialPardonForm& obj) : Form(obj.getName(), obj.getGradeSign(), obj.getGradeExecute()) {
	
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& obj) {
	setTarget( obj.getTarget() );
	return (*this);
}

std::string PresidentialPardonForm::getTarget() const { return this->_target; }

void PresidentialPardonForm::setTarget( std::string target ) { this->_target = target; }

