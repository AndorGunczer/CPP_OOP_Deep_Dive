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
    return os << obj.toFloat();
    // return os;
};

bool    Fixed::operator<(Fixed const& input) { return this->_fixedPointNumber < input._fixedPointNumber; }
bool    Fixed::operator<=(Fixed const& input) { return this->_fixedPointNumber <= input._fixedPointNumber; }
bool    Fixed::operator>(Fixed const& input) { return this->_fixedPointNumber > input._fixedPointNumber; }
bool    Fixed::operator>=(Fixed const& input) { return this->_fixedPointNumber >= input._fixedPointNumber; }
bool    Fixed::operator==(Fixed const& input) { return this->_fixedPointNumber == input._fixedPointNumber; }
bool    Fixed::operator!=(Fixed const& input) { return this->_fixedPointNumber != input._fixedPointNumber; }

Fixed   Fixed::operator+(Fixed const& input) { return Fixed(this->toFloat() + input.toFloat() ); }
Fixed   Fixed::operator-(Fixed const& input) { return Fixed(this->toFloat() - input.toFloat() ); }
Fixed   Fixed::operator*(Fixed const& input) { return Fixed(this->toFloat() * input.toFloat() ); }
Fixed   Fixed::operator/(Fixed const& input) { return Fixed(this->toFloat() / input.toFloat() ); }

Fixed Fixed::operator++ ()
{
	Fixed rt;
	_fixedPointNumber++;
	rt._fixedPointNumber = _fixedPointNumber;
	return (rt);
}

Fixed Fixed::operator++ (int)
{
	Fixed rt;
	rt._fixedPointNumber = _fixedPointNumber++;
	return (rt);
}

Fixed Fixed::operator-- ()
{
	Fixed rt;
	_fixedPointNumber--;
	rt._fixedPointNumber = _fixedPointNumber;
	return (rt);
}

Fixed Fixed::operator-- (int)
{
	Fixed rt;
	rt._fixedPointNumber = _fixedPointNumber--;
	return (rt);
}

Fixed & Fixed::min(Fixed& fixedOne, Fixed& fixedTwo) {
    if (fixedOne._fixedPointNumber < fixedTwo._fixedPointNumber)
        return fixedOne;
    return fixedTwo;
}

Fixed const& Fixed::min(Fixed const& fixedOne, Fixed const& fixedTwo) {
    if (fixedOne._fixedPointNumber < fixedTwo._fixedPointNumber)
        return fixedOne;
    return  fixedTwo;
}

Fixed & Fixed::max(Fixed& fixedOne, Fixed& fixedTwo) {
    if (fixedOne._fixedPointNumber > fixedTwo._fixedPointNumber)
        return fixedOne;
    return fixedTwo;
}

Fixed const& Fixed::max(Fixed const& fixedOne, Fixed const& fixedTwo) {
    if (fixedOne._fixedPointNumber > fixedTwo._fixedPointNumber)
        return fixedOne;
    return fixedTwo;
}
