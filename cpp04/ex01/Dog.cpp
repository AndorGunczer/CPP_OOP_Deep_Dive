# include "Dog.hpp"

Dog::Dog() {
    std::cout << "Constructor called for " << type << std::endl;
    type = "Dog";
    _brain = new Brain();
}

Dog::~Dog() {
    std::cout << "Destructor called for " << this->type << std::endl;
    delete _brain;
}

Dog::Dog( const Dog& obj ) {
    std::cout << "Copy constructor called" << this->type << std::endl;
    this->type = obj.type;
    this->_brain = new Brain(*obj._brain);
}

Dog& Dog::operator=( const Dog& obj ) {
    this->type = obj.type;
    delete this->_brain;
    this->_brain = new Brain();
    *this->_brain = *(obj._brain);
    std::cout << "Assignation operator called" << this->type << std::endl;
	return (*this);
}

void Dog::makeSound() const
{
	std::cout << "Dog is doing the sound" << std::endl;
}
