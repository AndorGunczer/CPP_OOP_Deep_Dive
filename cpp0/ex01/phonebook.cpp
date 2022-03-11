#include "phonebook.hpp"
#include <sstream>
#include <iostream>
#include <iomanip>

Phonebook::Phonebook( void ){
	next_contact = 0;
	return ;
}

Phonebook::~Phonebook( void ){
	return ;
}

void Phonebook::add_contact( void ){
	std::string prompt[5] = {"First Name: ", "Last Name: ", "Nickname: ", "Phone Number: ", "Darkest Secret: "};
	std::string input[5];
	std::cin.ignore();
	for	(int i = 0; i < 5; i++)
	{
		std::cout << prompt[i];
		getline(std::cin, input[i]);
	}

	Contact new_contact(input[0], input[1], input[2], input[3], input[4]);
	if (next_contact == 8)
	{
		this->contacts[0] = new_contact;
		next_contact = 1;
	}
	else
	{
		this->contacts[next_contact] = new_contact;
		next_contact++;
	}
	return ;
}

void Phonebook::display( void ){
	for (int i = 0; i < 8; i++)
	{
		std::string formatted_string[3] = {this->contacts[i].first_name, this->contacts[i].last_name, this->contacts[i].nickname};

		for (int j = 0; j < 3; j++)
		{
			if (formatted_string[j].length() > 10)
			{
				formatted_string[j] = formatted_string[j].substr(0, 10);
				formatted_string[j][9] = '.';
			}
		}
		std::cout << std::setw(10) << std::left << i + 1 << "|";
		std::cout << std::setw(10) << std::left << formatted_string[0] << "|";
		std::cout << std::setw(10) << std::left << formatted_string[1] << "|";
		std::cout << std::setw(10) << std::left << formatted_string[2] << std::endl;
	}

	std::string buffer;
	int			index;

	std::cout << "Type the required index: ";
	std::cin >> buffer;
	if (this->check_index(buffer) == false)
	{
		std::cout << "Invalid Index" << std::endl;
		return ;
	}
	index = stoi(buffer);
	if (index > 8 || index < 1)
	{
		std::cout << "Index outside range!" << std::endl;
		return ;
	}
	index--;
	std::cout << this->contacts[index].first_name << std::endl << this->contacts[index].last_name << 
	std::endl << this->contacts[index].nickname << std::endl << this->contacts[index].phone_number << std::endl <<
	this->contacts[index].darkest_secret << std::endl;
	return ;
}

int	Phonebook::check_index(std::string index){
	for (int i = 0; i < index.length(); i++)
	{
		if (std::isdigit(index[i]) == 0)
			return false;
	}
	return true;
}