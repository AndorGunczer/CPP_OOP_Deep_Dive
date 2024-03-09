#include "contact.hpp"

Contact::Contact(std::string first_name, std::string last_name, std::string nickname, 
		std::string phone_number, std::string darkest_secret) {
	this->first_name = first_name;
	this->last_name = last_name;
	this->nickname = nickname;
	this->phone_number = phone_number;
	this->darkest_secret = darkest_secret;
	return ;
}

Contact::Contact( void ){
	return ;
}

Contact::~Contact( void ){
	return ;
}

void Contact::setFirstName( const std::string& firstName ) { this->first_name = firstName; }
void Contact::setLastName( const std::string& lastName ) { this->last_name = lastName; }
void Contact::setNickName( const std::string& nickName ) { this->nickname = nickName; }
void Contact::setPhoneNumber( const std::string& phoneNumber ) { this->phone_number = phoneNumber; }
void Contact::setDarkestSecret( const std::string& darkestSecret ) { this->darkest_secret = darkestSecret; } 

const std::string& Contact::getFirstName( void ) const { return this->first_name; }
const std::string& Contact::getLastName( void ) const { return this->last_name; }
const std::string& Contact::getNickName( void ) const { return this->nickname; }
const std::string& Contact::getPhoneNumber( void ) const { return this->phone_number; }
const std::string& Contact::getDarkestSecret( void ) const { return this->darkest_secret; }