# include "WrongCat.hpp"

WrongCat::WrongCat() {
    type = "WrongCat";
    std::cout << "Constructor called for " << type << std::endl;
}

WrongCat::~WrongCat() {
    std::cout << "Destructor called for " << this->type << std::endl;
}

WrongCat::WrongCat( const WrongCat& obj ) {
    std::cout << "Copy constructor called" << this->type << std::endl;
    *this = obj;
}

WrongCat& WrongCat::operator=( const WrongCat& obj ) {
    std::cout << "Assignation operator called" << this->type << std::endl;
    this->type = obj.type;
	return (*this);
}

void WrongCat::makeSound() const
{
	std::cout << "WrongCat is doing the sound" << std::endl;
}