#include "Zombie.hpp"

Zombie::Zombie( std::string name ) {
	this->_name = name;
	std::cout << this->_name << " Constructor called" << std::endl;
}

Zombie::Zombie( void ) {
	// this->name = name;
	// std::cout << this->name << " Constructor called" << std::endl;
}

Zombie::~Zombie( void ) {
	std::cout << this->_name << " Destructor called" << std::endl;
}

void Zombie::announce( void ) {
	std::cout << this->_name << ":  BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setName( std::string name ) {
	this->_name = name;
}