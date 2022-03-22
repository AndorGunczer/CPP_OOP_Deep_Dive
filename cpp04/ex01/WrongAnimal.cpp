# include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("WrongAnimal") {
    std::cout << "Constructor called for " << type << std::endl;
}

WrongAnimal::~WrongAnimal() {
    std::cout << "Destructor called for " << type << std::endl;
}

WrongAnimal::WrongAnimal( const WrongAnimal& obj ) {
    std::cout << "Copy constructor called for" << type << std::endl;
    *this = obj;
}

WrongAnimal& WrongAnimal::operator=( const WrongAnimal& obj ) {
    std::cout << "Assignation operator called for" << type << std::endl;
	this->type = obj.type;
	return (*this);
}

void WrongAnimal::makeSound() const
{
	std::cout << "WrongAnimal is doing the sound" << std::endl;
}

std::string WrongAnimal::getType() const
{
	return (type);
}
