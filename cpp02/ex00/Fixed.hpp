# ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed {
    public:
        Fixed( void );
        Fixed ( Fixed const& obj );
        Fixed& operator=( Fixed const& obj );
        ~Fixed ( void );
        int getRawBits( void ) const;
        void setRawBits( int const raw );

    private:
        int _fixedPointNumber;
        static const int _fractionalBits = 8;

};

# endif