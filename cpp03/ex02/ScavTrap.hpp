# ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include <string>
# include <iostream>
# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {
    public:
        ScavTrap( std::string name );
        ~ScavTrap( void );
        ScavTrap( const ScavTrap & obj );
        ScavTrap& operator=( const ScavTrap & obj );

        void guardGate( void );
};

# endif