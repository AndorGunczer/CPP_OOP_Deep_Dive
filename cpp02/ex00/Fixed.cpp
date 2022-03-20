# include "Fixed.hpp"

Fixed::Fixed( void ) : _fixedPointNumber(0)
{}

Fixed::Fixed ( Fixed const& obj ) : _fixedPointNumber(obj._fixedPointNumber) {}

Fixed &Fixed::operator=( Fixed const& obj ) {
    this->_fixedPointNumber = obj._fixedPointNumber;
    return *this;
}

Fixed::~Fixed ( void ) {
}

int Fixed::getRawBits( void ) const { return this->_fixedPointNumber; }

void Fixed::setRawBits( int const raw ) {
    this->_fixedPointNumber = raw;
}

// Fixed::_fractionalBits = 8;