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