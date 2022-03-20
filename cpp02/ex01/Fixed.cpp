# include "Fixed.hpp"

Fixed::Fixed( void ) : _fixedPointNumber(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed( int const& number ) {
    std::cout << "Int constructor called" << std::endl;
    this->_fixedPointNumber = number << _fractionalBits;
}

Fixed::Fixed( float const& number ) {
    std::cout << "Float constructor called" << std::endl;
    this->_fixedPointNumber = (int)roundf(number * (1 << _fractionalBits));
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

int Fixed::getRawBits( void ) const {
    std::cout << "getRawBits member function called" << std::endl;
    return this->_fixedPointNumber;
}

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