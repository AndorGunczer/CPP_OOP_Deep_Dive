# include "HumanB.hpp"

HumanB::HumanB( const std::string &name ) {
    this->_name = name;
    this->_weapon = NULL;
}

HumanB::~HumanB( void ) {
    return ;
}

const std::string& HumanB::getWeapon( void ) const {
    return this->_weapon->getType();
}

void HumanB::setWeapon( Weapon &weapon ) {
    // this->_weapon.setType(weapon.getType());
    this->_weapon = &weapon;
}

void HumanB::attack() {
    std::cout << this->_name << " Attacking with: " << this->_weapon->getType() << std::endl;
}