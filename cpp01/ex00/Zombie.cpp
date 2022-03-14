#include "Zombie.hpp"

Zombie::Zombie( std::string name ) {
	this->name = name;
	std::cout << this->name << " Constructor called" << std::endl;
}

Zombie::~Zombie( void ) {
	std::cout << this->name << " Destructor called" << std::endl;
}

void Zombie::announce( void ) {
	std::cout << this->name << ":  BraiiiiiiinnnzzzZ..." << std::endl;
}
