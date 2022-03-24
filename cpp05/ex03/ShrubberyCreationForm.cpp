/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunczer <agunczer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 11:25:33 by agunczer          #+#    #+#             */
/*   Updated: 2022/03/24 17:18:15 by agunczer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm( std::string target ) : Form("ShrubberyCreationForm", 145, 137) {
	this->setTarget(target);
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
	
}

ShrubberyCreationForm::ShrubberyCreationForm( const ShrubberyCreationForm& obj) : Form(obj.getName(), obj.getGradeSign(), obj.getGradeExecute()) {
	
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& obj) {
	setTarget( obj.getTarget() );
	return (*this);
}

std::string ShrubberyCreationForm::getTarget() const { return this->_target; }

void ShrubberyCreationForm::setTarget( std::string target ) { this->_target = target; }

void ShrubberyCreationForm::action() const {
	// std::cout << "action called at " << target << std::endl;
	std::ofstream myFile;
	myFile.open (this->_target, std::fstream::out);
	if (myFile.is_open() == false)
		return ;
	else {
		myFile << "      #      #" << std::endl;
		myFile << "     ##     ##" << std::endl;
		myFile << "    ###    ###" << std::endl;
		myFile << "   ####   ####" << std::endl;
		myFile << "  #####  #####" << std::endl;
		myFile << " ###### ######" << std::endl;
		myFile << "##############" << std::endl;
		myFile << "  ##      ##" << std::endl;
		myFile << "  ##      ##" << std::endl;
		myFile.close();	
	}
}