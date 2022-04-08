#ifndef PHONEBOOK_H
# define PHONEBOOK_H

#include "contact.hpp"

class Phonebook {
	public:
		Phonebook( void );
		~Phonebook( void );
		void add_contact( void );
		void display( void );
		int	check_index( std::string index );

		// void setContact( const Contact& obj, int index );
		// void setNextContact( int nextContact );

		// Contact& getContact( int index ) const;
		// int& getNextContact( void ) const;

	private:
		Contact		contacts[8];
		int			next_contact;
};

#endif