# ifndef HARL_HPP
# define HARL_HPP

# include <string>
# include <iostream>

class Harl {
    public:
        // void (*const ptr[4])( void );

        Harl( void );
        ~Harl( void );
        void complain( std::string level );

    private:
        void _debug( void );
        void _info ( void );
        void _warning( void );
        void _error( void );
};

# endif