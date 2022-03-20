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
        ~Fixed ( void );

        int     getRawBits( void ) const;
        void    setRawBits( int const raw );
        float   toFloat( void ) const;
        int     toInt( void ) const;

        Fixed& operator=( Fixed const& obj );

        bool    operator<(Fixed const& input);
        bool    operator<=(Fixed const& input);
        bool    operator>(Fixed const& input);
        bool    operator>=(Fixed const& input);
        bool    operator==(Fixed const& input);
        bool    operator!=(Fixed const& input);

        Fixed   operator+(Fixed const& input);
        Fixed   operator-(Fixed const& input);
        Fixed   operator*(Fixed const& input);
        Fixed   operator/(Fixed const& input);

        Fixed    operator++();
        Fixed    operator--();
        Fixed    operator++( int );
        Fixed    operator--( int );

        static Fixed & min(Fixed& fixedOne, Fixed& fixedTwo);
        static Fixed const& min(Fixed const& fixedOne, Fixed const& fixedTwo);
        static Fixed & max(Fixed& fixedOne, Fixed& fixedTwo);
        static Fixed const& max(Fixed const& fixedOne, Fixed const& fixedTwo);

    private:
        int _fixedPointNumber;
        static const int _fractionalBits = 8;

};

std::ostream& operator<< (std::ostream& os, const Fixed& obj);

# endif