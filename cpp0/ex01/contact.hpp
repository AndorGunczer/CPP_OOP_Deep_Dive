#ifndef CONTACT_H
# define CONTACT_H

#include <string>
#include <iostream>

class Contact {
	public:
		Contact(std::string first_name, std::string last_name, std::string nickname, 
			std::string phone_number, std::string darkest_secret);
		Contact( void );
		~Contact( void );

		void setFirstName( const std::string& firstName );
		void setLastName( const std::string& lastName );
		void setNickName( const std::string& nickName );
		void setPhoneNumber( const std::string& phoneNumber );
		void setDarkestSecret( const std::string& darkestSecret );

		const std::string& getFirstName( void ) const;
		const std::string& getLastName( void ) const;
		const std::string& getNickName( void ) const;
		const std::string& getPhoneNumber( void ) const;
		const std::string& getDarkestSecret( void ) const;
	
	private:
		std::string first_name;
		std::string last_name;
		std::string nickname;
		std::string phone_number;
		std::string darkest_secret;
};

#endif