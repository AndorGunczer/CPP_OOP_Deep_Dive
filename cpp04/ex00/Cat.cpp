# include "Cat.hpp"

Cat::Cat() {
    type = "Cat";
    std::cout << "Constructor called for " << type << std::endl;
}

Cat::~Cat() {
    std::cout << "Destructor called for " << this->type << std::endl;
}

Cat::Cat( const Cat& obj ) {
    std::cout << "Copy constructor called" << this->type << std::endl;
    *this = obj;
}

Cat& Cat::operator=( const Cat& obj ) {
    std::cout << "Assignation operator called" << this->type << std::endl;
    this->type = obj.type;
	return (*this);
}

void Cat::makeSound() const
{
	std::cout << "Cat is doing the sound" << std::endl;
}
