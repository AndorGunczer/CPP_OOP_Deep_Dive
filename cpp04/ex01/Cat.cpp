# include "Cat.hpp"

Cat::Cat() {
    this->type = "Cat";
    this->_brain = new Brain();
    std::cout << "Constructor called for " << type << std::endl;
}

Cat::~Cat() {
    delete this->_brain;
    std::cout << "Destructor called for " << this->type << std::endl;
}

Cat::Cat( const Cat& obj ) {
    this->type = obj.type;
    this->_brain = new Brain(*obj._brain);
    std::cout << "Copy constructor called " << this->type << std::endl;
}

Cat& Cat::operator=( const Cat& obj ) {
    this->type = obj.type;
    delete this->_brain;
    this->_brain = new Brain();
    *this->_brain = *(obj._brain);
    std::cout << "Assignment operator called " << this->type << std::endl;
	return (*this);
}

void Cat::makeSound() const
{
	std::cout << "Cat is doing the sound" << std::endl;
}

void    Cat::addIdea( std::string idea ) {
    int i;

    for (i = 0; i < 100; i++)
    {
        if (_brain->ideas[i].empty())
            break;
    }
    _brain->ideas[i] = idea;
}

void    Cat::displayIdea() {
    for (size_t i = 0; i < 100; i++)
    {
        if (_brain->ideas[i].empty())
            break;
        std::cout << _brain->ideas[i] << ", ";
    }
    std::cout << std::endl;
}

