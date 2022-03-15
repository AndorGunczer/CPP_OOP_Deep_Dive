# ifndef HUMANA_HPP
# define HUMANA_HPP

#include "Weapon.hpp"

class HumanA {
    public:
        HumanA( const std::string &name, Weapon &weapon );
        ~HumanA( void );
        const std::string& getWeapon( void ) const;
        void setWeapon( const std::string &weapon );
        void attack();

    private:
        Weapon &_weapon;
        std::string _name;
};

# endif