# ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include <string>
# include <iostream>
# include "ClapTrap.hpp"

class FragTrap : public ClapTrap {
    public:
        FragTrap( std::string name );
        ~FragTrap( void );
        FragTrap( const FragTrap & obj );
        FragTrap& operator=( const FragTrap & obj );


};

# endif