# include "Fixed.hpp"

Fixed::Fixed( void ) : _fixedPointNumber(0)
{}

Fixed::Fixed( int const& number ) {
    this->_fixedPointNumber = number << _fractionalBits;
}

Fixed::Fixed( float const& number ) {
    this->_fixedPointNumber = (int)roundf(number * (1 << _fractionalBits));
}

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

float   Fixed::toFloat( void ) const {
    return (float) _fixedPointNumber / (float)(1 << _fractionalBits);
}

int     Fixed::toInt( void ) const {
    return _fixedPointNumber >> _fractionalBits;
}

std::ostream& operator<< (std::ostream& os, const Fixed& obj){
    return os << obj.toInt();
    // return os;
};