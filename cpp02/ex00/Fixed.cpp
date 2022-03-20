# include "Fixed.hpp"

Fixed::Fixed( void ) : _fixedPointNumber(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed ( Fixed const& obj ) : _fixedPointNumber(obj._fixedPointNumber) {
    std::cout << "Copy constructor called" << std::endl;
}

Fixed &Fixed::operator=( Fixed const& obj ) {
    std::cout << "Assignment operator called" << std::endl;
    this->_fixedPointNumber = obj._fixedPointNumber;
    return *this;
}

Fixed::~Fixed ( void ) {
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits( void ) const { return this->_fixedPointNumber; }

void Fixed::setRawBits( int const raw ) {
    this->_fixedPointNumber = raw;
}

// Fixed::_fractionalBits = 8;