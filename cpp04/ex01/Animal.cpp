# include "Animal.hpp"

Animal::Animal() : type("Animal") {
    std::cout << "Constructor called for " << type << std::endl;
}

Animal::~Animal() {
    std::cout << "Destructor called for " << type << std::endl;
}

Animal::Animal( const Animal& obj ) {
    std::cout << "Copy constructor called for" << type << std::endl;
    *this = obj;
}

Animal& Animal::operator=( const Animal& obj ) {
    std::cout << "Assignation operator called for" << type << std::endl;
	this->type = obj.type;
	return (*this);
}

void Animal::makeSound() const
{
	std::cout << "Animal is doing the sound" << std::endl;
}

std::string Animal::getType() const
{
	return (type);
}
