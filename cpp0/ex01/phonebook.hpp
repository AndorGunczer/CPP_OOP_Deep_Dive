#ifndef PHONEBOOK_H
# define PHONEBOOK_H

#include "contact.hpp"

class Phonebook {
	public :
		Contact contacts[8];
		int			next_contact;

		Phonebook( void );
		~Phonebook( void );
		void add_contact( void );
		void display( void );
		int	check_index( std::string index );
};

#endif