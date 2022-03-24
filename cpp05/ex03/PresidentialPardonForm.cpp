/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunczer <agunczer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 10:13:53 by agunczer          #+#    #+#             */
/*   Updated: 2022/03/24 17:20:19 by agunczer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm( std::string target ) : Form("PresidentialPardonForm", 25, 5) {
	this->setTarget(target);
}

PresidentialPardonForm::~PresidentialPardonForm() {
	
}

PresidentialPardonForm::PresidentialPardonForm( const PresidentialPardonForm& obj) : Form(obj.getName(), obj.getGradeSign(), obj.getGradeExecute()) {
	
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& obj) {
	setTarget( obj.getTarget() );
	return (*this);
}

void PresidentialPardonForm::action() const {
	std::cout << getTarget() << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}

