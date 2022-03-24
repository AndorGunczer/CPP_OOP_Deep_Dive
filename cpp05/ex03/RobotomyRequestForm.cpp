/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunczer <agunczer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 11:25:33 by agunczer          #+#    #+#             */
/*   Updated: 2022/03/24 17:16:18 by agunczer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm( std::string target ) : Form("RobotomyRequestForm", 72, 45) {
	this->setTarget(target);
}

RobotomyRequestForm::~RobotomyRequestForm() {
	
}

RobotomyRequestForm::RobotomyRequestForm( const RobotomyRequestForm& obj) : Form(obj.getName(), obj.getGradeSign(), obj.getGradeExecute()) {
	
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& obj) {
	setTarget( obj.getTarget() );
	return (*this);
}

std::string RobotomyRequestForm::getTarget() const { return this->_target; }

void RobotomyRequestForm::setTarget( std::string target ) { this->_target = target; }

void RobotomyRequestForm::action() const {
	if (rand() % 2 == 0)
		std::cout << this->_target << " has been robotomized." << std::endl;
	else
		std::cout << this->_target << "'s robotomy has failed" << std::endl;
}