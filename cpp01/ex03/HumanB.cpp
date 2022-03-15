# include "HumanB.hpp"

HumanB::HumanB( const std::string &name ) {
    this->_name = name;
}

HumanB::~HumanB( void ) {
    return ;
}

const std::string& HumanB::getWeapon( void ) {
    return this->_weapon.getType();
}

void HumanB::setWeapon( const std::string &weapon ) {
    this->_weapon.setType(weapon);
}

void HumanB::attack() {
    std::cout << this->_name << " Attacking with: " << this->_weapon.getType() << std::endl;
}