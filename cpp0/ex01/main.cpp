#include <string>
#include <iostream>
#include "phonebook.hpp"

int	main( void ){
	std::string	input;
	Phonebook phonebook;
	
	while (1)
	{
		std::cin >> input;
		if (input.compare("EXIT") == 0)
			return (0);
		if (input.compare("ADD") == 0)
			phonebook.add_contact();
		if (input.compare("SEARCH") == 0)
			phonebook.display();
	}
}