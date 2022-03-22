# include "Brain.hpp"

Brain::Brain() {
    std::cout << "Brain Constructor called" << std::endl;
}

Brain::~Brain() {
    std::cout << "Brain Destructor called" << std::endl;
}

Brain::Brain( const Brain& obj ) {
    for (size_t i = 0; i < 100; i++)
        this->ideas[i] = obj.ideas[i];
    std::cout << "Brain Copy constructor called" << std::endl;
}

Brain& Brain::operator=( const Brain& obj ) {
    for (size_t i = 0; i < 100; i++)
        this->ideas[i] = obj.ideas[i];
    std::cout << "Brain Assignment op called" << std::endl;
	return (*this);
}