# ifndef FIXED_HPP
# define FIXED_HPP


#include <iostream>
#include <cmath>

class Fixed {
    public:
        Fixed( void );
        Fixed( int const& number );
        Fixed( float const& number );
        Fixed ( Fixed const& obj );
        Fixed& operator=( Fixed const& obj );
        ~Fixed ( void );
        int     getRawBits( void ) const;
        void    setRawBits( int const raw );
        float   toFloat( void ) const;
        int     toInt( void ) const;

    private:
        int _fixedPointNumber;
        static const int _fractionalBits = 8;

};

std::ostream& operator<< (std::ostream& os, const Fixed& obj);

# endif