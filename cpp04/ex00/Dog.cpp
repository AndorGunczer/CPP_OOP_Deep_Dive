# include "Dog.hpp"

Dog::Dog() {
    type = "Dog";
    std::cout << "Constructor called for " << type << std::endl;
}

Dog::~Dog() {
    std::cout << "Destructor called for " << this->type << std::endl;
}

Dog::Dog( const Dog& obj ) {
    std::cout << "Copy constructor called" << this->type << std::endl;
    *this = obj;
}

Dog& Dog::operator=( const Dog& obj ) {
    std::cout << "Assignation operator called" << this->type << std::endl;
    this->type = obj.type;
	return (*this);
}

void Dog::makeSound() const
{
	std::cout << "Dog is doing the sound" << std::endl;
}
