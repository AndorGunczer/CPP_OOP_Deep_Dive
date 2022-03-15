# ifndef HUMANB_HPP
# define HUMANB_HPP

#include "Weapon.hpp"

class HumanB {
    public:
        HumanB( const std::string &name );
        ~HumanB( void );
        const std::string& getWeapon( void ) const;
        void setWeapon( Weapon &weapon );
        void attack();

    private:
        Weapon *_weapon;
        std::string _name;
};

# endif